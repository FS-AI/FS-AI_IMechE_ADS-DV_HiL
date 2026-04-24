
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
RBS_0_Rx_AI2VCU_Status_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL)
	return -1;

    RBS_0.Frame_Rx_AI2VCU_Status = frm;

    return 0;
}

int
RBS_0_Rx_AI2VCU_Steer_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Rx_AI2VCU_Steer = frm;

    return 0;
}

int
RBS_0_Rx_AI2VCU_Brake_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Rx_AI2VCU_Brake = frm;

    return 0;
}

int
RBS_0_Rx_AI2VCU_Drive_F_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Rx_AI2VCU_Drive_F = frm;

    return 0;
}

int
RBS_0_Rx_AI2VCU_Drive_R_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Rx_AI2VCU_Drive_R = frm;

    return 0;
}

int
RBS_0_Rx_OPUS2VCU_FB_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL)
	return -1;

    RBS_0.Frame_Rx_OPUS2VCU_FB = frm;

    return 0;
}

int
RBS_0_Tx_VCU2OPUS_3_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2OPUS_3 = frm;

    return 0;
}

int
RBS_0_Tx_VCU2OPUS_2_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2OPUS_2 = frm;

    return 0;
}

int
RBS_0_Tx_VCU2OPUS_1_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2OPUS_1 = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Status_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL)
	return -1;

    RBS_0.Frame_Tx_VCU2AI_Status = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Steer_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2AI_Steer = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Speeds_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2AI_Speeds = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Brake_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2AI_Brake = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Drive_F_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2AI_Drive_F = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Drive_R_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2AI_Drive_R = frm;

    return 0;
}

int
RBS_0_Tx_VCU2AI_Wheel_counts_Init(
    struct tRBS_SigFrame *frm)
{
    if (frm == NULL) {
        return -1;
    }

    RBS_0.Frame_Tx_VCU2AI_Wheel_counts = frm;

    return 0;
}
