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

#if !defined(__RBS_0_PDU_H__)
#define __RBS_0_PDU_H__

#include <rbs.h>

#ifdef __cplusplus
extern "C" {
#endif

int RBS_0_OPUS_OPUS2VCU_FB_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_AI_AI2VCU_Status_Init	(struct tRBS_SigPDU *pdu);
int RBS_0_AI_AI2VCU_Status_PreDecode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);
int RBS_0_AI_AI2VCU_Status_PostDecode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);
int RBS_0_AI_AI2VCU_Status_PostMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);

int RBS_0_AI_AI2VCU_Drive_F_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_AI_AI2VCU_Drive_R_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_AI_AI2VCU_Steer_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_AI_AI2VCU_Brake_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_NMT_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2LOG_Dynamics1_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2LOG_Status_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Status_Init	(struct tRBS_SigPDU *pdu);
int RBS_0_VCU_VCU2AI_Status_PreEncode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);
int RBS_0_VCU_VCU2AI_Status_PostEncode	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);
int RBS_0_VCU_VCU2AI_Status_PreMapping	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);
int RBS_0_VCU_VCU2AI_Status_CRC	(struct tRBS_SigFrame *frm, struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Drive_F_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Drive_R_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Steer_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Brake_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Speeds_Init	(struct tRBS_SigPDU *pdu);

int RBS_0_VCU_VCU2AI_Wheel_counts_Init	(struct tRBS_SigPDU *pdu);

#ifdef __cplusplus
}
#endif

#endif /* #if !defined(__RBS_0_PDU_H__) */
