/*
 *****************************************************************************
 *  CarMaker - Version 14.0.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 */

/******************************************************************************
 * +++ ATTENTION +++ ATTENTION +++ ATTENTION +++ ATTENTION +++ ATTENTION +++
 *
 *     Please, don't modify this file!
 *
 * +++ ATTENTION +++ ATTENTION +++ ATTENTION +++ ATTENTION +++ ATTENTION +++
 ******************************************************************************
 */

#if !defined(__RBS_0_SIGNAL_DATA_H__)
#define __RBS_0_SIGNAL_DATA_H__

#include <rbs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tRBS_0_OPUS_OPUS2VCU_FB_Sigs {
    tRBS_Signal *Sig_AMI_STATE;
    unsigned char *AMI_STATE;
    tRBS_Signal *Sig_BRK_DISCH_REQ;
    char *BRK_DISCH_REQ;
} tRBS_0_OPUS_OPUS2VCU_FB_Sigs;
typedef struct tRBS_0_AI_AI2VCU_Status_Sigs {
    tRBS_Signal *Sig_CONES_COUNT_ACTUAL;
    unsigned char *CONES_COUNT_ACTUAL;
    tRBS_Signal *Sig_CONES_COUNT_ALL;
    unsigned short *CONES_COUNT_ALL;
    tRBS_Signal *Sig_DIRECTION_REQUEST;
    unsigned char *DIRECTION_REQUEST;
    tRBS_Signal *Sig_ESTOP_REQUEST;
    char *ESTOP_REQUEST;
    tRBS_Signal *Sig_HANDSHAKE;
    unsigned char *HANDSHAKE;
    tRBS_Signal *Sig_LAP_COUNTER;
    unsigned char *LAP_COUNTER;
    tRBS_Signal *Sig_MISSION_STATUS;
    unsigned char *MISSION_STATUS;
    tRBS_Signal *Sig_VEH_SPEED_ACTUAL;
    unsigned char *VEH_SPEED_ACTUAL;
    tRBS_Signal *Sig_VEH_SPEED_DEMAND;
    unsigned char *VEH_SPEED_DEMAND;
} tRBS_0_AI_AI2VCU_Status_Sigs;
typedef struct tRBS_0_AI_AI2VCU_Drive_F_Sigs {
    tRBS_Signal *Sig_FRONT_AXLE_TRQ_REQUEST;
    double *FRONT_AXLE_TRQ_REQUEST;
    tRBS_Signal *Sig_FRONT_MOTOR_SPEED_MAX;
    unsigned short *FRONT_MOTOR_SPEED_MAX;
} tRBS_0_AI_AI2VCU_Drive_F_Sigs;
typedef struct tRBS_0_AI_AI2VCU_Drive_R_Sigs {
    tRBS_Signal *Sig_REAR_AXLE_TRQ_REQUEST;
    double *REAR_AXLE_TRQ_REQUEST;
    tRBS_Signal *Sig_REAR_MOTOR_SPEED_MAX;
    unsigned short *REAR_MOTOR_SPEED_MAX;
} tRBS_0_AI_AI2VCU_Drive_R_Sigs;
typedef struct tRBS_0_AI_AI2VCU_Steer_Sigs {
    tRBS_Signal *Sig_STEER_REQUEST;
    double *STEER_REQUEST;
} tRBS_0_AI_AI2VCU_Steer_Sigs;
typedef struct tRBS_0_AI_AI2VCU_Brake_Sigs {
    tRBS_Signal *Sig_HYD_PRESS_F_REQ_pct;
    double *HYD_PRESS_F_REQ_pct;
    tRBS_Signal *Sig_HYD_PRESS_R_REQ_pct;
    double *HYD_PRESS_R_REQ_pct;
} tRBS_0_AI_AI2VCU_Brake_Sigs;
typedef struct tRBS_0_VCU_NMT_Sigs {
    tRBS_Signal *Sig_CMD;
    unsigned char *CMD;
    tRBS_Signal *Sig_NODE_ID;
    unsigned char *NODE_ID;
} tRBS_0_VCU_NMT_Sigs;
typedef struct tRBS_0_VCU_VCU2LOG_Dynamics1_Sigs {
    tRBS_Signal *Sig_Brake_actual_pct;
    unsigned char *Brake_actual_pct;
    tRBS_Signal *Sig_Brake_target_pct;
    unsigned char *Brake_target_pct;
    tRBS_Signal *Sig_Drive_trq_actual_pct;
    unsigned char *Drive_trq_actual_pct;
    tRBS_Signal *Sig_Drive_trq_target_pct;
    unsigned char *Drive_trq_target_pct;
    tRBS_Signal *Sig_Speed_actual;
    unsigned char *Speed_actual;
    tRBS_Signal *Sig_Speed_target;
    unsigned char *Speed_target;
    tRBS_Signal *Sig_Steer_actual;
    double *Steer_actual;
    tRBS_Signal *Sig_Steer_target;
    double *Steer_target;
} tRBS_0_VCU_VCU2LOG_Dynamics1_Sigs;
typedef struct tRBS_0_VCU_VCU2LOG_Status_Sigs {
    tRBS_Signal *Sig_AMI_STATE;
    unsigned char *AMI_STATE;
    tRBS_Signal *Sig_Cones_count_actual;
    unsigned char *Cones_count_actual;
    tRBS_Signal *Sig_Cones_count_all;
    unsigned int *Cones_count_all;
    tRBS_Signal *Sig_Lap_counter;
    unsigned char *Lap_counter;
    tRBS_Signal *Sig_State_ASSI;
    unsigned char *State_ASSI;
    tRBS_Signal *Sig_State_EBS;
    unsigned char *State_EBS;
    tRBS_Signal *Sig_State_service_brake;
    unsigned char *State_service_brake;
    tRBS_Signal *Sig_State_steering;
    char *State_steering;
} tRBS_0_VCU_VCU2LOG_Status_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Status_Sigs {
    tRBS_Signal *Sig_AI_COMMS_LOST;
    char *AI_COMMS_LOST;
    tRBS_Signal *Sig_AI_ESTOP_REQUEST;
    char *AI_ESTOP_REQUEST;
    tRBS_Signal *Sig_AMI_STATE;
    unsigned char *AMI_STATE;
    tRBS_Signal *Sig_AS_STATE;
    unsigned char *AS_STATE;
    tRBS_Signal *Sig_AS_SWITCH_STATUS;
    char *AS_SWITCH_STATUS;
    tRBS_Signal *Sig_AUTONOMOUS_BRAKING_FAULT;
    char *AUTONOMOUS_BRAKING_FAULT;
    tRBS_Signal *Sig_BMS_FAULT;
    char *BMS_FAULT;
    tRBS_Signal *Sig_BRAKE_PLAUSIBILITY_FAULT;
    char *BRAKE_PLAUSIBILITY_FAULT;
    tRBS_Signal *Sig_CHARGE_PROCEDURE_FAULT;
    char *CHARGE_PROCEDURE_FAULT;
    tRBS_Signal *Sig_EBS_FAULT;
    char *EBS_FAULT;
    tRBS_Signal *Sig_FAULT_STATUS;
    char *FAULT_STATUS;
    tRBS_Signal *Sig_GO_SIGNAL;
    char *GO_SIGNAL;
    tRBS_Signal *Sig_HANDSHAKE;
    unsigned char *HANDSHAKE;
    tRBS_Signal *Sig_HVIL_OPEN_FAULT;
    char *HVIL_OPEN_FAULT;
    tRBS_Signal *Sig_HVIL_SHORT_FAULT;
    char *HVIL_SHORT_FAULT;
    tRBS_Signal *Sig_MISSION_STATUS_FAULT;
    char *MISSION_STATUS_FAULT;
    tRBS_Signal *Sig_OFFBOARD_CHARGER_FAULT;
    char *OFFBOARD_CHARGER_FAULT;
    tRBS_Signal *Sig_SHUTDOWN_CAUSE;
    unsigned char *SHUTDOWN_CAUSE;
    tRBS_Signal *Sig_SHUTDOWN_REQUEST;
    char *SHUTDOWN_REQUEST;
    tRBS_Signal *Sig_STEERING_STATUS;
    unsigned char *STEERING_STATUS;
    tRBS_Signal *Sig_TS_SWITCH_STATUS;
    char *TS_SWITCH_STATUS;
    tRBS_Signal *Sig_WARN_BATT_SOC_LOW;
    char *WARN_BATT_SOC_LOW;
    tRBS_Signal *Sig_WARN_BATT_TEMP_HIGH;
    char *WARN_BATT_TEMP_HIGH;
    tRBS_Signal *Sig_WARNING_STATUS;
    char *WARNING_STATUS;
} tRBS_0_VCU_VCU2AI_Status_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Drive_F_Sigs {
    tRBS_Signal *Sig_FRONT_AXLE_TRQ;
    double *FRONT_AXLE_TRQ;
    tRBS_Signal *Sig_FRONT_AXLE_TRQ_MAX;
    double *FRONT_AXLE_TRQ_MAX;
    tRBS_Signal *Sig_FRONT_AXLE_TRQ_REQUEST;
    double *FRONT_AXLE_TRQ_REQUEST;
} tRBS_0_VCU_VCU2AI_Drive_F_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Drive_R_Sigs {
    tRBS_Signal *Sig_REAR_AXLE_TRQ_MAX_Nm;
    double *REAR_AXLE_TRQ_MAX_Nm;
    tRBS_Signal *Sig_REAR_AXLE_TRQ_Nm;
    double *REAR_AXLE_TRQ_Nm;
    tRBS_Signal *Sig_REAR_AXLE_TRQ_REQUEST_Nm;
    double *REAR_AXLE_TRQ_REQUEST_Nm;
} tRBS_0_VCU_VCU2AI_Drive_R_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Steer_Sigs {
    tRBS_Signal *Sig_ANGLE;
    double *ANGLE;
    tRBS_Signal *Sig_ANGLE_MAX;
    double *ANGLE_MAX;
    tRBS_Signal *Sig_ANGLE_REQUEST;
    double *ANGLE_REQUEST;
} tRBS_0_VCU_VCU2AI_Steer_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Brake_Sigs {
    tRBS_Signal *Sig_HYD_PRESS_F_pct;
    double *HYD_PRESS_F_pct;
    tRBS_Signal *Sig_HYD_PRESS_F_REQ_pct;
    double *HYD_PRESS_F_REQ_pct;
    tRBS_Signal *Sig_HYD_PRESS_R_pct;
    double *HYD_PRESS_R_pct;
    tRBS_Signal *Sig_HYD_PRESS_R_REQ_pct;
    double *HYD_PRESS_R_REQ_pct;
    tRBS_Signal *Sig_STATUS_BRK;
    unsigned char *STATUS_BRK;
    tRBS_Signal *Sig_STATUS_EBS;
    unsigned char *STATUS_EBS;
} tRBS_0_VCU_VCU2AI_Brake_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Speeds_Sigs {
    tRBS_Signal *Sig_FL_WHEEL_SPEED;
    unsigned short *FL_WHEEL_SPEED;
    tRBS_Signal *Sig_FR_WHEEL_SPEED;
    unsigned short *FR_WHEEL_SPEED;
    tRBS_Signal *Sig_RL_WHEEL_SPEED;
    unsigned short *RL_WHEEL_SPEED;
    tRBS_Signal *Sig_RR_WHEEL_SPEED;
    unsigned short *RR_WHEEL_SPEED;
} tRBS_0_VCU_VCU2AI_Speeds_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Wheel_counts_Sigs {
    tRBS_Signal *Sig_FL_PULSE_COUNT;
    unsigned short *FL_PULSE_COUNT;
    tRBS_Signal *Sig_FR_PULSE_COUNT;
    unsigned short *FR_PULSE_COUNT;
    tRBS_Signal *Sig_RL_PULSE_COUNT;
    unsigned short *RL_PULSE_COUNT;
    tRBS_Signal *Sig_RR_PULSE_COUNT;
    unsigned short *RR_PULSE_COUNT;
} tRBS_0_VCU_VCU2AI_Wheel_counts_Sigs;

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_SIGNAL_DATA_H__) */
