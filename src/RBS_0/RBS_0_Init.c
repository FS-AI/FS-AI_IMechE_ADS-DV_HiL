
/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 */

#include "RBS_0.h"

#include <stdlib.h>
#include <string.h>

tRBS_0 RBS_0;

/* ---- User Code - Start ---- */

/* ---- User Code - End   ---- */

/*** Initialization ***/

/*
 * RBS_0_Init_First ()
 *
 * First, low level initialization of the module RBS_0
 * - fill all RBS user data structures with 0
 *
 * call:
 * - called directly after loading the shared library
 *   in RBS_Param_Get()
 * - no realtime conditions
 */
int
RBS_0_Init_First(
    void)
{
    /* Init RBS data structures */
    memset(&RBS_0, 0, sizeof(RBS_0));
    return 0;
}

/*
 * RBS_0_Init ()
 *
 * Initialization
 *
 * call:
 * - called in RBS_Init()
 * - after reading all information from FlexRay-/CAN-/EthParameters Info File
 * - no realtime conditions
 */
void*
RBS_0_Init(
    struct tRBS *rbs)
{
    RBS_GetRBSData(rbs, (tRBS_Data *)&RBS_0.RBS);
    return (void *)&RBS_0;
}

/*
 * RBS_0_Delete ()
 *
 * Deinitialization
 *
 * call:
 * - called before unloading the shared library
 * - no realtime conditions
 */
int
RBS_0_Delete(
    void)
{
    return 0;
}
