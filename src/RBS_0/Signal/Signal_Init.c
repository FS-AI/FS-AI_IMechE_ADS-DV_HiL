
/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 */

#include "../RBS_0.h"

/* ---- User Code - Start ---- */

/* ---- User Code - End   ---- */

int
RBS_0_AI_AI2VCU_Status_DIRECTION_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_DIRECTION_REQUEST = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.DIRECTION_REQUEST = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_AI_AI2VCU_Status_ESTOP_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_ESTOP_REQUEST = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.ESTOP_REQUEST = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_AI_AI2VCU_Status_HANDSHAKE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_HANDSHAKE = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.HANDSHAKE = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_AI_AI2VCU_Status_MISSION_STATUS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_MISSION_STATUS = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.MISSION_STATUS = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_AI_AI2VCU_Steer_STEER_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Steer.Sig_STEER_REQUEST = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Steer.STEER_REQUEST = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_AI_AI2VCU_Brake_HYD_PRESS_F_REQ_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Brake.Sig_HYD_PRESS_F_REQ_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Brake.HYD_PRESS_F_REQ_pct = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_AI_AI2VCU_Brake_HYD_PRESS_R_REQ_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Brake.Sig_HYD_PRESS_R_REQ_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Brake.HYD_PRESS_R_REQ_pct = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_AI_AI2VCU_Drive_F_FRONT_AXLE_TRQ_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Drive_F.Sig_FRONT_AXLE_TRQ_REQUEST = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Drive_F.FRONT_AXLE_TRQ_REQUEST = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_AI_AI2VCU_Drive_F_FRONT_MOTOR_SPEED_MAX_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Drive_F.Sig_FRONT_MOTOR_SPEED_MAX = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Drive_F.FRONT_MOTOR_SPEED_MAX = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_AI_AI2VCU_Drive_R_REAR_AXLE_TRQ_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Drive_R.Sig_REAR_AXLE_TRQ_REQUEST = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Drive_R.REAR_AXLE_TRQ_REQUEST = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_AI_AI2VCU_Drive_R_REAR_MOTOR_SPEED_MAX_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.AI.AI2VCU_Drive_R.Sig_REAR_MOTOR_SPEED_MAX = sig;

    if (sig->SigVar != NULL) {
        RBS_0.AI.AI2VCU_Drive_R.REAR_MOTOR_SPEED_MAX = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_OPUS_OPUS2VCU_FB_AMI_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.OPUS.OPUS2VCU_FB.Sig_AMI_STATE = sig;

    if (sig->SigVar != NULL)
    	RBS_0.OPUS.OPUS2VCU_FB.AMI_STATE = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_OPUS_OPUS2VCU_FB_BRK_DISCH_REQ_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.OPUS.OPUS2VCU_FB.Sig_BRK_DISCH_REQ = sig;

    if (sig->SigVar != NULL)
    	RBS_0.OPUS.OPUS2VCU_FB.BRK_DISCH_REQ = &sig->SigVar->Char;

    return 0;
}

