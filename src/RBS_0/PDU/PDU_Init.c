
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
RBS_0_AI_AI2VCU_Status_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL)
	return -1;

    RBS_0.AI.PDU_AI2VCU_Status = pdu;
    return 0;

}

int
RBS_0_AI_AI2VCU_Steer_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.AI.PDU_AI2VCU_Steer = pdu;
    return 0;
}

int
RBS_0_AI_AI2VCU_Brake_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.AI.PDU_AI2VCU_Brake = pdu;
    return 0;
}

int
RBS_0_AI_AI2VCU_Drive_F_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.AI.PDU_AI2VCU_Drive_F = pdu;
    return 0;
}

int
RBS_0_AI_AI2VCU_Drive_R_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.AI.PDU_AI2VCU_Drive_R = pdu;
    return 0;
}

int
RBS_0_OPUS_OPUS2VCU_FB_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL)
	return -1;

    RBS_0.OPUS.PDU_OPUS2VCU_FB = pdu;
    return 0;

}

int
RBS_0_VCU_VCU2OPUS_3_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2OPUS_3 = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2OPUS_2_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2OPUS_2 = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2OPUS_1_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2OPUS_1 = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2AI_Status_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL)
	return -1;

    RBS_0.VCU.PDU_VCU2AI_Status = pdu;
    return 0;

}

int
RBS_0_VCU_VCU2AI_Steer_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2AI_Steer = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2AI_Speeds_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2AI_Speeds = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2AI_Brake_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2AI_Brake = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_F_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2AI_Drive_F = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2AI_Drive_R_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2AI_Drive_R = pdu;
    return 0;
}

int
RBS_0_VCU_VCU2AI_Wheel_counts_Init(
    struct tRBS_SigPDU *pdu)
{
    if (pdu == NULL) {
        return -1;
    }

    RBS_0.VCU.PDU_VCU2AI_Wheel_counts = pdu;
    return 0;
}
