#ifndef VEHICLE_MODEL_H
#define VEHICLE_MODEL_H

#include "../../mock_io/messages.h"
#include "../../mock_io/vehicle_state.h"

int vehicle_model_init();
int vehicle_model_update(ai2vcu_data_t *ai2vcu_data, vehicle_state_t *vehicle_state, vcu2ai_data_t *vcu2ai_data, 
                          float rtU_ActualWheelspeedFL_mps, float rtU_ActualWheelspeedFR_mps, 
                          float rtU_ActualWheelspeedRL_mps, float rtU_ActualWheelspeedRR_mps);

#endif