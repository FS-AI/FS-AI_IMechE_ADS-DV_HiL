
/*
 *****************************************************************************
 *  CarMaker - Version 14.0.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 */

#include "RBS_0.h"

#include <stdlib.h>
#include <string.h>

/* ---- User Code - Start ---- */

/* ---- User Code - End   ---- */

#if 0
int
RBS_0_OutMap(
    unsigned CycleNo)
{
// Start of generated list. Do not remove.
//    *(RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_F_pct)                = 0;
//    *(RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_F_REQ_pct)            = 0;
//    *(RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_R_pct)                = 0;
//    *(RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_R_REQ_pct)            = 0;
//    *(RBS_0.VCU.VCU2AI_Brake.STATUS_BRK)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Brake.STATUS_EBS)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Drive_F.FRONT_AXLE_TRQ)               = 0;
//    *(RBS_0.VCU.VCU2AI_Drive_F.FRONT_AXLE_TRQ_MAX)           = 0;
//    *(RBS_0.VCU.VCU2AI_Drive_F.FRONT_AXLE_TRQ_REQUEST)       = 0;
//    *(RBS_0.VCU.VCU2AI_Drive_R.REAR_AXLE_TRQ)                = 0;
//    *(RBS_0.VCU.VCU2AI_Drive_R.REAR_AXLE_TRQ_MAX)            = 0;
//    *(RBS_0.VCU.VCU2AI_Drive_R.REAR_AXLE_TRQ_REQUEST)        = 0;
//    *(RBS_0.VCU.VCU2AI_Speeds.FL_WHEEL_SPEED)                = 0;
//    *(RBS_0.VCU.VCU2AI_Speeds.FR_WHEEL_SPEED)                = 0;
//    *(RBS_0.VCU.VCU2AI_Speeds.RL_WHEEL_SPEED)                = 0;
//    *(RBS_0.VCU.VCU2AI_Speeds.RR_WHEEL_SPEED)                = 0;
//    *(RBS_0.VCU.VCU2AI_Status.AI_COMMS_LOST)                 = 0;
//    *(RBS_0.VCU.VCU2AI_Status.AI_ESTOP_REQUEST)              = 0;
//    *(RBS_0.VCU.VCU2AI_Status.AMI_STATE)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Status.AS_STATE)                      = 0;
//    *(RBS_0.VCU.VCU2AI_Status.AS_SWITCH_STATUS)              = 0;
//    *(RBS_0.VCU.VCU2AI_Status.AUTONOMOUS_BRAKING_FAULT)      = 0;
//    *(RBS_0.VCU.VCU2AI_Status.BMS_FAULT)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Status.BRAKE_PLAUSIBILITY_FAULT)      = 0;
//    *(RBS_0.VCU.VCU2AI_Status.CHARGE_PROCEDURE_FAULT)        = 0;
//    *(RBS_0.VCU.VCU2AI_Status.EBS_FAULT)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Status.FAULT_STATUS)                  = 0;
//    *(RBS_0.VCU.VCU2AI_Status.GO_SIGNAL)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Status.HANDSHAKE)                     = 0;
//    *(RBS_0.VCU.VCU2AI_Status.HVIL_OPEN_FAULT)               = 0;
//    *(RBS_0.VCU.VCU2AI_Status.HVIL_SHORT_FAULT)              = 0;
//    *(RBS_0.VCU.VCU2AI_Status.MISSION_STATUS_FAULT)          = 0;
//    *(RBS_0.VCU.VCU2AI_Status.OFFBOARD_CHARGER_FAULT)        = 0;
//    *(RBS_0.VCU.VCU2AI_Status.SHUTDOWN_CAUSE)                = 0;
//    *(RBS_0.VCU.VCU2AI_Status.SHUTDOWN_REQUEST)              = 0;
//    *(RBS_0.VCU.VCU2AI_Status.STEERING_STATUS)               = 0;
//    *(RBS_0.VCU.VCU2AI_Status.TS_SWITCH_STATUS)              = 0;
//    *(RBS_0.VCU.VCU2AI_Status.WARN_BATT_SOC_LOW)             = 0;
//    *(RBS_0.VCU.VCU2AI_Status.WARN_BATT_TEMP_HIGH)           = 0;
//    *(RBS_0.VCU.VCU2AI_Status.WARNING_STATUS)                = 0;
//    *(RBS_0.VCU.VCU2AI_Steer.ANGLE)                          = 0;
//    *(RBS_0.VCU.VCU2AI_Steer.ANGLE_MAX)                      = 0;
//    *(RBS_0.VCU.VCU2AI_Steer.ANGLE_REQUEST)                  = 0;
//    *(RBS_0.VCU.VCU2AI_Wheel_counts.FL_PULSE_COUNT)          = 0;
//    *(RBS_0.VCU.VCU2AI_Wheel_counts.FR_PULSE_COUNT)          = 0;
//    *(RBS_0.VCU.VCU2AI_Wheel_counts.RL_PULSE_COUNT)          = 0;
//    *(RBS_0.VCU.VCU2AI_Wheel_counts.RR_PULSE_COUNT)          = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Brake_actual_pct)          = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Brake_target_pct)          = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Drive_trq_actual_pct)      = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Drive_trq_target_pct)      = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Speed_actual)              = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Speed_target)              = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Steer_actual)              = 0;
//    *(RBS_0.VCU.VCU2LOG_Dynamics1.Steer_target)              = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.AMI_STATE)                    = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.Cones_count_actual)           = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.Cones_count_all)              = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.Lap_counter)                  = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.State_ASSI)                   = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.State_EBS)                    = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.State_service_brake)          = 0;
//    *(RBS_0.VCU.VCU2LOG_Status.State_steering)               = 0;
//    *(RBS_0.VCU.VCU_STATUS.R1_AI2VCU_BRAKE_TIMEOUT_ERROR)    = 0;
//    *(RBS_0.VCU.VCU_STATUS.R1_AI2VCU_DRIVE_F_TIMEOUT_ERROR)  = 0;
//    *(RBS_0.VCU.VCU_STATUS.R1_AI2VCU_DRIVE_R_TIMEOUT_ERROR)  = 0;
//    *(RBS_0.VCU.VCU_STATUS.R1_AI2VCU_STATUS_HANDSHAKE_TIMEO) = 0;
//    *(RBS_0.VCU.VCU_STATUS.R1_AI2VCU_STATUS_TIMEOUT_ERROR)   = 0;
//    *(RBS_0.VCU.VCU_STATUS.R1_AI2VCU_STEER_TIMEOUT_ERROR)    = 0;
//    *(RBS_0.VCU.VCU_STATUS.SM_AS)                            = 0;
//    *(RBS_0.VCU.VCU_STATUS.SM_SYS)                           = 0;
//    *(RBS_0.VCU.VCU_STATUS.SYS_ACTION_STATE)                 = 0;
//    *(RBS_0.VCU.VCU_STATUS.WARN_AI_COMMS_LOST)               = 0;
//    *(RBS_0.VCU.VCU_STATUS.WARN_AI_ESTOP_REQ)                = 0;
//    *(RBS_0.VCU.VCU_STATUS.WARN_AUTO_BRAKING)                = 0;
//    *(RBS_0.VCU.VCU_STATUS.WARN_BRAKE_PLAUSIBILITY)          = 0;
//    *(RBS_0.VCU.VCU_STATUS.WARN_KL15_UNDER_V)                = 0;
//    *(RBS_0.VCU.VCU_STATUS.WARN_MISSION_STATUS)              = 0;
// End of generated list. Do not remove.
    return 0;
}
#endif
