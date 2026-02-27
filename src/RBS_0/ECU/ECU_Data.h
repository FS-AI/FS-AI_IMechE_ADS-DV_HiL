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

#if !defined(__RBS_0_ECU_DATA_H__)
#define __RBS_0_ECU_DATA_H__

#include <rbs.h>
#include "../PDU/PDU_Data.h"

#ifdef __cplusplus
extern "C" {
#endif

tRBS_ECU 	*ECU_OPUS;
tRBS_0_OPUS_PDUs OPUS;
tRBS_ECU 	*ECU_AI;
tRBS_0_AI_PDUs AI;
tRBS_ECU 	*ECU_VCU;
tRBS_0_VCU_PDUs VCU;

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_ECU_DATA_H__) */
