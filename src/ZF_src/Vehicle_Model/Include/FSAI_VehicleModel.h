/*
 * File: FSAI_VehicleModel.h
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

#ifndef RTW_HEADER_FSAI_VehicleModel_h_
#define RTW_HEADER_FSAI_VehicleModel_h_
#ifndef FSAI_VehicleModel_COMMON_INCLUDES_
#define FSAI_VehicleModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FSAI_VehicleModel_COMMON_INCLUDES_ */

#include "../../mock_io/messages.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S2>/MotorModel_f' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S51>/Integrator' */
  real32_T Filter_DSTATE;              /* '<S46>/Filter' */
  real32_T PrevY;                      /* '<S8>/Rate Limiter' */
  int8_T Integrator_PrevResetState;    /* '<S51>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S46>/Filter' */
} DW_MotorModel_f;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_MotorModel_f MotorModel_fr;       /* '<S2>/MotorModel_fr' */
  DW_MotorModel_f MotorModel_f_a;      /* '<S2>/MotorModel_f' */
  real_T RateTransition11;             /* '<S2>/Rate Transition11' */
  real_T RateTransition10;             /* '<S2>/Rate Transition10' */
  real_T RateTransition11_Buffer0;     /* '<S2>/Rate Transition11' */
  real_T RateTransition10_Buffer0;     /* '<S2>/Rate Transition10' */
  real32_T Delay2_DSTATE[16];          /* '<S2>/Delay2' */
  real32_T Delay1_DSTATE[5];           /* '<S1>/Delay1' */
  real32_T PrevY_o[2];                 /* '<S2>/Rate Limiter' */
  real32_T RateTransition8;            /* '<S2>/Rate Transition8' */
  real32_T RateTransition9;            /* '<S2>/Rate Transition9' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S4>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTA_o0;/* '<S5>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_a;/* '<S6>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S4>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S5>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_na;/* '<S6>/Discrete-Time Integrator' */
  real32_T RateTransition8_Buffer0;    /* '<S2>/Rate Transition8' */
  real32_T RateTransition9_Buffer0;    /* '<S2>/Rate Transition9' */
  real32_T PrevY;                      /* '<S1>/Rate Limiter' */
  real32_T PrevY_a;                    /* '<S1>/Backlash' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S3>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S4>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_n;/* '<S5>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_o;/* '<S6>/Discrete-Time Integrator1' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: MotorModel_LUT_MaxTorque)
   * Referenced by:
   *   '<S8>/TorqueLimit'
   *   '<S9>/TorqueLimit'
   */
  real_T pooled1[9];

  /* Pooled Parameter (Expression: MotorModel_LUT_MaxTorque2)
   * Referenced by:
   *   '<S8>/MotorTorqueModel'
   *   '<S9>/MotorTorqueModel'
   */
  real_T pooled2[5];

  /* Pooled Parameter (Expression: MotorModel_LUT_MotorSpeed_BP)
   * Referenced by:
   *   '<S8>/TorqueLimit'
   *   '<S9>/TorqueLimit'
   */
  real32_T pooled9[9];

  /* Pooled Parameter (Expression: MotorModel_LUT_MotorSpeed2_BP)
   * Referenced by:
   *   '<S8>/MotorTorqueModel'
   *   '<S9>/MotorTorqueModel'
   */
  real32_T pooled10[5];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* External data declarations for dependent source files */
extern const vcu2ai_data_t FSAI_VehicleModel_rtZvcu2ai_dat;/* vcu2ai_data_t ground */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void FSAI_VehicleModel_initialize(RT_MODEL *const rtM, vcu2ai_data_t
  *rtU_vcu2ai_data_init, vcu2ai_data_t *rtY_vcu2ai_data_outport);
