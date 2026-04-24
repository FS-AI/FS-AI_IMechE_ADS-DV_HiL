/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
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

typedef struct tRBS_0_AI_AI2VCU_Status_Sigs {
    tRBS_Signal *Sig_DIRECTION_REQUEST;
    unsigned char *DIRECTION_REQUEST;
    tRBS_Signal *Sig_ESTOP_REQUEST;
    char *ESTOP_REQUEST;
    tRBS_Signal *Sig_HANDSHAKE;
    unsigned char *HANDSHAKE;
    tRBS_Signal *Sig_MISSION_STATUS;
    unsigned char *MISSION_STATUS;
} tRBS_0_AI_AI2VCU_Status_Sigs;
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
typedef struct tRBS_0_OPUS_OPUS2VCU_FB_Sigs {
    tRBS_Signal *Sig_AMI_STATE;
    unsigned char *AMI_STATE;
    tRBS_Signal *Sig_BRK_DISCH_REQ;
    char *BRK_DISCH_REQ;
    tRBS_Signal *Sig_CHARGE_REQ;
    char *CHARGE_REQ;
} tRBS_0_OPUS_OPUS2VCU_FB_Sigs;
typedef struct tRBS_0_VCU_VCU2OPUS_3_Sigs {
    tRBS_Signal *Sig_EBS_TEST_BITFIELD;
    unsigned short *EBS_TEST_BITFIELD;
    tRBS_Signal *Sig_EBS_TEST_BITFIELD_LATCHED;
    unsigned short *EBS_TEST_BITFIELD_LATCHED;
} tRBS_0_VCU_VCU2OPUS_3_Sigs;
typedef struct tRBS_0_VCU_VCU2OPUS_2_Sigs {
    tRBS_Signal *Sig_EBS_FRONT_ACC_PRESS;
    double *EBS_FRONT_ACC_PRESS;
    tRBS_Signal *Sig_EBS_FRONT_CALIPER_PRESS;
    double *EBS_FRONT_CALIPER_PRESS;
    tRBS_Signal *Sig_EBS_REAR_ACC_PRESS;
    double *EBS_REAR_ACC_PRESS;
    tRBS_Signal *Sig_EBS_REAR_CALIPER_PRESS;
    double *EBS_REAR_CALIPER_PRESS;
} tRBS_0_VCU_VCU2OPUS_2_Sigs;
typedef struct tRBS_0_VCU_VCU2OPUS_1_Sigs {
    tRBS_Signal *Sig_AUX_HV;
    double *AUX_HV;
    tRBS_Signal *Sig_KL15_ADC;
    double *KL15_ADC;
    tRBS_Signal *Sig_LEM_500A_ADC;
    double *LEM_500A_ADC;
    tRBS_Signal *Sig_VBAT_ADC;
    double *VBAT_ADC;
} tRBS_0_VCU_VCU2OPUS_1_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Status_Sigs {
    tRBS_Signal *Sig_AMI_STATE;
    unsigned char *AMI_STATE;
    tRBS_Signal *Sig_AS_STATE;
    unsigned char *AS_STATE;
    tRBS_Signal *Sig_AS_SWITCH_STATUS;
    char *AS_SWITCH_STATUS;
    tRBS_Signal *Sig_EBS_STATE;
    unsigned char *EBS_STATE;
    tRBS_Signal *Sig_GO_SIGNAL;
    char *GO_SIGNAL;
    tRBS_Signal *Sig_HANDSHAKE;
    unsigned char *HANDSHAKE;
    tRBS_Signal *Sig_HVIL_OPEN_FAULT;
    char *HVIL_OPEN_FAULT;
    tRBS_Signal *Sig_OP_STATE;
    unsigned char *OP_STATE;
    tRBS_Signal *Sig_STEERING_STATUS;
    unsigned char *STEERING_STATUS;
    tRBS_Signal *Sig_TS_STATE;
    unsigned char *TS_STATE;
    tRBS_Signal *Sig_TS_SWITCH_STATUS;
    char *TS_SWITCH_STATUS;
} tRBS_0_VCU_VCU2AI_Status_Sigs;
typedef struct tRBS_0_VCU_VCU2AI_Steer_Sigs {
    tRBS_Signal *Sig_ANGLE;
    double *ANGLE;
    tRBS_Signal *Sig_ANGLE_MAX;
    double *ANGLE_MAX;
    tRBS_Signal *Sig_ANGLE_REQUEST;
    double *ANGLE_REQUEST;
} tRBS_0_VCU_VCU2AI_Steer_Sigs;
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