int
RBS_0_OPUS_OPUS2VCU_FB_CHARGE_REQ_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.OPUS.OPUS2VCU_FB.Sig_CHARGE_REQ = sig;

    if (sig->SigVar != NULL) {
        RBS_0.OPUS.OPUS2VCU_FB.CHARGE_REQ = &sig->SigVar->Char;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_3_EBS_TEST_BITFIELD_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_3.Sig_EBS_TEST_BITFIELD = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_3.EBS_TEST_BITFIELD = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_3_EBS_TEST_BITFIELD_LATCHED_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_3.Sig_EBS_TEST_BITFIELD_LATCHED = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_3.EBS_TEST_BITFIELD_LATCHED = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_2_EBS_FRONT_ACC_PRESS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_2.Sig_EBS_FRONT_ACC_PRESS = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_2.EBS_FRONT_ACC_PRESS = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_2_EBS_FRONT_CALIPER_PRESS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_2.Sig_EBS_FRONT_CALIPER_PRESS = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_2.EBS_FRONT_CALIPER_PRESS = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_2_EBS_REAR_ACC_PRESS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_2.Sig_EBS_REAR_ACC_PRESS = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_2.EBS_REAR_ACC_PRESS = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_2_EBS_REAR_CALIPER_PRESS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_2.Sig_EBS_REAR_CALIPER_PRESS = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_2.EBS_REAR_CALIPER_PRESS = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_1_AUX_HV_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_1.Sig_AUX_HV = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_1.AUX_HV = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_1_KL15_ADC_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_1.Sig_KL15_ADC = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_1.KL15_ADC = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_1_LEM_500A_ADC_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_1.Sig_LEM_500A_ADC = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_1.LEM_500A_ADC = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2OPUS_1_VBAT_ADC_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2OPUS_1.Sig_VBAT_ADC = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2OPUS_1.VBAT_ADC = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_AMI_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_AMI_STATE = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.AMI_STATE = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_AS_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_AS_STATE = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.AS_STATE = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_AS_SWITCH_STATUS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_AS_SWITCH_STATUS = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.AS_SWITCH_STATUS = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_EBS_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Status.Sig_EBS_STATE = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Status.EBS_STATE = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_GO_SIGNAL_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_GO_SIGNAL = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.GO_SIGNAL = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_HANDSHAKE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_HANDSHAKE = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.HANDSHAKE = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_HVIL_OPEN_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_HVIL_OPEN_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.HVIL_OPEN_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_OP_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Status.Sig_OP_STATE = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Status.OP_STATE = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_STEERING_STATUS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_STEERING_STATUS = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.STEERING_STATUS = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_TS_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Status.Sig_TS_STATE = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Status.TS_STATE = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_TS_SWITCH_STATUS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_TS_SWITCH_STATUS = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.TS_SWITCH_STATUS = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Steer_ANGLE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Steer.Sig_ANGLE = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Steer.ANGLE = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Steer_ANGLE_MAX_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Steer.Sig_ANGLE_MAX = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Steer.ANGLE_MAX = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Steer_ANGLE_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Steer.Sig_ANGLE_REQUEST = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Steer.ANGLE_REQUEST = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Speeds_FL_WHEEL_SPEED_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Speeds.Sig_FL_WHEEL_SPEED = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Speeds.FL_WHEEL_SPEED = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Speeds_FR_WHEEL_SPEED_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Speeds.Sig_FR_WHEEL_SPEED = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Speeds.FR_WHEEL_SPEED = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Speeds_RL_WHEEL_SPEED_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Speeds.Sig_RL_WHEEL_SPEED = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Speeds.RL_WHEEL_SPEED = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Speeds_RR_WHEEL_SPEED_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Speeds.Sig_RR_WHEEL_SPEED = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Speeds.RR_WHEEL_SPEED = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_F_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Brake.Sig_HYD_PRESS_F_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_F_pct = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_F_REQ_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Brake.Sig_HYD_PRESS_F_REQ_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_F_REQ_pct = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_R_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Brake.Sig_HYD_PRESS_R_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_R_pct = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_HYD_PRESS_R_REQ_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Brake.Sig_HYD_PRESS_R_REQ_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Brake.HYD_PRESS_R_REQ_pct = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_STATUS_BRK_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Brake.Sig_STATUS_BRK = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Brake.STATUS_BRK = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_STATUS_EBS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Brake.Sig_STATUS_EBS = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Brake.STATUS_EBS = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_F_FRONT_AXLE_TRQ_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Drive_F.Sig_FRONT_AXLE_TRQ = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Drive_F.FRONT_AXLE_TRQ = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_F_FRONT_AXLE_TRQ_MAX_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Drive_F.Sig_FRONT_AXLE_TRQ_MAX = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Drive_F.FRONT_AXLE_TRQ_MAX = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_F_FRONT_AXLE_TRQ_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Drive_F.Sig_FRONT_AXLE_TRQ_REQUEST = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Drive_F.FRONT_AXLE_TRQ_REQUEST = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_R_REAR_AXLE_TRQ_MAX_Nm_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Drive_R.Sig_REAR_AXLE_TRQ_MAX_Nm = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Drive_R.REAR_AXLE_TRQ_MAX_Nm = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_R_REAR_AXLE_TRQ_Nm_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Drive_R.Sig_REAR_AXLE_TRQ_Nm = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Drive_R.REAR_AXLE_TRQ_Nm = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_R_REAR_AXLE_TRQ_REQUEST_Nm_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Drive_R.Sig_REAR_AXLE_TRQ_REQUEST_Nm = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Drive_R.REAR_AXLE_TRQ_REQUEST_Nm = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Wheel_counts_FL_PULSE_COUNT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Wheel_counts.Sig_FL_PULSE_COUNT = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Wheel_counts.FL_PULSE_COUNT = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Wheel_counts_FR_PULSE_COUNT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Wheel_counts.Sig_FR_PULSE_COUNT = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Wheel_counts.FR_PULSE_COUNT = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Wheel_counts_RL_PULSE_COUNT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Wheel_counts.Sig_RL_PULSE_COUNT = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Wheel_counts.RL_PULSE_COUNT = &sig->SigVar->UShort;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Wheel_counts_RR_PULSE_COUNT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2AI_Wheel_counts.Sig_RR_PULSE_COUNT = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2AI_Wheel_counts.RR_PULSE_COUNT = &sig->SigVar->UShort;
    }

    return 0;
}
