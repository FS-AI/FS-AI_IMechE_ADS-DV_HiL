/*
 * File: FSAI_VehicleModel.c
 *
 * Code generated for Simulink model 'FSAI_VehicleModel'.
 *
 * Model version                  : 5.89
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jul  5 16:50:25 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "../Include/FSAI_VehicleModel.h"
#include "../Include/rtwtypes.h"
#include <math.h>
#include "../../mock_io/messages.h"

static real_T look1_iftd_binlc(real32_T u0, const real32_T bp0[], const real_T
  table[], uint32_T maxIndex);
static uint32_T plook_u32f_bincka(real32_T u, const real32_T bp[], uint32_T
  maxIndex);
static uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
static void MotorModel_f_Init(DW_MotorModel_f *localDW);
static void MotorModel_f(real32_T rtu_RequestedMotorSpeed_RPM, real32_T
  rtu_MaxAxleTorqueDemand, real32_T rtu_BeltDriveGearRatio, real32_T
  rtu_CurrentMotorSpeed_RPM, boolean_T rtu_BrakesActive, real32_T
  *rty_MotorOutputTorque_Nm, real_T *rty_MotorOutputTorqueMax_Nm,
  DW_MotorModel_f *localDW);
static void rate_scheduler(RT_MODEL *const rtM);
const vcu2ai_data_t FSAI_VehicleModel_rtZvcu2ai_dat = { {
    HANDSHAKE_RECEIVE_BIT_OFF,         /* handshake */
    0U,                                /* shutdown_request */
    OFF,                               /* as_switch_status */
    OFF,                               /* ts_switch_status */
    RES_GO_SIGNAL_NO_GO,               /* go_signal */
    0U,                                /* steering_status */
    AS_OFF,                            /* as_state */
    AMI_NOT_SELECTED,                  /* ami_state */
    0U,                                /* fault_status */
    0U,                                /* warning_status */
    0U,                                /* warn_batt_temp_high */
    0U,                                /* warn_batt_soc_low */
    0U,                                /* ai_estop_request */
    0U,                                /* hvil_open_fault */
    0U,                                /* hvil_short_fault */
    0U,                                /* ebs_fault */
    0U,                                /* offboard_charger_fault */
    0U,                                /* ai_comms_lost */
    0U,                                /* autonomous_braking_fault */
    0U,                                /* mission_status_fault */
    0U,                                /* charge_procedure_fault */
    0U,                                /* bms_fault */
    0U,                                /* brake_plausibility_fault */
    0U                                 /* shutdown_cause */
  },                                   /* vcu_status */

  { 0.0F,                              /* hyd_press_f_pct */
    0.0F,                              /* hyd_press_f_req_pct */
    0.0F,                              /* hyd_press_r_pct */
    0.0F,                              /* hyd_press_r_req_pct */
    0U,                                /* status_brk */
    0U                                 /* status_ebs */
  },                                   /* vcu_brake */

  { 0.0F,                              /* front_axle_trq */
    0.0F,                              /* front_axle_trq_request */
    0.0F                               /* front_axle_trq_max */
  },                                   /* vcu_drive_f */

  { 0.0F,                              /* rear_axle_trq */
    0.0F,                              /* rear_axle_trq_request */
    0.0F                               /* rear_axle_trq_max */
  },                                   /* vcu_drive_r */

  { 0U,                                /* fl_wheel_speed */
    0U,                                /* fr_wheel_speed */
    0U,                                /* rl_wheel_speed */
    0U                                 /* rr_wheel_speed */
  },                                   /* vcu_speeds */

  { 0.0F,                              /* angle */
    0.0F,                              /* angle_max */
    0.0F                               /* angle_request */
  },                                   /* vcu_steer */

  { 0U,                                /* fl_pulse_count */
    0U,                                /* fr_pulse_count */
    0U,                                /* rl_pulse_count */
    0U                                 /* rr_pulse_count */
  }                                    /* vcu_wheel_counts */
};

