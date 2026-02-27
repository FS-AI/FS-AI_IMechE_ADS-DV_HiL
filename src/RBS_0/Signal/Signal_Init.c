
/*
 *****************************************************************************
 *  CarMaker - Version 14.0.1
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
RBS_0_AI_AI2VCU_Status_CONES_COUNT_ACTUAL_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_CONES_COUNT_ACTUAL = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.CONES_COUNT_ACTUAL = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_AI_AI2VCU_Status_CONES_COUNT_ALL_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_CONES_COUNT_ALL = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.CONES_COUNT_ALL = &sig->SigVar->UShort;

    return 0;
}

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
RBS_0_AI_AI2VCU_Status_LAP_COUNTER_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_LAP_COUNTER = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.LAP_COUNTER = &sig->SigVar->UChar;

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
RBS_0_AI_AI2VCU_Status_VEH_SPEED_ACTUAL_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_VEH_SPEED_ACTUAL = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.VEH_SPEED_ACTUAL = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_AI_AI2VCU_Status_VEH_SPEED_DEMAND_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.AI.AI2VCU_Status.Sig_VEH_SPEED_DEMAND = sig;

    if (sig->SigVar != NULL)
    	RBS_0.AI.AI2VCU_Status.VEH_SPEED_DEMAND = &sig->SigVar->UChar;

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
RBS_0_VCU_NMT_CMD_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.NMT.Sig_CMD = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.NMT.CMD = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_NMT_NODE_ID_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.NMT.Sig_NODE_ID = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.NMT.NODE_ID = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Brake_actual_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Brake_actual_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Brake_actual_pct = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Brake_target_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Brake_target_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Brake_target_pct = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Drive_trq_actual_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Drive_trq_actual_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Drive_trq_actual_pct = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Drive_trq_target_pct_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Drive_trq_target_pct = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Drive_trq_target_pct = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Speed_actual_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Speed_actual = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Speed_actual = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Speed_target_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Speed_target = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Speed_target = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Steer_actual_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Steer_actual = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Steer_actual = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Dynamics1_Steer_target_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Dynamics1.Sig_Steer_target = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Dynamics1.Steer_target = &sig->SigVar->Double;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_AMI_STATE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_AMI_STATE = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.AMI_STATE = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_Cones_count_actual_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_Cones_count_actual = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.Cones_count_actual = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_Cones_count_all_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_Cones_count_all = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.Cones_count_all = &sig->SigVar->UInt;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_Lap_counter_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_Lap_counter = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.Lap_counter = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_State_ASSI_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_State_ASSI = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.State_ASSI = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_State_EBS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_State_EBS = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.State_EBS = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_State_service_brake_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_State_service_brake = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.State_service_brake = &sig->SigVar->UChar;
    }

    return 0;
}

int
RBS_0_VCU_VCU2LOG_Status_State_steering_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL) {
        return -1;
    }

    RBS_0.VCU.VCU2LOG_Status.Sig_State_steering = sig;

    if (sig->SigVar != NULL) {
        RBS_0.VCU.VCU2LOG_Status.State_steering = &sig->SigVar->Char;
    }

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_AI_COMMS_LOST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_AI_COMMS_LOST = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.AI_COMMS_LOST = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_AI_ESTOP_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_AI_ESTOP_REQUEST = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.AI_ESTOP_REQUEST = &sig->SigVar->UChar;

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
RBS_0_VCU_VCU2AI_Status_AUTONOMOUS_BRAKING_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_AUTONOMOUS_BRAKING_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.AUTONOMOUS_BRAKING_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_BMS_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_BMS_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.BMS_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_BRAKE_PLAUSIBILITY_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_BRAKE_PLAUSIBILITY_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.BRAKE_PLAUSIBILITY_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_CHARGE_PROCEDURE_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_CHARGE_PROCEDURE_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.CHARGE_PROCEDURE_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_EBS_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_EBS_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.EBS_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_FAULT_STATUS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_FAULT_STATUS = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.FAULT_STATUS = &sig->SigVar->UChar;

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
RBS_0_VCU_VCU2AI_Status_HVIL_SHORT_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_HVIL_SHORT_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.HVIL_SHORT_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_MISSION_STATUS_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_MISSION_STATUS_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.MISSION_STATUS_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_OFFBOARD_CHARGER_FAULT_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_OFFBOARD_CHARGER_FAULT = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.OFFBOARD_CHARGER_FAULT = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_SHUTDOWN_CAUSE_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_SHUTDOWN_CAUSE = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.SHUTDOWN_CAUSE = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_SHUTDOWN_REQUEST_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_SHUTDOWN_REQUEST = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.SHUTDOWN_REQUEST = &sig->SigVar->UChar;

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
RBS_0_VCU_VCU2AI_Status_WARN_BATT_SOC_LOW_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_WARN_BATT_SOC_LOW = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.WARN_BATT_SOC_LOW = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_WARN_BATT_TEMP_HIGH_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_WARN_BATT_TEMP_HIGH = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.WARN_BATT_TEMP_HIGH = &sig->SigVar->UChar;

    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_WARNING_STATUS_Init(
    struct tRBS_Signal *sig)
{
    if (sig == NULL)
	return -1;

    RBS_0.VCU.VCU2AI_Status.Sig_WARNING_STATUS = sig;

    if (sig->SigVar != NULL)
    	RBS_0.VCU.VCU2AI_Status.WARNING_STATUS = &sig->SigVar->UChar;

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
