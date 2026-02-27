#pragma once
//#define _POSIX_C_SOURCE 199309L
#include <stdlib.h> // Include for exit
// #include "can_interface.h"
// #include "utils/scheduling.h"
// #include "mock_io/command_line_tasks.h"
#include "../mock_io/state_machine.h"
// #include "utils/flags.h"
#include "../Vehicle_Model/Include/vehicle_model.h"

// Optional components
#if DEBUG_SKIP_CAN_TX_RX
#include "shared_memory_fsai_console.h"
#endif
#if USE_FIR_FILTER_VEHICLE_MODEL
#include "fir_filter_vehicle_model.h"
#endif

typedef struct
{
    long loop_interval_ms;
    pthread_t __private_pipeline_thread_handle;
    char * canInterface;
    int can_debug_flag;
    ai2vcu_data_t * __private_ai2vcu_data;
    vcu2ai_data_t * __private_vcu2ai_data;
    mockio_module_state_t * __private_mock_io_state_for_cleanup;
    #if DEBUG_SKIP_CAN_TX_RX
    shared_memory_init_kwargs_t * __private_shared_mem_state_for_cleanup;
    #endif
    bool print_vehicle_state;
    bool print_ai2vcu;
    bool print_vcu2ai;
} pipeline_kwargs_t;

static inline void *pipeline_thread(void *arg)
{
    pipeline_kwargs_t * kwargs = arg;
    // Initialize the timespec to the current time
    struct timespec start_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    state_machine_hidden_state_t __private_state_machine_hidden_state = {0};
    while (1)
    {
        #if !DEBUG_SKIP_CAN_TX_RX
        read_data(kwargs->__private_ai2vcu_data);
        #endif
        state_machine_kwargs_t state_machine_kwargs = {
            .ai2vcu = kwargs->__private_ai2vcu_data,
            .vcu2ai = kwargs->__private_vcu2ai_data,
            .hidden_state = &__private_state_machine_hidden_state,
            .vehicle_state = kwargs->__private_mock_io_state_for_cleanup->input_kwargs.vehicle_state,
            .vehicle_state_mutex = kwargs->__private_mock_io_state_for_cleanup->input_kwargs.vehicle_state_mutex,
        };
        state_machine_retval_t sm_state = state_machine_iteration(&state_machine_kwargs);

        #if USE_FIR_FILTER_VEHICLE_MODEL
        first_order_filter_vehicle_model(&sm_state, kwargs->__private_ai2vcu_data, kwargs->__private_vcu2ai_data);
        #else
        vehicle_model_update(sm_state.ai2vcu, &sm_state.vehicle_state, sm_state.vcu2ai);
        #endif

        #if !DEBUG_SKIP_CAN_TX_RX
        // Do not send data if the vcu is off
        if (sm_state.hidden_state.op_mode != AMI_OP_MODE_OFF) send_data(*(kwargs->__private_vcu2ai_data));
        #endif

        sleep_until_next_interval(&start_time, kwargs->loop_interval_ms);
    }
    return NULL;
}


static inline int pipeline_init(pipeline_kwargs_t *kwargs)
{
    // Shared Variables (used as i/o between pipeline stages)
    static ai2vcu_data_t ai2vcu_data = {0};
    static vcu2ai_data_t vcu2ai_data = {0};
    kwargs->__private_ai2vcu_data = &ai2vcu_data;
    kwargs->__private_vcu2ai_data = &vcu2ai_data;
    // static struct model_state_t model_state = {0};
    // static struct switch_state_t switch_state = {0};
    vehicle_model_init();

    #if !DEBUG_SKIP_CAN_TX_RX
    // Initialize Can interface
    if (can_interface_init(kwargs->canInterface, kwargs->can_debug_flag) > 0)
    {
        printf("Error in can_interface_init()");
        exit(1);
    }
    #else
    // Use shared memory (debug use only! THis is not intended for release)
    static shared_memory_init_kwargs_t shared_mem_init_kwargs = {
        .kwargs = {
            .ai2vcu = &ai2vcu_data,
            .vcu2ai = &vcu2ai_data,
        },
    };
    create_shared_memory_listener_thread(&shared_mem_init_kwargs);
    kwargs->__private_shared_mem_state_for_cleanup = &shared_mem_init_kwargs;
    #endif
    // Launch the mock io (switches) cli module
    static vehicle_state_t vehicle_state = {0};
    static pthread_mutex_t vehicle_state_mutex = PTHREAD_MUTEX_INITIALIZER;
    static mockio_module_state_t mockio_state = {
        .input_kwargs = {
            .vehicle_state = &vehicle_state,
            .vehicle_state_mutex = &vehicle_state_mutex
        },
        .output_kwargs = {
            .vehicle_state = &vehicle_state,
            .loop_interval_ms = 10,
            .vehicle_state_mutex = &vehicle_state_mutex,
            .ai2vcu = &ai2vcu_data,
            .vcu2ai = &vcu2ai_data,
        }
    };
    mockio_state.output_kwargs.print_ai2vcu = kwargs->print_ai2vcu;
    mockio_state.output_kwargs.print_vcu2ai = kwargs->print_vcu2ai;
    mockio_state.output_kwargs.print_vehicle_state = kwargs->print_vehicle_state;
    create_cli_threads(&mockio_state);
    kwargs->__private_mock_io_state_for_cleanup = &mockio_state;
    // Launch threads
    if (pthread_create(&(kwargs->__private_pipeline_thread_handle), NULL, pipeline_thread, kwargs))
    {
        perror("Failed to create Pipeline::pipeline_thread");
        exit(1);
    }
}

static inline int pipeline_terminate(pipeline_kwargs_t *kwargs)
{
    join_cli_threads(kwargs->__private_mock_io_state_for_cleanup);
    #if DEBUG_SKIP_CAN_TX_RX
    join_shared_memory(kwargs->__private_shared_mem_state_for_cleanup);
    #endif
    pthread_join(kwargs->__private_pipeline_thread_handle, NULL);
    return 0;
}

