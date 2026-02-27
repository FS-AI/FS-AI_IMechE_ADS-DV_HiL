#pragma once
#include "mock_io/command_line_tasks.h"
#include "mock_io/state_machine.h"
#include "utils/flags.h"

typedef struct
{
    float brake_hyd_press_f_buffer[FILTER_SIZE];
    float brake_hyd_press_r_buffer[FILTER_SIZE];
    float drive_f_trq_buffer[FILTER_SIZE];
    float drive_r_trq_buffer[FILTER_SIZE];
    int buffer_index;
    float speed;
    int sub_count;
} first_order_filter_vehicle_state_t;

static inline float apply_fir_filter(int buffer_index, float *buffer, float new_value)
{
    buffer[buffer_index] = new_value;

    float sum = 0;
    for (int i = 0; i < FILTER_SIZE; i++)
    {
        sum += buffer[i];
    }
    return sum / FILTER_SIZE;
}

static inline void first_order_filter_vehicle_model(state_machine_retval_t *sm_state, ai2vcu_data_t *ai2vcu, vcu2ai_data_t *vcu2ai)
{
    static first_order_filter_vehicle_state_t state = {0};
    if (sm_state->hidden_state.op_mode == AMI_OP_MODE_OFF)
    {
        memset(&state, 0, sizeof(state));
    };
    // Status & Request
    vcu2ai->vcu_brake.hyd_press_f_req_pct = ai2vcu->ai_brake.hyd_press_f_req_pct;
    vcu2ai->vcu_brake.hyd_press_r_req_pct = ai2vcu->ai_brake.hyd_press_r_req_pct;
    vcu2ai->vcu_brake.status_brk = 1;
    vcu2ai->vcu_brake.status_ebs = (sm_state->hidden_state.op_mode == AMI_OP_MODE_EMERGENCY) ? 2 : 1;
    vcu2ai->vcu_drive_f.front_axle_trq_max = (sm_state->hidden_state.speed_capped) ? TORQUE_MAX_LIMIT_LOW : TORQUE_MAX_LIMIT;
    vcu2ai->vcu_drive_r.rear_axle_trq_max = (sm_state->hidden_state.speed_capped) ? TORQUE_MAX_LIMIT_LOW : TORQUE_MAX_LIMIT;
    vcu2ai->vcu_drive_f.front_axle_trq_request = ai2vcu->ai_drive_f.front_axle_trq_request;
    vcu2ai->vcu_drive_r.rear_axle_trq_request = ai2vcu->ai_drive_r.rear_axle_trq_request;

    // Actual
    vcu2ai->vcu_brake.hyd_press_f_pct = apply_fir_filter(
        state.buffer_index,
        state.brake_hyd_press_f_buffer,
        ai2vcu->ai_brake.hyd_press_f_req_pct);
    vcu2ai->vcu_brake.hyd_press_r_pct = apply_fir_filter(
        state.buffer_index,
        state.brake_hyd_press_r_buffer,
        ai2vcu->ai_brake.hyd_press_r_req_pct);

    vcu2ai->vcu_drive_f.front_axle_trq = apply_fir_filter(
        state.buffer_index,
        state.drive_f_trq_buffer,
        (ai2vcu->ai_drive_f.front_axle_trq_request > vcu2ai->vcu_drive_f.front_axle_trq_max) ? vcu2ai->vcu_drive_f.front_axle_trq_max : ai2vcu->ai_drive_f.front_axle_trq_request);
    vcu2ai->vcu_drive_r.rear_axle_trq = apply_fir_filter(
        state.buffer_index,
        state.drive_r_trq_buffer,
        (ai2vcu->ai_drive_r.rear_axle_trq_request > vcu2ai->vcu_drive_r.rear_axle_trq_max) ? vcu2ai->vcu_drive_r.rear_axle_trq_max : ai2vcu->ai_drive_r.rear_axle_trq_request);
    vcu2ai->vcu_steer.angle = ai2vcu->ai_steer.steer_request;
    vcu2ai->vcu_steer.angle_request = ai2vcu->ai_steer.steer_request;
    
    state.speed = state.speed + ((float)(ai2vcu->ai_drive_f.front_axle_trq_request + ai2vcu->ai_drive_r.rear_axle_trq_request) * 0.001);
    state.speed = state.speed - ((float)(ai2vcu->ai_brake.hyd_press_f_req_pct + ai2vcu->ai_brake.hyd_press_r_req_pct) * 0.001);
    state.speed = state.speed < 0 ? 0 : state.speed;
    state.speed = state.speed > ai2vcu->ai_drive_f.front_motor_speed_max ? ai2vcu->ai_drive_f.front_motor_speed_max : state.speed;
    state.speed = state.speed > ai2vcu->ai_drive_r.rear_motor_speed_max ? ai2vcu->ai_drive_r.rear_motor_speed_max : state.speed;
    state.speed = state.speed > SPEED_LIMIT ? SPEED_LIMIT : state.speed;

    vcu2ai->vcu_speeds.fl_wheel_speed = state.speed;
    vcu2ai->vcu_speeds.fr_wheel_speed = state.speed;
    vcu2ai->vcu_speeds.rl_wheel_speed = state.speed;
    vcu2ai->vcu_speeds.rr_wheel_speed = state.speed;
    state.sub_count += (int)state.speed;
    if (state.sub_count > 20000)
    {
        vcu2ai->vcu_wheel_counts.fl_pulse_count += 1;
        vcu2ai->vcu_wheel_counts.fr_pulse_count += 1;
        vcu2ai->vcu_wheel_counts.rl_pulse_count += 1;
        vcu2ai->vcu_wheel_counts.rr_pulse_count += 1;
        state.sub_count = state.sub_count % 20000;
    }
    state.buffer_index = (state.buffer_index + 1) % FILTER_SIZE;
};