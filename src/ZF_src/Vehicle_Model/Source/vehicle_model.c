#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h>
#include "../../mock_io/messages.h"
//#include "mock_io/state_machine.h"
#include "../Include/vehicle_model.h"
#include "../Include/FSAI_VehicleModel.h"
#include "../Include/rtwtypes.h"

// #include "can_interface.h"

static RT_MODEL rtM_; 
static RT_MODEL *const rtMPtr = &rtM_;
static DW rtDW;

/* '<Root>/WheelRadius_[m]' */
static float rtU_WheelRadius_m = 0.15;


int vehicle_model_update(ai2vcu_data_t *ai2vcu_data, vehicle_state_t *vehicle_state, vcu2ai_data_t *vcu2ai_data, 
                          float rtU_ActualWheelspeedFL_mps, float rtU_ActualWheelspeedFR_mps, 
                          float rtU_ActualWheelspeedRL_mps, float rtU_ActualWheelspeedRR_mps)
{
  // static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  // /* Check for overrun */
  // if (OverrunFlag) {
  //   rtmSetErrorStatus(rtM, "Overrun");
  //   return;
  // }

  // OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  
  /* Step the model */
  FSAI_VehicleModel_step(rtMPtr, ai2vcu_data, vehicle_state->VehicleOperatingCondition, rtU_WheelRadius_m, vcu2ai_data, 
                           rtU_ActualWheelspeedFL_mps, rtU_ActualWheelspeedFR_mps,  rtU_ActualWheelspeedRL_mps, rtU_ActualWheelspeedRR_mps,  vcu2ai_data );

  // /* Indicate task complete */
  // OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */

  return 0;
}

// init the vehicle model depending on running condition (i.e on ground, static wheels on, static wheels off, etc...
int vehicle_model_init()
{
  
  RT_MODEL *const rtM = rtMPtr;

  rtMPtr->dwork = &rtDW;
  vcu2ai_data_t temp;

  FSAI_VehicleModel_initialize(rtM, &temp, &temp); //local variabvcu2ai data to be reset without affecting global data storage or something

  return 0;
}