extern void FSAI_VehicleModel_step(RT_MODEL *const rtM, ai2vcu_data_t
  *rtU_ai2vcu_data, uint8_T rtU_VehicleOperatingConditon, real32_T
  rtU_WheelRadius_m, vcu2ai_data_t *rtU_vcu2ai_data_init, real32_T
  rtU_ActualWheelspeedFL_mps, real32_T rtU_ActualWheelspeedFR_mps, real32_T
  rtU_ActualWheelspeedRL_mps, real32_T rtU_ActualWheelspeedRR_mps, vcu2ai_data_t
  *rtY_vcu2ai_data_outport);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Propagation' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion19' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion21' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion22' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition7' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FSAI_VehicleModel'
 * '<S1>'   : 'FSAI_VehicleModel/LateralVehicleModel'
 * '<S2>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel'
 * '<S3>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountFL'
 * '<S4>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountFR'
 * '<S5>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountRL'
 * '<S6>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountRR'
 * '<S7>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/Compare To Zero'
 * '<S8>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f'
 * '<S9>'   : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr'
 * '<S10>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/WheelSpeed_2_MotorRotationRate_f'
 * '<S11>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/WheelSpeed_2_MotorRotationRate_r'
 * '<S12>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountFL/Compare To Constant'
 * '<S13>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountFR/Compare To Constant'
 * '<S14>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountRL/Compare To Constant'
 * '<S15>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/CalculatePulseCountRR/Compare To Constant'
 * '<S16>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front'
 * '<S17>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Anti-windup'
 * '<S18>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/D Gain'
 * '<S19>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Filter'
 * '<S20>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Filter ICs'
 * '<S21>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/I Gain'
 * '<S22>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Ideal P Gain'
 * '<S23>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Ideal P Gain Fdbk'
 * '<S24>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Integrator'
 * '<S25>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Integrator ICs'
 * '<S26>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/N Copy'
 * '<S27>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/N Gain'
 * '<S28>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/P Copy'
 * '<S29>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Parallel P Gain'
 * '<S30>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Reset Signal'
 * '<S31>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Saturation'
 * '<S32>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Saturation Fdbk'
 * '<S33>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Sum'
 * '<S34>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Sum Fdbk'
 * '<S35>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tracking Mode'
 * '<S36>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tracking Mode Sum'
 * '<S37>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tsamp - Integral'
 * '<S38>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tsamp - Ngain'
 * '<S39>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/postSat Signal'
 * '<S40>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/preSat Signal'
 * '<S41>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel'
 * '<S42>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S43>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S44>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S45>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/D Gain/Internal Parameters'
 * '<S46>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Filter/Disc. Forward Euler Filter'
 * '<S47>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Filter ICs/Internal IC - Filter'
 * '<S48>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/I Gain/Internal Parameters'
 * '<S49>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Ideal P Gain/Passthrough'
 * '<S50>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Ideal P Gain Fdbk/Disabled'
 * '<S51>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Integrator/Discrete'
 * '<S52>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Integrator ICs/Internal IC'
 * '<S53>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/N Copy/Disabled'
 * '<S54>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/N Gain/Internal Parameters'
 * '<S55>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/P Copy/Disabled'
 * '<S56>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Parallel P Gain/Internal Parameters'
 * '<S57>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Reset Signal/External Reset'
 * '<S58>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Saturation/External'
 * '<S59>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Saturation/External/Saturation Dynamic'
 * '<S60>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Saturation Fdbk/Disabled'
 * '<S61>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Sum/Sum_PID'
 * '<S62>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Sum Fdbk/Disabled'
 * '<S63>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tracking Mode/Disabled'
 * '<S64>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tracking Mode Sum/Passthrough'
 * '<S65>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tsamp - Integral/TsSignalSpecification'
 * '<S66>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/Tsamp - Ngain/Passthrough'
 * '<S67>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/postSat Signal/Forward_Path'
 * '<S68>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_f/SpeedControl_Front/preSat Signal/Forward_Path'
 * '<S69>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front'
 * '<S70>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Anti-windup'
 * '<S71>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/D Gain'
 * '<S72>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Filter'
 * '<S73>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Filter ICs'
 * '<S74>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/I Gain'
 * '<S75>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Ideal P Gain'
 * '<S76>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Ideal P Gain Fdbk'
 * '<S77>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Integrator'
 * '<S78>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Integrator ICs'
 * '<S79>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/N Copy'
 * '<S80>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/N Gain'
 * '<S81>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/P Copy'
 * '<S82>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Parallel P Gain'
 * '<S83>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Reset Signal'
 * '<S84>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Saturation'
 * '<S85>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Saturation Fdbk'
 * '<S86>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Sum'
 * '<S87>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Sum Fdbk'
 * '<S88>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tracking Mode'
 * '<S89>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tracking Mode Sum'
 * '<S90>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tsamp - Integral'
 * '<S91>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tsamp - Ngain'
 * '<S92>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/postSat Signal'
 * '<S93>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/preSat Signal'
 * '<S94>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel'
 * '<S95>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S96>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S97>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S98>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/D Gain/Internal Parameters'
 * '<S99>'  : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Filter/Disc. Forward Euler Filter'
 * '<S100>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Filter ICs/Internal IC - Filter'
 * '<S101>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/I Gain/Internal Parameters'
 * '<S102>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Ideal P Gain/Passthrough'
 * '<S103>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Ideal P Gain Fdbk/Disabled'
 * '<S104>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Integrator/Discrete'
 * '<S105>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Integrator ICs/Internal IC'
 * '<S106>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/N Copy/Disabled'
 * '<S107>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/N Gain/Internal Parameters'
 * '<S108>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/P Copy/Disabled'
 * '<S109>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Parallel P Gain/Internal Parameters'
 * '<S110>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Reset Signal/External Reset'
 * '<S111>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Saturation/External'
 * '<S112>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Saturation/External/Saturation Dynamic'
 * '<S113>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Saturation Fdbk/Disabled'
 * '<S114>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Sum/Sum_PID'
 * '<S115>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Sum Fdbk/Disabled'
 * '<S116>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tracking Mode/Disabled'
 * '<S117>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tracking Mode Sum/Passthrough'
 * '<S118>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tsamp - Integral/TsSignalSpecification'
 * '<S119>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/Tsamp - Ngain/Passthrough'
 * '<S120>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/postSat Signal/Forward_Path'
 * '<S121>' : 'FSAI_VehicleModel/LongitudinalVehicleModel/MotorModel_fr/SpeedControl_Front/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FSAI_VehicleModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
