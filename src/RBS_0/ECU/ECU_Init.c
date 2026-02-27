
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
RBS_0_ECU_OPUS_Init(
    struct tRBS_ECU *ecu)
{
    if (ecu == NULL)
	return -1;

    RBS_0.ECU_OPUS = ecu;

    return 0;
}

int
RBS_0_ECU_AI_Init(
    struct tRBS_ECU *ecu)
{
    if (ecu == NULL)
	return -1;

    RBS_0.ECU_AI = ecu;

    return 0;
}

int
RBS_0_ECU_VCU_Init(
    struct tRBS_ECU *ecu)
{
    if (ecu == NULL)
	return -1;

    RBS_0.ECU_VCU = ecu;

    return 0;
}
