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

#if !defined(__RBS_0_PDU_DATA_H__)
#define __RBS_0_PDU_DATA_H__

#include <rbs.h>
#include "../Signal/Signal_Data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tRBS_0_OPUS_PDUs {
    tRBS_SigPDU 	 *PDU_OPUS2VCU_FB;
    tRBS_0_OPUS_OPUS2VCU_FB_Sigs OPUS2VCU_FB;
} tRBS_0_OPUS_PDUs;
typedef struct tRBS_0_AI_PDUs {
    tRBS_SigPDU 	 *PDU_AI2VCU_Status;
    tRBS_0_AI_AI2VCU_Status_Sigs AI2VCU_Status;
    tRBS_SigPDU 	 *PDU_AI2VCU_Drive_F;
    tRBS_0_AI_AI2VCU_Drive_F_Sigs AI2VCU_Drive_F;
    tRBS_SigPDU 	 *PDU_AI2VCU_Drive_R;
    tRBS_0_AI_AI2VCU_Drive_R_Sigs AI2VCU_Drive_R;
    tRBS_SigPDU 	 *PDU_AI2VCU_Steer;
    tRBS_0_AI_AI2VCU_Steer_Sigs AI2VCU_Steer;
    tRBS_SigPDU 	 *PDU_AI2VCU_Brake;
    tRBS_0_AI_AI2VCU_Brake_Sigs AI2VCU_Brake;
} tRBS_0_AI_PDUs;
typedef struct tRBS_0_VCU_PDUs {
    tRBS_SigPDU 	 *PDU_NMT;
    tRBS_0_VCU_NMT_Sigs NMT;
    tRBS_SigPDU 	 *PDU_VCU2LOG_Dynamics1;
    tRBS_0_VCU_VCU2LOG_Dynamics1_Sigs VCU2LOG_Dynamics1;
    tRBS_SigPDU 	 *PDU_VCU2LOG_Status;
    tRBS_0_VCU_VCU2LOG_Status_Sigs VCU2LOG_Status;
    tRBS_SigPDU 	 *PDU_VCU2AI_Status;
    tRBS_0_VCU_VCU2AI_Status_Sigs VCU2AI_Status;
    tRBS_SigPDU 	 *PDU_VCU2AI_Drive_F;
    tRBS_0_VCU_VCU2AI_Drive_F_Sigs VCU2AI_Drive_F;
    tRBS_SigPDU 	 *PDU_VCU2AI_Drive_R;
    tRBS_0_VCU_VCU2AI_Drive_R_Sigs VCU2AI_Drive_R;
    tRBS_SigPDU 	 *PDU_VCU2AI_Steer;
    tRBS_0_VCU_VCU2AI_Steer_Sigs VCU2AI_Steer;
    tRBS_SigPDU 	 *PDU_VCU2AI_Brake;
    tRBS_0_VCU_VCU2AI_Brake_Sigs VCU2AI_Brake;
    tRBS_SigPDU 	 *PDU_VCU2AI_Speeds;
    tRBS_0_VCU_VCU2AI_Speeds_Sigs VCU2AI_Speeds;
    tRBS_SigPDU 	 *PDU_VCU2AI_Wheel_counts;
    tRBS_0_VCU_VCU2AI_Wheel_counts_Sigs VCU2AI_Wheel_counts;
} tRBS_0_VCU_PDUs;

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_PDU_DATA_H__) */
