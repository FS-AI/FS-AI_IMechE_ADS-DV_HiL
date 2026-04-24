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

#if !defined(__RBS_0_SIGNAL_H__)
#define __RBS_0_SIGNAL_H__

#include <rbs.h>

#ifdef __cplusplus
extern "C" {
#endif

int RBS_0_AI_AI2VCU_Status_DIRECTION_REQUEST_Init	(struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_DIRECTION_REQUEST_Decode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_DIRECTION_REQUEST_PostMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Status_ESTOP_REQUEST_Init	(struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_ESTOP_REQUEST_Decode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_ESTOP_REQUEST_PostMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Status_HANDSHAKE_Init	(struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_HANDSHAKE_Decode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_HANDSHAKE_PostMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Status_MISSION_STATUS_Init	(struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_MISSION_STATUS_Decode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_AI_AI2VCU_Status_MISSION_STATUS_PostMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Steer_STEER_REQUEST_Init	(struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Brake_HYD_PRESS_F_REQ_pct_Init	(struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Brake_HYD_PRESS_R_REQ_pct_Init	(struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Drive_F_FRONT_AXLE_TRQ_REQUEST_Init	(struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Drive_F_FRONT_MOTOR_SPEED_MAX_Init	(struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Drive_R_REAR_AXLE_TRQ_REQUEST_Init	(struct tRBS_Signal *sig);

int RBS_0_AI_AI2VCU_Drive_R_REAR_MOTOR_SPEED_MAX_Init	(struct tRBS_Signal *sig);

int RBS_0_OPUS_OPUS2VCU_FB_AMI_STATE_Init	(struct tRBS_Signal *sig);

int RBS_0_OPUS_OPUS2VCU_FB_BRK_DISCH_REQ_Init	(struct tRBS_Signal *sig);

int RBS_0_OPUS_OPUS2VCU_FB_CHARGE_REQ_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_3_EBS_TEST_BITFIELD_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_3_EBS_TEST_BITFIELD_LATCHED_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_2_EBS_FRONT_ACC_PRESS_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_2_EBS_FRONT_CALIPER_PRESS_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_2_EBS_REAR_ACC_PRESS_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_2_EBS_REAR_CALIPER_PRESS_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_1_AUX_HV_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_1_KL15_ADC_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_1_LEM_500A_ADC_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2OPUS_1_VBAT_ADC_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_AMI_STATE_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_AMI_STATE_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_AMI_STATE_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_AS_STATE_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_AS_STATE_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_AS_STATE_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_AS_SWITCH_STATUS_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_AS_SWITCH_STATUS_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_AS_SWITCH_STATUS_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_EBS_STATE_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_GO_SIGNAL_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_GO_SIGNAL_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_GO_SIGNAL_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_HANDSHAKE_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_HANDSHAKE_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_HANDSHAKE_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_HVIL_OPEN_FAULT_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_HVIL_OPEN_FAULT_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_HVIL_OPEN_FAULT_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_OP_STATE_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_STEERING_STATUS_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_STEERING_STATUS_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_STEERING_STATUS_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_TS_STATE_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Status_TS_SWITCH_STATUS_Init	(struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_TS_SWITCH_STATUS_Encode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);
int RBS_0_VCU_VCU2AI_Status_TS_SWITCH_STATUS_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu, struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Steer_ANGLE_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Steer_ANGLE_MAX_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Steer_ANGLE_REQUEST_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Speeds_FL_WHEEL_SPEED_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Speeds_FR_WHEEL_SPEED_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Speeds_RL_WHEEL_SPEED_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Speeds_RR_WHEEL_SPEED_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_F_pct_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_F_REQ_pct_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_R_pct_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_R_REQ_pct_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Brake_STATUS_BRK_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Brake_STATUS_EBS_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Drive_F_FRONT_AXLE_TRQ_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Drive_F_FRONT_AXLE_TRQ_MAX_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Drive_F_FRONT_AXLE_TRQ_REQUEST_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Drive_R_REAR_AXLE_TRQ_MAX_Nm_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Drive_R_REAR_AXLE_TRQ_Nm_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Drive_R_REAR_AXLE_TRQ_REQUEST_Nm_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Wheel_counts_FL_PULSE_COUNT_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Wheel_counts_FR_PULSE_COUNT_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Wheel_counts_RL_PULSE_COUNT_Init	(struct tRBS_Signal *sig);

int RBS_0_VCU_VCU2AI_Wheel_counts_RR_PULSE_COUNT_Init	(struct tRBS_Signal *sig);

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_SIGNAL_H__) */
