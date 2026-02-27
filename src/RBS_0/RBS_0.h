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

#if !defined(__RBS_0_H__)
#define __RBS_0_H__

#if defined(RTMAKER)
# include <RTMaker.h>
#else
# include <CarMaker.h>
#endif

#include <rbs.h>
#include <SecOC.h>
#include "RBS_0_Data.h"
#include "ECU/ECU.h"
#include "Frame/Frame.h"
#include "Signal/Signal.h"
#include "PDU/PDU.h"

#ifdef __cplusplus
extern "C" {
#endif

int RBS_0_Init_First	(void);
void* RBS_0_Init	(struct tRBS *rbs);
int RBS_0_Delete	(void);
#if 0
int RBS_0_OutMap	(unsigned CycleNo);
#endif

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_H__) */
