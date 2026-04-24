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

#if !defined(__RBS_0_ECU_H__)
#define __RBS_0_ECU_H__

#include <rbs.h>

#ifdef __cplusplus
extern "C" {
#endif

int RBS_0_ECU_AI_Init	(struct tRBS_ECU *ecu);

int RBS_0_ECU_OPUS_Init	(struct tRBS_ECU *ecu);

int RBS_0_ECU_VCU_Init	(struct tRBS_ECU *ecu);

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_ECU_H__) */
