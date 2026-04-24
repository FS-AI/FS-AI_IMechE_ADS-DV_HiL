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

#if !defined(__RBS_0_FRAME_DATA_H__)
#define __RBS_0_FRAME_DATA_H__

#include <rbs.h>

#ifdef __cplusplus
extern "C" {
#endif

tRBS_SigFrame 		*Frame_Rx_AI2VCU_Status;
tRBS_SigFrame 		*Frame_Rx_AI2VCU_Steer;
tRBS_SigFrame 		*Frame_Rx_AI2VCU_Brake;
tRBS_SigFrame 		*Frame_Rx_AI2VCU_Drive_F;
tRBS_SigFrame 		*Frame_Rx_AI2VCU_Drive_R;
tRBS_SigFrame 		*Frame_Rx_OPUS2VCU_FB;
tRBS_SigFrame 		*Frame_Tx_VCU2OPUS_3;
tRBS_SigFrame 		*Frame_Tx_VCU2OPUS_2;
tRBS_SigFrame 		*Frame_Tx_VCU2OPUS_1;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Status;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Steer;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Speeds;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Brake;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Drive_F;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Drive_R;
tRBS_SigFrame 		*Frame_Tx_VCU2AI_Wheel_counts;

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_FRAME_DATA_H__) */
