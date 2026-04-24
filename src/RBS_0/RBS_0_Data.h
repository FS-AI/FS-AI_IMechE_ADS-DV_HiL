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

#if !defined(__RBS_0_DATA_H__)
#define __RBS_0_DATA_H__

#include <rbs.h>
#include "Signal/Signal_Data.h"
#include "PDU/PDU_Data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tRBS_0 {
    tRBS_Data RBS;
    #include "ECU/ECU_Data.h"
    #include "Frame/Frame_Data.h"
} tRBS_0;

extern tRBS_0 RBS_0;

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_DATA_H__) */
