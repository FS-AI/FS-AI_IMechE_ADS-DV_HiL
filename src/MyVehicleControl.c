/*
******************************************************************************
**  CarMaker - Version 13.0.1
**  Vehicle Dynamics Simulation Toolkit
**
**  Copyright (C)   IPG Automotive GmbH
**                  Bannwaldallee 60             Phone  +49.721.98520.0
**                  76185 Karlsruhe              Fax    +49.721.98520.99
**                  Germany                      WWW    www.ipg-automotive.com
******************************************************************************
**
** Simple VehicleControl Model to demonstrate the manipulation of Driver Gas
**
** Add the declaration of the register function to one of your header files,
** for example to User.h and call it in User_Register()
**
**    VehicleControl_Register_MyModel ()
**
******************************************************************************
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "CarMaker.h"
#include "Car/Vehicle_Car.h"
#include "Car/Car.h"
#include "MyModels.h"

#include "ZF_src/mock_io/autonomous_mission_indicator.h"
#include "ZF_src/mock_io/autonomous_system_status_indicator.h"
#include "ZF_src/mock_io/emergency_stop_system.h"
#include "ZF_src/mock_io/master_switch.h"
#include "ZF_src/mock_io/state_machine.h"
#include "ZF_src/mock_io/tractive_system_active_light.h"
#include "ZF_src/mock_io/vehicle_state.h"

#include "ZF_src/mock_io/messages.h"

#include "ZF_src/Vehicle_Model/Include/FSAI_VehicleModel.h"
#include "ZF_src/Vehicle_Model/Include/rtwtypes.h"
#include "ZF_src/Vehicle_Model/Include/vehicle_model.h"



typedef struct adsdv_interface_struct {
    uint8_t lv_switch;
    uint8_t as_switch;
    uint8_t ts_switch;
    uint8_t go_signal;
    uint8_t estop_switch;
    uint8_t mission_status;
	uint8_t mission_set;
    uint8_t mission_selected;
    // state_machine_hidden_state_t hidden_state;
    // vehicle_state_t vehicle_state;
} adsdv_interface_t;

struct tMyModel {

    ai2vcu_data_t ai2vcu_data;
    vcu2ai_data_t vcu2ai_data;
    adsdv_interface_t adsdv_if;
    state_machine_hidden_state_t hidden_state;
    vehicle_state_t vehicle_state;
    uint64_t simulation_cycle_count;
    boolean_T temp_bool;
};

// static const char ThisModelClass[] = "VehicleControl";
static const char ThisModelKind[]  = "MyModel";
static const int  ThisVersionId    = 1;

const float PI = 3.1415926535897932384626433832795;

/******************************************************************************/

static int counter = 0;
static uint8_t prev_mission_set = 0;

// Set override_handshake to true to copy previous handshake output to current input when CAN comms is not aviailable.
const bool override_handshake = true;