static real_T look1_iftd_binlc(real32_T u0, const real32_T bp0[], const real_T
  table[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

static uint32_T plook_u32f_bincka(real32_T u, const real32_T bp[], uint32_T
  maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

static uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(RT_MODEL *const rtM)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S2>/MotorModel_f'
 *    '<S2>/MotorModel_fr'
 */
static void MotorModel_f_Init(DW_MotorModel_f *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S51>/Integrator' */
  localDW->Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Filter' */
  localDW->Filter_PrevResetState = 0;

  /* InitializeConditions for RateLimiter: '<S8>/Rate Limiter' */
  localDW->PrevY = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S2>/MotorModel_f'
 *    '<S2>/MotorModel_fr'
 */
static void MotorModel_f(real32_T rtu_RequestedMotorSpeed_RPM, real32_T
  rtu_MaxAxleTorqueDemand, real32_T rtu_BeltDriveGearRatio, real32_T
  rtu_CurrentMotorSpeed_RPM, boolean_T rtu_BrakesActive, real32_T
  *rty_MotorOutputTorque_Nm, real_T *rty_MotorOutputTorqueMax_Nm,
  DW_MotorModel_f *localDW)
{
  real32_T rtb_Diff;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_Sum;

  /* MinMax: '<S8>/Min1' incorporates:
   *  Lookup_n-D: '<S8>/MotorTorqueModel'
   *  Lookup_n-D: '<S8>/TorqueLimit'
   */
  *rty_MotorOutputTorqueMax_Nm = fmin(rtConstP.pooled1[plook_u32f_bincka
    (rtu_CurrentMotorSpeed_RPM, rtConstP.pooled9, 8U)], look1_iftd_binlc
    (rtu_CurrentMotorSpeed_RPM, rtConstP.pooled10, rtConstP.pooled2, 4U));

  /* MinMax: '<S8>/Min' incorporates:
   *  Product: '<S8>/Divide'
   */
  rtb_Diff = (real32_T)fmin(rtu_MaxAxleTorqueDemand / rtu_BeltDriveGearRatio,
    *rty_MotorOutputTorqueMax_Nm);

  /* DiscreteIntegrator: '<S51>/Integrator' */
  if (rtu_BrakesActive || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S46>/Filter' */
  if (rtu_BrakesActive || (localDW->Filter_PrevResetState != 0)) {
    localDW->Filter_DSTATE = 0.0F;
  }

  /* Gain: '<S54>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S46>/Filter'
   *  Gain: '<S45>/Derivative Gain'
   *  Sum: '<S46>/SumD'
   */
  rtb_FilterCoefficient = (0.0F - localDW->Filter_DSTATE) * 100.0F;

  /* Sum: '<S61>/Sum' incorporates:
   *  DiscreteIntegrator: '<S51>/Integrator'
   *  Gain: '<S56>/Proportional Gain'
   *  Sum: '<S8>/Subtract'
   */
  rtb_Sum = ((rtu_RequestedMotorSpeed_RPM - rtu_CurrentMotorSpeed_RPM) * 0.0285F
             + localDW->Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Switch: '<S59>/Switch2' incorporates:
   *  Gain: '<S8>/Gain'
   *  RelationalOperator: '<S59>/LowerRelop1'
   *  RelationalOperator: '<S59>/UpperRelop'
   *  Switch: '<S59>/Switch'
   */
  if (rtb_Sum > rtb_Diff) {
    rtb_Sum = rtb_Diff;
  } else if (rtb_Sum < -rtb_Diff) {
    /* Switch: '<S59>/Switch' incorporates:
     *  Gain: '<S8>/Gain'
     */
    rtb_Sum = -rtb_Diff;
  }

  /* End of Switch: '<S59>/Switch2' */

  /* RateLimiter: '<S8>/Rate Limiter' */
  rtb_Diff = rtb_Sum - localDW->PrevY;
  if (rtb_Diff > 50.0F) {
    *rty_MotorOutputTorque_Nm = localDW->PrevY + 50.0F;
  } else if (rtb_Diff < -50.0F) {
    *rty_MotorOutputTorque_Nm = localDW->PrevY - 50.0F;
  } else {
    *rty_MotorOutputTorque_Nm = rtb_Sum;
  }

  localDW->PrevY = *rty_MotorOutputTorque_Nm;

  /* End of RateLimiter: '<S8>/Rate Limiter' */

  /* Update for DiscreteIntegrator: '<S51>/Integrator' */
  localDW->Integrator_PrevResetState = (int8_T)rtu_BrakesActive;

  /* Update for DiscreteIntegrator: '<S46>/Filter' incorporates:
   *  DiscreteIntegrator: '<S51>/Integrator'
   */
  localDW->Filter_DSTATE += 0.1F * rtb_FilterCoefficient;
  localDW->Filter_PrevResetState = (int8_T)rtu_BrakesActive;
}

/* Model step function */
void FSAI_VehicleModel_step(RT_MODEL *const rtM, ai2vcu_data_t *rtU_ai2vcu_data,
  uint8_T rtU_VehicleOperatingConditon, real32_T rtU_WheelRadius_m,
  vcu2ai_data_t *rtU_vcu2ai_data_init, real32_T rtU_ActualWheelspeedFL_mps,
  real32_T rtU_ActualWheelspeedFR_mps, real32_T rtU_ActualWheelspeedRL_mps,
  real32_T rtU_ActualWheelspeedRR_mps, vcu2ai_data_t *rtY_vcu2ai_data_outport)
{
  DW *rtDW = rtM->dwork;
  real_T rtb_MaxTorqueNm;
  real_T rtb_MaxTorqueNm_f1;
  real_T rtb_MultiportSwitch;
  int32_T Delay2_DSTATE_tmp;
  int32_T Delay2_DSTATE_tmp_0;
  int32_T idxDelay;
  int32_T rtb_DataTypeConversion;
  int32_T rtb_DataTypeConversion_e;
  int32_T rtb_DataTypeConversion_l;
  real32_T rtb_DiscreteTimeIntegrator_do;
  real32_T rtb_DiscreteTimeIntegrator_p;
  real32_T rtb_Product2_idx_1;
  real32_T rtb_RateLimiter_e;
  real32_T rtb_RateLimiter_m;
  real32_T rtb_RateLimiter_p_0;
  real32_T rtb_WheelRotationRate_rps_c;
  real32_T rtb_WheelRotationRate_rps_f;
  real32_T rtb_WheelRotationRate_rps_l;
  real32_T rtb_WheelRotationRate_rps_p;
  boolean_T rtb_Compare;

  /* RateTransition: '<S2>/Rate Transition11' incorporates:
   *  Constant: '<S2>/BELT_DRIVE_RATIO'
   *  Constant: '<S7>/Constant'
   *  Gain: '<S10>/CalcWheelCircumference_m'
   *  Gain: '<S10>/rps_2_rpm'
   *  Gain: '<S11>/CalcWheelCircumference_m'
   *  Gain: '<S11>/rps_2_rpm'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  Inport: '<Root>/ActualWheelspeedFL_mps'
   *  Inport: '<Root>/ActualWheelspeedFR_mps'
   *  Inport: '<Root>/ActualWheelspeedRL_mps'
   *  Inport: '<Root>/ActualWheelspeedRR_mps'
   *  Inport: '<Root>/WheelRadius_[m]'
   *  Inport: '<Root>/ai2vcu_data'
   *  Product: '<S10>/Divide1'
   *  Product: '<S10>/Product'
   *  Product: '<S11>/Divide1'
   *  Product: '<S11>/Product'
   *  RateTransition: '<S2>/Rate Transition10'
   *  RateTransition: '<S2>/Rate Transition9'
   *  RelationalOperator: '<S7>/Compare'
   *  Saturate: '<S2>/Saturation'
   *  Saturate: '<S2>/Saturation1'
   *  Saturate: '<S2>/Saturation2'
   *  Saturate: '<S2>/Saturation3'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Add1'
   */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<S2>/Saturation' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  Inport: '<Root>/ai2vcu_data'
     */
    if (rtU_ai2vcu_data->ai_drive_f.front_motor_speed_max > 4000) {
      idxDelay = 4000;
    } else if (rtU_ai2vcu_data->ai_drive_f.front_motor_speed_max < 0) {
      idxDelay = 0;
    } else {
      idxDelay = rtU_ai2vcu_data->ai_drive_f.front_motor_speed_max;
    }

    /* Saturate: '<S2>/Saturation2' incorporates:
     *  Inport: '<Root>/ai2vcu_data'
     */
    if (rtU_ai2vcu_data->ai_drive_f.front_axle_trq_request > 195.0F) {
      rtb_Product2_idx_1 = 195.0F;
    } else if (rtU_ai2vcu_data->ai_drive_f.front_axle_trq_request < 0.0F) {
      rtb_Product2_idx_1 = 0.0F;
    } else {
      rtb_Product2_idx_1 = rtU_ai2vcu_data->ai_drive_f.front_axle_trq_request;
    }

    /* Outputs for Atomic SubSystem: '<S2>/MotorModel_f' */
    MotorModel_f((real32_T)idxDelay, rtb_Product2_idx_1, 3.5F, 60.0F * (0.5F *
      (rtU_ActualWheelspeedFL_mps + rtU_ActualWheelspeedFR_mps) / (6.28318548F *
      rtU_WheelRadius_m)) * 3.5F, (rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct
      <= 0.0F), &rtb_RateLimiter_e, &rtb_MaxTorqueNm_f1, &rtDW->MotorModel_f_a);

    /* End of Outputs for SubSystem: '<S2>/MotorModel_f' */

    /* Saturate: '<S2>/Saturation1' incorporates:
     *  Constant: '<S2>/BELT_DRIVE_RATIO'
     *  Constant: '<S7>/Constant'
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  Gain: '<S10>/CalcWheelCircumference_m'
     *  Gain: '<S10>/rps_2_rpm'
     *  Gain: '<S2>/Gain2'
     *  Inport: '<Root>/ActualWheelspeedFL_mps'
     *  Inport: '<Root>/ActualWheelspeedFR_mps'
     *  Inport: '<Root>/WheelRadius_[m]'
     *  Inport: '<Root>/ai2vcu_data'
     *  Product: '<S10>/Divide1'
     *  Product: '<S10>/Product'
     *  RelationalOperator: '<S7>/Compare'
     *  Saturate: '<S2>/Saturation'
     *  Saturate: '<S2>/Saturation2'
     *  Sum: '<S2>/Add'
     */
    if (rtU_ai2vcu_data->ai_drive_r.rear_motor_speed_max > 4000) {
      idxDelay = 4000;
    } else if (rtU_ai2vcu_data->ai_drive_r.rear_motor_speed_max < 0) {
      idxDelay = 0;
    } else {
      idxDelay = rtU_ai2vcu_data->ai_drive_r.rear_motor_speed_max;
    }

    /* Saturate: '<S2>/Saturation3' incorporates:
     *  Inport: '<Root>/ai2vcu_data'
     */
    if (rtU_ai2vcu_data->ai_drive_r.rear_axle_trq_request > 195.0F) {
      rtb_Product2_idx_1 = 195.0F;
    } else if (rtU_ai2vcu_data->ai_drive_r.rear_axle_trq_request < 0.0F) {
      rtb_Product2_idx_1 = 0.0F;
    } else {
      rtb_Product2_idx_1 = rtU_ai2vcu_data->ai_drive_r.rear_axle_trq_request;
    }

    /* Outputs for Atomic SubSystem: '<S2>/MotorModel_fr' */
    MotorModel_f((real32_T)idxDelay, rtb_Product2_idx_1, 3.5F, 60.0F * (0.5F *
      (rtU_ActualWheelspeedRL_mps + rtU_ActualWheelspeedRR_mps) / (6.28318548F *
      rtU_WheelRadius_m)) * 3.5F, (rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct
      <= 0.0F), &rtb_RateLimiter_m, &rtb_MaxTorqueNm, &rtDW->MotorModel_fr);

    /* End of Outputs for SubSystem: '<S2>/MotorModel_fr' */

    /* RateTransition: '<S2>/Rate Transition8' incorporates:
     *  Constant: '<S2>/BELT_DRIVE_RATIO'
     *  Constant: '<S7>/Constant'
     *  Gain: '<S11>/CalcWheelCircumference_m'
     *  Gain: '<S11>/rps_2_rpm'
     *  Gain: '<S2>/Gain3'
     *  Inport: '<Root>/ActualWheelspeedRL_mps'
     *  Inport: '<Root>/ActualWheelspeedRR_mps'
     *  Inport: '<Root>/WheelRadius_[m]'
     *  Inport: '<Root>/ai2vcu_data'
     *  Product: '<S11>/Divide1'
     *  Product: '<S11>/Product'
     *  RelationalOperator: '<S7>/Compare'
     *  Saturate: '<S2>/Saturation1'
     *  Saturate: '<S2>/Saturation3'
     *  Sum: '<S2>/Add1'
     */
    rtDW->RateTransition8 = rtDW->RateTransition8_Buffer0;

    /* RateTransition: '<S2>/Rate Transition11' */
    rtDW->RateTransition11 = rtDW->RateTransition11_Buffer0;

    /* RateTransition: '<S2>/Rate Transition9' */
    rtDW->RateTransition9 = rtDW->RateTransition9_Buffer0;

    /* RateTransition: '<S2>/Rate Transition10' */
    rtDW->RateTransition10 = rtDW->RateTransition10_Buffer0;
  }

  /* End of RateTransition: '<S2>/Rate Transition11' */

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S2>/BELT_DRIVE_RATIO'
   *  Gain: '<S2>/Gain'
   *  Inport: '<Root>/ai2vcu_data'
   *  Product: '<S2>/Product'
   */
  rtY_vcu2ai_data_outport->vcu_drive_f.front_axle_trq = rtDW->RateTransition8 *
    3.5F;
  rtY_vcu2ai_data_outport->vcu_drive_f.front_axle_trq_request =
    rtU_ai2vcu_data->ai_drive_f.front_axle_trq_request;
  rtY_vcu2ai_data_outport->vcu_drive_f.front_axle_trq_max = (real32_T)(3.5 *
    rtDW->RateTransition11);

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Inport: '<Root>/vcu2ai_data_input'
   */
  rtY_vcu2ai_data_outport->vcu_status = rtU_vcu2ai_data_init->vcu_status;

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Delay: '<S2>/Delay2'
   *  Inport: '<Root>/ai2vcu_data'
   *  Inport: '<Root>/vcu2ai_data_input'
   */
  rtY_vcu2ai_data_outport->vcu_brake.hyd_press_f_pct = rtDW->Delay2_DSTATE[0];
  rtY_vcu2ai_data_outport->vcu_brake.hyd_press_f_req_pct =
    rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct;
  rtY_vcu2ai_data_outport->vcu_brake.hyd_press_r_pct = rtDW->Delay2_DSTATE[1];
  rtY_vcu2ai_data_outport->vcu_brake.hyd_press_r_req_pct =
    rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct;
  rtY_vcu2ai_data_outport->vcu_brake.status_brk =
    rtU_vcu2ai_data_init->vcu_brake.status_brk;
  rtY_vcu2ai_data_outport->vcu_brake.status_ebs =
    rtU_vcu2ai_data_init->vcu_brake.status_ebs;

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S2>/BELT_DRIVE_RATIO'
   *  Gain: '<S2>/Gain1'
   *  Inport: '<Root>/ai2vcu_data'
   *  Product: '<S2>/Product1'
   */
  rtY_vcu2ai_data_outport->vcu_drive_r.rear_axle_trq = rtDW->RateTransition9 *
    3.5F;
  rtY_vcu2ai_data_outport->vcu_drive_r.rear_axle_trq_request =
    rtU_ai2vcu_data->ai_drive_r.rear_axle_trq_request;
  rtY_vcu2ai_data_outport->vcu_drive_r.rear_axle_trq_max = (real32_T)(3.5 *
    rtDW->RateTransition10);

  /* Product: '<S3>/Divide3' incorporates:
   *  Gain: '<S3>/CalcWheelCircumference_m1'
   *  Inport: '<Root>/ActualWheelspeedFL_mps'
   *  Inport: '<Root>/WheelRadius_[m]'
   */
  rtb_WheelRotationRate_rps_p = rtU_ActualWheelspeedFL_mps / (6.28318548F *
    rtU_WheelRadius_m);

  /* Gain: '<S3>/Gain' */
  rtb_DiscreteTimeIntegrator_do = 60.0F * rtb_WheelRotationRate_rps_p;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   */
  rtb_DataTypeConversion = (rtb_DiscreteTimeIntegrator_do <= 1.0F);

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   */
  if ((rtb_DiscreteTimeIntegrator_do > 1.0F) &&
      (rtDW->DiscreteTimeIntegrator1_PrevRes == 1)) {
    rtDW->DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  if (rtDW->DiscreteTimeIntegrator1_DSTATE == 1.0F) {
    idxDelay = 1;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTATE == -100.0F) {
    idxDelay = -1;
  } else {
    idxDelay = 0;
  }

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_do > 1143.0F) {
    rtb_DiscreteTimeIntegrator_do = 1143.0F;
  } else if (rtb_DiscreteTimeIntegrator_do < 9.0F) {
    rtb_DiscreteTimeIntegrator_do = 9.0F;
  }

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   *  Product: '<S3>/Product'
   *  Saturate: '<S3>/Saturation1'
   *  Sum: '<S3>/Sum'
   */
  rtY_vcu2ai_data_outport->vcu_speeds.fl_wheel_speed = (uint16_T)(real32_T)((1.0
    - (real_T)idxDelay) * rtb_DiscreteTimeIntegrator_do);

  /* Product: '<S4>/Divide3' incorporates:
   *  Gain: '<S4>/CalcWheelCircumference_m1'
   *  Inport: '<Root>/ActualWheelspeedFR_mps'
   *  Inport: '<Root>/WheelRadius_[m]'
   */
  rtb_WheelRotationRate_rps_c = rtU_ActualWheelspeedFR_mps / (6.28318548F *
    rtU_WheelRadius_m);

  /* Gain: '<S4>/Gain' */
  rtb_DiscreteTimeIntegrator_do = 60.0F * rtb_WheelRotationRate_rps_c;

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S13>/Compare'
   */
  rtb_DataTypeConversion_e = (rtb_DiscreteTimeIntegrator_do <= 1.0F);

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S13>/Compare'
   */
  if ((rtb_DiscreteTimeIntegrator_do > 1.0F) &&
      (rtDW->DiscreteTimeIntegrator1_PrevR_p == 1)) {
    rtDW->DiscreteTimeIntegrator1_DSTAT_o = 0.0F;
  }

  if (rtDW->DiscreteTimeIntegrator1_DSTAT_o == 1.0F) {
    idxDelay = 1;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTAT_o == -100.0F) {
    idxDelay = -1;
  } else {
    idxDelay = 0;
  }

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_do > 1143.0F) {
    rtb_DiscreteTimeIntegrator_do = 1143.0F;
  } else if (rtb_DiscreteTimeIntegrator_do < 9.0F) {
    rtb_DiscreteTimeIntegrator_do = 9.0F;
  }

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   *  Product: '<S4>/Product'
   *  Saturate: '<S4>/Saturation1'
   *  Sum: '<S4>/Sum'
   */
  rtY_vcu2ai_data_outport->vcu_speeds.fr_wheel_speed = (uint16_T)(real32_T)((1.0
    - (real_T)idxDelay) * rtb_DiscreteTimeIntegrator_do);

  /* Product: '<S5>/Divide3' incorporates:
   *  Gain: '<S5>/CalcWheelCircumference_m1'
   *  Inport: '<Root>/ActualWheelspeedRL_mps'
   *  Inport: '<Root>/WheelRadius_[m]'
   */
  rtb_WheelRotationRate_rps_f = rtU_ActualWheelspeedRL_mps / (6.28318548F *
    rtU_WheelRadius_m);

  /* Gain: '<S5>/Gain' */
  rtb_DiscreteTimeIntegrator_do = 60.0F * rtb_WheelRotationRate_rps_f;

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S14>/Compare'
   */
  rtb_DataTypeConversion_l = (rtb_DiscreteTimeIntegrator_do <= 1.0F);

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S14>/Compare'
   */
  if ((rtb_DiscreteTimeIntegrator_do > 1.0F) &&
      (rtDW->DiscreteTimeIntegrator1_PrevR_n == 1)) {
    rtDW->DiscreteTimeIntegrator1_DSTA_o0 = 0.0F;
  }

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_do > 1143.0F) {
    rtb_DiscreteTimeIntegrator_p = 1143.0F;
  } else if (rtb_DiscreteTimeIntegrator_do < 9.0F) {
    rtb_DiscreteTimeIntegrator_p = 9.0F;
  } else {
    rtb_DiscreteTimeIntegrator_p = rtb_DiscreteTimeIntegrator_do;
  }

  /* End of Saturate: '<S5>/Saturation1' */

  /* Product: '<S6>/Divide3' incorporates:
   *  Gain: '<S6>/CalcWheelCircumference_m1'
   *  Inport: '<Root>/ActualWheelspeedRR_mps'
   *  Inport: '<Root>/WheelRadius_[m]'
   */
  rtb_WheelRotationRate_rps_l = rtU_ActualWheelspeedRR_mps / (6.28318548F *
    rtU_WheelRadius_m);

  /* Gain: '<S6>/Gain' */
  rtb_DiscreteTimeIntegrator_do = 60.0F * rtb_WheelRotationRate_rps_l;

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Compare = (rtb_DiscreteTimeIntegrator_do <= 1.0F);

  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  if ((!rtb_Compare) && (rtDW->DiscreteTimeIntegrator1_PrevR_o == 1)) {
    rtDW->DiscreteTimeIntegrator1_DSTAT_a = 0.0F;
  }

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  if (rtDW->DiscreteTimeIntegrator1_DSTA_o0 == 1.0F) {
    idxDelay = 1;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTA_o0 == -100.0F) {
    idxDelay = -1;
  } else {
    idxDelay = 0;
  }

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion13'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Product: '<S5>/Product'
   *  Sum: '<S5>/Sum'
   */
  rtY_vcu2ai_data_outport->vcu_speeds.rl_wheel_speed = (uint16_T)(real32_T)((1.0
    - (real_T)idxDelay) * rtb_DiscreteTimeIntegrator_p);

  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
  if (rtDW->DiscreteTimeIntegrator1_DSTAT_a == 1.0F) {
    idxDelay = 1;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTAT_a == -100.0F) {
    idxDelay = -1;
  } else {
    idxDelay = 0;
  }

  /* Saturate: '<S6>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_do > 1143.0F) {
    rtb_DiscreteTimeIntegrator_do = 1143.0F;
  } else if (rtb_DiscreteTimeIntegrator_do < 9.0F) {
    rtb_DiscreteTimeIntegrator_do = 9.0F;
  }

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion14'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
   *  Product: '<S6>/Product'
   *  Saturate: '<S6>/Saturation1'
   *  Sum: '<S6>/Sum'
   */
  rtY_vcu2ai_data_outport->vcu_speeds.rr_wheel_speed = (uint16_T)(real32_T)((1.0
    - (real_T)idxDelay) * rtb_DiscreteTimeIntegrator_do);

  /* RateLimiter: '<S1>/Rate Limiter' incorporates:
   *  Delay: '<S1>/Delay1'
   */
  rtb_DiscreteTimeIntegrator_do = rtDW->Delay1_DSTATE[0] - rtDW->PrevY;
  if (rtb_DiscreteTimeIntegrator_do > 0.4F) {
    rtb_DiscreteTimeIntegrator_do = rtDW->PrevY + 0.4F;
  } else if (rtb_DiscreteTimeIntegrator_do < -0.4F) {
    rtb_DiscreteTimeIntegrator_do = rtDW->PrevY - 0.4F;
  } else {
    rtb_DiscreteTimeIntegrator_do = rtDW->Delay1_DSTATE[0];
  }

  rtDW->PrevY = rtb_DiscreteTimeIntegrator_do;

  /* End of RateLimiter: '<S1>/Rate Limiter' */

  /* Backlash: '<S1>/Backlash' */
  if (rtb_DiscreteTimeIntegrator_do < rtDW->PrevY_a - 0.9F) {
    /* Backlash: '<S1>/Backlash' */
    rtb_DiscreteTimeIntegrator_p = rtb_DiscreteTimeIntegrator_do + 0.9F;
  } else if (rtb_DiscreteTimeIntegrator_do <= rtDW->PrevY_a + 0.9F) {
    /* Backlash: '<S1>/Backlash' */
    rtb_DiscreteTimeIntegrator_p = rtDW->PrevY_a;
  } else {
    /* Backlash: '<S1>/Backlash' */
    rtb_DiscreteTimeIntegrator_p = rtb_DiscreteTimeIntegrator_do - 0.9F;
  }

  /* End of Backlash: '<S1>/Backlash' */

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/VehicleOperatingConditon'
   */
  switch (rtU_VehicleOperatingConditon) {
   case 0:
    rtb_MultiportSwitch = 0.0;
    break;

   case 1:
    rtb_MultiportSwitch = rtb_DiscreteTimeIntegrator_p;
    break;

   case 2:
    rtb_MultiportSwitch = rtb_DiscreteTimeIntegrator_do;
    break;

   default:
    rtb_MultiportSwitch = rtb_DiscreteTimeIntegrator_do;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   *  Inport: '<Root>/ai2vcu_data'
   */
  rtY_vcu2ai_data_outport->vcu_steer.angle = -1.0f*(real32_T)rtb_MultiportSwitch;
  rtY_vcu2ai_data_outport->vcu_steer.angle_max = 30.0F;
  rtY_vcu2ai_data_outport->vcu_steer.angle_request =
    rtU_ai2vcu_data->ai_steer.steer_request;

  /* BusCreator generated from: '<Root>/vcu2ai_data_outport' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   */
  rtY_vcu2ai_data_outport->vcu_wheel_counts.fl_pulse_count = (uint16_T)
    rtDW->DiscreteTimeIntegrator_DSTATE;
  rtY_vcu2ai_data_outport->vcu_wheel_counts.fr_pulse_count = (uint16_T)
    rtDW->DiscreteTimeIntegrator_DSTATE_b;
  rtY_vcu2ai_data_outport->vcu_wheel_counts.rl_pulse_count = (uint16_T)
    rtDW->DiscreteTimeIntegrator_DSTATE_n;
  rtY_vcu2ai_data_outport->vcu_wheel_counts.rr_pulse_count = (uint16_T)
    rtDW->DiscreteTimeIntegrator_DSTAT_na;

  /* Signum: '<S2>/Sign' incorporates:
   *  BusCreator generated from: '<Root>/vcu2ai_data_outport'
   *  Inport: '<Root>/ai2vcu_data'
   */
  if (rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct < 0.0F) {
    idxDelay = -1;
  } else {
    idxDelay = (rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct > 0.0F);
  }

  /* Saturate: '<S2>/Saturation4' incorporates:
   *  Bias: '<S2>/Add Constant'
   *  Inport: '<Root>/ai2vcu_data'
   */
  if (rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct + 6.4F > 100.0F) {
    rtb_Product2_idx_1 = 100.0F;
  } else if (rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct + 6.4F < 13.0F) {
    rtb_Product2_idx_1 = 13.0F;
  } else {
    rtb_Product2_idx_1 = rtU_ai2vcu_data->ai_brake.hyd_press_f_req_pct + 6.4F;
  }

  /* Product: '<S2>/Product2' incorporates:
   *  Saturate: '<S2>/Saturation4'
   *  Signum: '<S2>/Sign'
   */
  rtb_DiscreteTimeIntegrator_do = (real32_T)idxDelay * rtb_Product2_idx_1;

  /* Signum: '<S2>/Sign' incorporates:
   *  BusCreator generated from: '<Root>/vcu2ai_data_outport'
   *  Inport: '<Root>/ai2vcu_data'
   */
  if (rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct < 0.0F) {
    idxDelay = -1;
  } else {
    idxDelay = (rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct > 0.0F);
  }

  /* Saturate: '<S2>/Saturation4' incorporates:
   *  Bias: '<S2>/Add Constant'
   *  Inport: '<Root>/ai2vcu_data'
   */
  if (rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct + 6.4F > 100.0F) {
    rtb_Product2_idx_1 = 100.0F;
  } else if (rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct + 6.4F < 13.0F) {
    rtb_Product2_idx_1 = 13.0F;
  } else {
    rtb_Product2_idx_1 = rtU_ai2vcu_data->ai_brake.hyd_press_r_req_pct + 6.4F;
  }

  /* Product: '<S2>/Product2' incorporates:
   *  Saturate: '<S2>/Saturation4'
   *  Signum: '<S2>/Sign'
   */
  rtb_Product2_idx_1 *= (real32_T)idxDelay;

  /* RateLimiter: '<S2>/Rate Limiter' */
  rtb_RateLimiter_p_0 = rtb_DiscreteTimeIntegrator_do - rtDW->PrevY_o[0];
  if (rtb_RateLimiter_p_0 > 50.0F) {
    rtb_RateLimiter_p_0 = rtDW->PrevY_o[0] + 50.0F;
  } else if (rtb_RateLimiter_p_0 < -33.0F) {
    rtb_RateLimiter_p_0 = rtDW->PrevY_o[0] - 33.0F;
  } else {
    rtb_RateLimiter_p_0 = rtb_DiscreteTimeIntegrator_do;
  }

  rtb_DiscreteTimeIntegrator_do = rtb_RateLimiter_p_0;
  rtDW->PrevY_o[0] = rtb_RateLimiter_p_0;
  rtb_RateLimiter_p_0 = rtb_Product2_idx_1 - rtDW->PrevY_o[1];
  if (rtb_RateLimiter_p_0 > 50.0F) {
    rtb_RateLimiter_p_0 = rtDW->PrevY_o[1] + 50.0F;
  } else if (rtb_RateLimiter_p_0 < -33.0F) {
    rtb_RateLimiter_p_0 = rtDW->PrevY_o[1] - 33.0F;
  } else {
    rtb_RateLimiter_p_0 = rtb_Product2_idx_1;
  }

  rtDW->PrevY_o[1] = rtb_RateLimiter_p_0;

  /* Update for Delay: '<S2>/Delay2' incorporates:
   *  RateLimiter: '<S2>/Rate Limiter'
   */
  for (idxDelay = 0; idxDelay < 7; idxDelay++) {
    Delay2_DSTATE_tmp = (idxDelay + 1) << 1;
    Delay2_DSTATE_tmp_0 = idxDelay << 1;
    rtDW->Delay2_DSTATE[Delay2_DSTATE_tmp_0] = rtDW->
      Delay2_DSTATE[Delay2_DSTATE_tmp];
    rtDW->Delay2_DSTATE[Delay2_DSTATE_tmp_0 + 1] = rtDW->
      Delay2_DSTATE[Delay2_DSTATE_tmp + 1];
  }

  rtDW->Delay2_DSTATE[14] = rtb_DiscreteTimeIntegrator_do;
  rtDW->Delay2_DSTATE[15] = rtb_RateLimiter_p_0;

  /* End of Update for Delay: '<S2>/Delay2' */

  /* Update for RateTransition: '<S2>/Rate Transition8' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW->RateTransition8_Buffer0 = rtb_RateLimiter_e;

    /* Update for RateTransition: '<S2>/Rate Transition11' */
    rtDW->RateTransition11_Buffer0 = rtb_MaxTorqueNm_f1;

    /* Update for RateTransition: '<S2>/Rate Transition9' */
    rtDW->RateTransition9_Buffer0 = rtb_RateLimiter_m;

    /* Update for RateTransition: '<S2>/Rate Transition10' */
    rtDW->RateTransition10_Buffer0 = rtb_MaxTorqueNm;
  }

  /* End of Update for RateTransition: '<S2>/Rate Transition8' */

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_DSTATE += 0.01F * (real32_T)
    rtb_DataTypeConversion;
  if (rtDW->DiscreteTimeIntegrator1_DSTATE > 1.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTATE = 1.0F;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTATE < -100.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTATE = -100.0F;
  }

  if (rtb_DataTypeConversion > 0) {
    rtDW->DiscreteTimeIntegrator1_PrevRes = 1;
  } else {
    rtDW->DiscreteTimeIntegrator1_PrevRes = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_DSTAT_o += 0.01F * (real32_T)
    rtb_DataTypeConversion_e;
  if (rtDW->DiscreteTimeIntegrator1_DSTAT_o > 1.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTAT_o = 1.0F;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTAT_o < -100.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTAT_o = -100.0F;
  }

  if (rtb_DataTypeConversion_e > 0) {
    rtDW->DiscreteTimeIntegrator1_PrevR_p = 1;
  } else {
    rtDW->DiscreteTimeIntegrator1_PrevR_p = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_DSTA_o0 += 0.01F * (real32_T)
    rtb_DataTypeConversion_l;
  if (rtDW->DiscreteTimeIntegrator1_DSTA_o0 > 1.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTA_o0 = 1.0F;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTA_o0 < -100.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTA_o0 = -100.0F;
  }

  if (rtb_DataTypeConversion_l > 0) {
    rtDW->DiscreteTimeIntegrator1_PrevR_n = 1;
  } else {
    rtDW->DiscreteTimeIntegrator1_PrevR_n = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  rtDW->DiscreteTimeIntegrator1_DSTAT_a += 0.01F * (real32_T)rtb_Compare;
  if (rtDW->DiscreteTimeIntegrator1_DSTAT_a > 1.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTAT_a = 1.0F;
  } else if (rtDW->DiscreteTimeIntegrator1_DSTAT_a < -100.0F) {
    rtDW->DiscreteTimeIntegrator1_DSTAT_a = -100.0F;
  }

  if (rtb_Compare) {
    rtDW->DiscreteTimeIntegrator1_PrevR_o = 1;
  } else {
    rtDW->DiscreteTimeIntegrator1_PrevR_o = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  BusCreator generated from: '<Root>/vcu2ai_data_outport'
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/ai2vcu_data'
   */
  rtDW->Delay1_DSTATE[0] = rtDW->Delay1_DSTATE[1];
  rtDW->Delay1_DSTATE[1] = rtDW->Delay1_DSTATE[2];
  rtDW->Delay1_DSTATE[2] = rtDW->Delay1_DSTATE[3];
  rtDW->Delay1_DSTATE[3] = rtDW->Delay1_DSTATE[4];
  rtDW->Delay1_DSTATE[4] = -rtU_ai2vcu_data->ai_steer.steer_request;

  /* Update for Backlash: '<S1>/Backlash' */
  rtDW->PrevY_a = rtb_DiscreteTimeIntegrator_p;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S3>/PulsesPerRevolution'
   */
  rtDW->DiscreteTimeIntegrator_DSTATE += 36.0F * rtb_WheelRotationRate_rps_p *
    0.01F;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S4>/PulsesPerRevolution'
   */
  rtDW->DiscreteTimeIntegrator_DSTATE_b += 36.0F * rtb_WheelRotationRate_rps_c *
    0.01F;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S5>/PulsesPerRevolution'
   */
  rtDW->DiscreteTimeIntegrator_DSTATE_n += 36.0F * rtb_WheelRotationRate_rps_f *
    0.01F;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S6>/PulsesPerRevolution'
   */
  rtDW->DiscreteTimeIntegrator_DSTAT_na += 36.0F * rtb_WheelRotationRate_rps_l *
    0.01F;
  rate_scheduler(rtM);
}

/* Model initialize function */
void FSAI_VehicleModel_initialize(RT_MODEL *const rtM, vcu2ai_data_t
  *rtU_vcu2ai_data_init, vcu2ai_data_t *rtY_vcu2ai_data_outport)
{
  DW *rtDW = rtM->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)rtDW, 0,
                sizeof(DW));

  /* external inputs */
  *rtU_vcu2ai_data_init = FSAI_VehicleModel_rtZvcu2ai_dat;

  /* external outputs */
  *rtY_vcu2ai_data_outport = FSAI_VehicleModel_rtZvcu2ai_dat;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_PrevRes = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_PrevR_p = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_PrevR_n = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
  rtDW->DiscreteTimeIntegrator1_PrevR_o = 2;

  /* InitializeConditions for RateLimiter: '<S1>/Rate Limiter' */
  rtDW->PrevY = 0.0F;

  /* InitializeConditions for Backlash: '<S1>/Backlash' */
  rtDW->PrevY_a = 0.0F;

  /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
  rtDW->PrevY_o[0] = 0.0F;
  rtDW->PrevY_o[1] = 0.0F;

  /* SystemInitialize for Atomic SubSystem: '<S2>/MotorModel_f' */
  MotorModel_f_Init(&rtDW->MotorModel_f_a);

  /* End of SystemInitialize for SubSystem: '<S2>/MotorModel_f' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/MotorModel_fr' */
  MotorModel_f_Init(&rtDW->MotorModel_fr);

  /* End of SystemInitialize for SubSystem: '<S2>/MotorModel_fr' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
