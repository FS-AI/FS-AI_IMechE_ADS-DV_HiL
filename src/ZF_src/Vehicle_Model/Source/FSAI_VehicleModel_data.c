/*
 * File: FSAI_VehicleModel_data.c
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

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: MotorModel_LUT_MaxTorque)
   * Referenced by:
   *   '<S8>/TorqueLimit'
   *   '<S9>/TorqueLimit'
   */
  { 55.714285714285715, 42.857142857142854, 34.285714285714285,
    28.571428571428573, 24.285714285714285, 14.285714285714286,
    8.5714285714285712, 2.8571428571428572, 0.0 },

  /* Pooled Parameter (Expression: MotorModel_LUT_MaxTorque2)
   * Referenced by:
   *   '<S8>/MotorTorqueModel'
   *   '<S9>/MotorTorqueModel'
   */
  { 55.714285714285715, 14.285714285714286, 8.5714285714285712,
    2.8571428571428572, 0.0 },

  /* Pooled Parameter (Expression: MotorModel_LUT_MotorSpeed_BP)
   * Referenced by:
   *   '<S8>/TorqueLimit'
   *   '<S9>/TorqueLimit'
   */
  { 0.0F, 1050.0F, 1400.0F, 1750.0F, 2100.0F, 2450.0F, 2800.0F, 3150.0F, 4000.5F
  },

  /* Pooled Parameter (Expression: MotorModel_LUT_MotorSpeed2_BP)
   * Referenced by:
   *   '<S8>/MotorTorqueModel'
   *   '<S9>/MotorTorqueModel'
   */
  { 0.0F, 2450.0F, 2800.0F, 3150.0F, 4000.5F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