static void
MyModel_DeclQuants_dyn (struct tMyModel *mp, int park)
{
    static struct tMyModel MyModel_Dummy = {0};
    if (park)
	mp = &MyModel_Dummy;

    /* Define here dict entries for dynamically allocated variables. */

    // AI2VCU signals defined to allow for mapping from CAN signals and easier manipulation in model

    tDDefault *ai2vcu_df = DDefaultCreate("AI2VCU.");

    DDefUChar(ai2vcu_df, "Brake.HYD_PRESS_F_REQ_pct", "", &mp->ai2vcu_data.ai_brake.hyd_press_f_req_pct, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Brake.HYD_PRESS_R_REQ_pct", "", &mp->ai2vcu_data.ai_brake.hyd_press_r_req_pct, DVA_IO_In);

    DDefUShort(ai2vcu_df, "Drive_F.FRONT_AXLE_TRQ_REQUEST", "", &mp->ai2vcu_data.ai_drive_f.front_axle_trq_request, DVA_IO_In);
    DDefUShort(ai2vcu_df, "Drive_F.FRONT_MOTOR_SPEED_MAX", "", &mp->ai2vcu_data.ai_drive_f.front_motor_speed_max, DVA_IO_In);

    DDefUShort(ai2vcu_df, "Drive_R.REAR_AXLE_TRQ_REQUEST", "", &mp->ai2vcu_data.ai_drive_r.rear_axle_trq_request, DVA_IO_In);
    DDefUShort(ai2vcu_df, "Drive_R.REAR_MOTOR_SPEED_MAX", "", &mp->ai2vcu_data.ai_drive_r.rear_motor_speed_max, DVA_IO_In);

    DDefShort(ai2vcu_df, "Steer.STEER_REQUEST", "", &mp->ai2vcu_data.ai_steer.steer_request, DVA_IO_In);

    DDefUChar(ai2vcu_df, "Status.CONES_COUNT_ACTUAL", "", &mp->ai2vcu_data.ai_status.cones_count_actual, DVA_IO_In);
    DDefUShort(ai2vcu_df, "Status.CONES_COUNT_ALL", "", &mp->ai2vcu_data.ai_status.cones_count_all, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.DIRECTION_REQUEST", "", &mp->ai2vcu_data.ai_status.direction_request, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.ESTOP_REQUEST", "", &mp->ai2vcu_data.ai_status.estop_request, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.HANDSHAKE", "", &mp->ai2vcu_data.ai_status.handshake, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.LAP_COUNTER", "", &mp->ai2vcu_data.ai_status.lap_counter, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.MISSION_STATUS", "", &mp->ai2vcu_data.ai_status.mission_status, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.VEH_SPEED_ACTUAL", "", &mp->ai2vcu_data.ai_status.veh_speed_actual, DVA_IO_In);
    DDefUChar(ai2vcu_df, "Status.VEH_SPEED_DEMAND", "", &mp->ai2vcu_data.ai_status.veh_speed_demand, DVA_IO_In);

    DDefaultDelete(ai2vcu_df);

    // VCU2AI signals defined to allow for mapping to CAN signals and easier manipulation in model

    tDDefault *vcu2ai_df = DDefaultCreate("VCU2AI.");

    DDefUChar(vcu2ai_df, "Brake.HYD_PRESS_F_pct", "", &mp->vcu2ai_data.vcu_brake.hyd_press_f_pct, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Brake.HYD_PRESS_F_REQ_pct", "", &mp->vcu2ai_data.vcu_brake.hyd_press_f_req_pct, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Brake.HYD_PRESS_R_pct", "", &mp->vcu2ai_data.vcu_brake.hyd_press_r_pct, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Brake.HYD_PRESS_R_REQ_pct", "", &mp->vcu2ai_data.vcu_brake.hyd_press_r_req_pct, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Brake.STATUS_BRK", "", &mp->vcu2ai_data.vcu_brake.status_brk, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Brake.STATUS_EBS", "", &mp->vcu2ai_data.vcu_brake.status_ebs, DVA_IO_In);

    DDefShort(vcu2ai_df, "Drive_F.FRONT_AXLE_TRQ", "", &mp->vcu2ai_data.vcu_drive_f.front_axle_trq, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Drive_F.FRONT_AXLE_TRQ_MAX", "", &mp->vcu2ai_data.vcu_drive_f.front_axle_trq_max, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Drive_F.FRONT_AXLE_TRQ_REQUEST", "", &mp->vcu2ai_data.vcu_drive_f.front_axle_trq_request, DVA_IO_In);

    DDefShort(vcu2ai_df, "Drive_R.REAR_AXLE_TRQ", "", &mp->vcu2ai_data.vcu_drive_r.rear_axle_trq, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Drive_R.REAR_AXLE_TRQ_MAX", "", &mp->vcu2ai_data.vcu_drive_r.rear_axle_trq_max, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Drive_R.REAR_AXLE_TRQ_REQUEST", "", &mp->vcu2ai_data.vcu_drive_r.rear_axle_trq_request, DVA_IO_In);

    DDefShort(vcu2ai_df, "Steer.ANGLE", "", &mp->vcu2ai_data.vcu_steer.angle, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Steer.ANGLE_MAX", "", &mp->vcu2ai_data.vcu_steer.angle_max, DVA_IO_In);
    DDefShort(vcu2ai_df, "Steer.ANGLE_REQUEST", "", &mp->vcu2ai_data.vcu_steer.angle_request, DVA_IO_In);

    DDefUShort(vcu2ai_df, "Speeds.FL_WHEEL_SPEED", "", &mp->vcu2ai_data.vcu_speeds.fl_wheel_speed, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Speeds.FR_WHEEL_SPEED", "", &mp->vcu2ai_data.vcu_speeds.fr_wheel_speed, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Speeds.RL_WHEEL_SPEED", "", &mp->vcu2ai_data.vcu_speeds.rl_wheel_speed, DVA_IO_In);
    DDefUShort(vcu2ai_df, "Speeds.RR_WHEEL_SPEED", "", &mp->vcu2ai_data.vcu_speeds.rr_wheel_speed, DVA_IO_In);

    DDefUChar(vcu2ai_df, "Status.AI_COMMS_LOST", "", &mp->vcu2ai_data.vcu_status.ai_comms_lost, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.AI_ESTOP_REQUEST", "", &mp->vcu2ai_data.vcu_status.ai_estop_request, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.AMI_STATE", "", &mp->vcu2ai_data.vcu_status.ami_state, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.AS_STATE", "", &mp->vcu2ai_data.vcu_status.as_state, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.AS_SWITCH_STATUS", "", &mp->vcu2ai_data.vcu_status.as_switch_status, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.AUTONOMOUS_BRAKING_FAULT", "", &mp->vcu2ai_data.vcu_status.autonomous_braking_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.BMS_FAULT", "", &mp->vcu2ai_data.vcu_status.bms_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.BRAKE_PLAUSIBILITY", "", &mp->vcu2ai_data.vcu_status.brake_plausibility_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.CHARGE_PROCEDURE_FAULT", "", &mp->vcu2ai_data.vcu_status.charge_procedure_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.EBS_FAULT", "", &mp->vcu2ai_data.vcu_status.ebs_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.FAULT_STATUS", "", &mp->vcu2ai_data.vcu_status.fault_status, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.GO_SIGNAL", "", &mp->vcu2ai_data.vcu_status.go_signal, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.HANDSHAKE", "", &mp->vcu2ai_data.vcu_status.handshake, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.HVIL_OPEN_FAULT", "", &mp->vcu2ai_data.vcu_status.hvil_open_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.HVIL_SHORT_FAULT", "", &mp->vcu2ai_data.vcu_status.hvil_short_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.MISSION_STATUS_FAULT", "", &mp->vcu2ai_data.vcu_status.mission_status_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.OFFBOARD_CHARGER_FAULT", "", &mp->vcu2ai_data.vcu_status.offboard_charger_fault, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.SHUTDOWN_CAUSE", "", &mp->vcu2ai_data.vcu_status.shutdown_cause, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.SHUTDOWN_REQUEST", "", &mp->vcu2ai_data.vcu_status.shutdown_request, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.STEERING_STATUS", "", &mp->vcu2ai_data.vcu_status.steering_status, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.TS_SWITCH_STATUS", "", &mp->vcu2ai_data.vcu_status.ts_switch_status, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.WARN_BATT_SOC_LOW", "", &mp->vcu2ai_data.vcu_status.warn_batt_soc_low, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.WARN_BATT_TEMP_HIGH", "", &mp->vcu2ai_data.vcu_status.warn_batt_temp_high, DVA_IO_In);
    DDefUChar(vcu2ai_df, "Status.WARNING_STATUS", "", &mp->vcu2ai_data.vcu_status.warning_status, DVA_IO_In);

    DDefaultDelete(vcu2ai_df);

    tDDefault *adsdv_if_df = DDefaultCreate("ADSDV_Interface.");

    DDefUChar(adsdv_if_df, "LV_Switch", "", &mp->adsdv_if.lv_switch, DVA_IO_In);
    DDefUChar(adsdv_if_df, "AS_Switch", "", &mp->adsdv_if.as_switch, DVA_IO_In);
    DDefUChar(adsdv_if_df, "TS_Switch", "", &mp->adsdv_if.ts_switch, DVA_IO_In);
    DDefUChar(adsdv_if_df, "Go_Signal", "", &mp->adsdv_if.go_signal, DVA_IO_In);
    DDefUChar(adsdv_if_df, "EStop_Switch", "", &mp->adsdv_if.estop_switch, DVA_IO_In);
    // Bool is 1 byte.   Check with sizeof().
    DDefUChar(adsdv_if_df, "TSAL_State", "", (uchar_T *)&mp->hidden_state.motor_control_enabled, DVA_None);
    // Enum is 4 bytes.   Check with sizeof().
    DDefUInt(adsdv_if_df, "ASSI_State", "", (uint32_T *)&mp->hidden_state.autonomous_state, DVA_None);
    DDefUChar(adsdv_if_df, "Mission_Status", "", &mp->adsdv_if.mission_status, DVA_IO_In);
	DDefUChar(adsdv_if_df, "Mission_Set", "", &mp->adsdv_if.mission_set, DVA_IO_In);
    DDefUChar(adsdv_if_df, "Mission_Selected", "", &mp->adsdv_if.mission_selected, DVA_IO_In);

    DDefaultDelete(adsdv_if_df);

    tDDefault *debug_if_df = DDefaultCreate("Debug_Interface.");

    DDefULLong(debug_if_df, "Handshake_Miss_Counter", "", &mp->hidden_state.handshake_miss_counter, DVA_None);
    DDefULLong(debug_if_df, "Simulation_Cycle_Time", "", &mp->simulation_cycle_count, DVA_None);

    DDefaultDelete(debug_if_df);

}


static void
MyModel_DeclQuants (void *MP)
{
    struct tMyModel *mp = (struct tMyModel *)MP;

    if (mp == NULL) {
	/* Define here dict entries for non-dynamically allocated (static) variables. */

    } else {
	MyModel_DeclQuants_dyn (mp, 0);
    }
}

// static LARGE_INTEGER start, now = {0};
// static LARGE_INTEGER frequency = {0};

static int
MyModel_Calc (void *MP, double dt)
{
    struct tMyModel *mp = (struct tMyModel *)MP;

    vcu2ai_data_t vcu2ai_prev_output = mp->vcu2ai_data;
    ai2vcu_data_t ai2vcu_input = mp->ai2vcu_data;
    // bool motor_controlled_enabled = false;

    static boolean_T FirstLogMessage = true;

    char Log_message[512];
    
    if(FirstLogMessage)
    {
        sprintf(Log_message,"first log message: mp has address %p\n", (void *)mp);
        Log(Log_message);
        FirstLogMessage = false;
    }

    // LARGE_INTEGER now;

    // if (frequency.QuadPart == 0)
    // {
    //     QueryPerformanceFrequency(&frequency);
    //     QueryPerformanceCounter(&start);
    // }

    // QueryPerformanceCounter(&now);
    // double elapsed_ms = (double)(now.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

    if (counter == 10)
    {
        // Setup Input Switch States
        mp->vehicle_state.master_switch_e.LVMSState = mp->adsdv_if.lv_switch;
        mp->vehicle_state.master_switch_e.ASMSState = mp->adsdv_if.as_switch;
        mp->vehicle_state.master_switch_e.TSMSState = mp->adsdv_if.ts_switch;
        mp->vehicle_state.master_switch_e.AIMSState = 1;
        mp->vehicle_state.EStop.estop_signalled = (mp->adsdv_if.estop_switch==0);
        mp->vehicle_state.EStop.go_signalled = mp->adsdv_if.go_signal;
        mp->vehicle_state.EStop.watchdog_detected = 1;
        mp->vehicle_state.AIComputerIgnitionSwitchedOn = true;
        mp->vehicle_state.MPPType = MPP_AutonomousDriving;
        //mp->vehicle_state.AMIScreenState.mission = mp->adsdv_if.mission_status;

        // Setup vehicle states
        mp->vehicle_state.VehicleOperatingCondition = VEH_OP_COND_ON_GROUND;

        // // Indicators
        // assi_led_state_e ASSILedState;
        // tsal_led_state_e TSALLedState;
        // AMIScreenState AMIScreenState;
        // // Internal State
        // bool joystick_dead_mans_switch_pressing;

        // vehicle_state_siren_e siren;
        // vehicle_state_actuator_locks_t vehicle_state_actuator_locks;
        // bool ai_connected;

        // vehicle_operating_condition_e VehicleOperatingCondition;

        if (override_handshake)
        {
            ai2vcu_input.ai_status.handshake = vcu2ai_prev_output.vcu_status.handshake;
        }
        else
        {
            ai2vcu_input.ai_status.handshake = (mp->ai2vcu_data.ai_status.handshake > 0);
        }

        if (mp->adsdv_if.mission_set > 0)
        {
            if (mp->adsdv_if.mission_status > 0)
            {
                mp->adsdv_if.mission_selected = mp->adsdv_if.mission_status;
                prev_mission_set = 1;
                mp->adsdv_if.mission_set = 0;
            }
        }
		
		mp->vehicle_state.AMIScreenState.mission = prev_mission_set;
        // ai2vcu_input.ai_status.mission_status = prev_mission_set;

        state_machine_kwargs_t state_machine_kwargs = {
            .ai2vcu = &(ai2vcu_input),
            .vcu2ai = &(mp->vcu2ai_data),
            .hidden_state = &(mp->hidden_state),
            .vehicle_state = &(mp->vehicle_state),
        };

        state_machine_retval_t sm_state = state_machine_iteration(&state_machine_kwargs);

        float rtU_ActualWheelspeedFL_mps = Car.Tire[0].v; //Vehicle.FL.rotv * (2 * PI * Car.WFL.Radius) / (2.0f * PI); // [rad/s] -> mps;
        float rtU_ActualWheelspeedFR_mps = Car.Tire[1].v; //Vehicle.FR.rotv * (2 * PI * Car.WFR.Radius) / (2.0f * PI); // [rad/s] -> mps;
        float rtU_ActualWheelspeedRL_mps = Car.Tire[2].v; //Vehicle.RL.rotv * (2 * PI * Car.WRL.Radius) / (2.0f * PI); // [rad/s] -> mps;
        float rtU_ActualWheelspeedRR_mps = Car.Tire[3].v; //Vehicle.RR.rotv * (2 * PI * Car.WRR.Radius) / (2.0f * PI); // [rad/s] -> mps;

        if ( sm_state.ai2vcu->ai_steer.steer_request > 20)
        {
            sm_state.ai2vcu->ai_steer.steer_request = 20;
        }
        else if ( sm_state.ai2vcu->ai_steer.steer_request < -20)
        {
            sm_state.ai2vcu->ai_steer.steer_request = -20;
        }

        vehicle_model_update(sm_state.ai2vcu, &sm_state.vehicle_state, sm_state.vcu2ai, 
                          rtU_ActualWheelspeedFL_mps, rtU_ActualWheelspeedFR_mps, 
                          rtU_ActualWheelspeedRL_mps, rtU_ActualWheelspeedRR_mps);


        mp->vcu2ai_data.vcu_status.ami_state = mp->adsdv_if.mission_selected;

        if (mp->temp_bool == 0)
        {
            mp->vcu2ai_data.vcu_status.handshake = 1;
            mp->temp_bool = 1;
        }
        else
        {
            mp->vcu2ai_data.vcu_status.handshake = 0;
            mp->temp_bool = 0;
        }
        
        // Steer Output
        // Car.Susp[0].SteerAngle = (sm_state.vcu2ai->vcu_steer.angle * PI / 180.0f);   // [deg] -> [rads]
        // Car.Susp[1].SteerAngle = (sm_state.vcu2ai->vcu_steer.angle * PI / 180.0f);   // [deg] -> [rads]

        // Steer Output
        DVA_WriteRequest("VC.Steer.Ang", OWMode_Abs, -1, 0, 0,  -6.9f*sm_state.vcu2ai->vcu_steer.angle * PI / 180.0f, NULL);

        // eMotor output
        DVA_WriteRequest("VC.Gas", OWMode_Abs, -1, 0, 0,  (sm_state.vcu2ai->vcu_drive_r.rear_axle_trq / (195.0f)), NULL);

        // Brake Output
        DVA_WriteRequest("VC.Brake", OWMode_Abs, -1, 0, 0,  (sm_state.vcu2ai->vcu_brake.hyd_press_r_pct / 100.0F), NULL);
        
        counter = 0;

        // count the number of 10ms cycles executed
        mp->simulation_cycle_count++;
    }

    counter++;
    
    return 0;
}


static void *
MyModel_New (struct tInfos *Inf, const char *KindKey)
{
    struct tMyModel *mp = NULL;
    const char *ModelKind;
    int VersionId = 0;
    char Log_message[512];

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_VehicleControl, KindKey,
	 				 0, ThisVersionId, &VersionId)) == NULL)
	return NULL;

    mp = (struct tMyModel *)calloc(1, sizeof(*mp));
    sprintf(Log_message,"mp allocated at address %p\n", (void *)mp);
    Log(Log_message);

    sprintf(Log_message,"Size of enum: %llu, bool %llu\n", sizeof(mp->hidden_state.autonomous_state), sizeof(boolean_T));
    Log(Log_message);


    // Initialise ZF Vehicle Model and State Machine
    vehicle_model_init();
    state_machine_hidden_state_t __private_state_machine_hidden_state = {0};
    mp->hidden_state = __private_state_machine_hidden_state;
    vehicle_state_t temp_vehicle_state = {0};
    mp->vehicle_state = temp_vehicle_state;

    if (override_handshake)
    {
        Log("WARNING: FSAI override_handshake is set to true\n");
    }

    return mp;
}


static void
MyModel_Delete (void *MP)
{
    struct tMyModel *mp = (struct tMyModel *)MP;
    char Log_message[512];
    /* Park the dict entries for dynamically allocated variables before deleting */
    MyModel_DeclQuants_dyn (mp, 1);
    free (mp);

    sprintf(Log_message,"mp freed at address %p\n", (void *)mp);
    Log(Log_message);
}


int
VehicleControl_Register_MyModel (void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.VehicleControl.VersionId =	ThisVersionId;	
    m.VehicleControl.New    = 		MyModel_New;
    m.VehicleControl.Calc   = 		MyModel_Calc;
    m.VehicleControl.DeclQuants   = 	MyModel_DeclQuants;
    m.VehicleControl.Delete = 		MyModel_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    m.VehicleControl.ParamsChanged = 	ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_VehicleControl, ThisModelKind, &m);
}
