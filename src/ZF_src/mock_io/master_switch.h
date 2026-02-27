#pragma once

#include <stdbool.h>
// #include "utils/logging.h"
#include "messages.h"

// Define the switches
typedef enum
{
    TSMS, // Tractive System Master Switch
    ASMS, // Autonomous System Master Switch
    LVMS, // Low Voltage Master Switch
    AIMS, // AI Master Switch
} master_switch_e;

// A struct to represent the state of all switches
typedef struct
{
    status_bit_e TSMSState;
    status_bit_e ASMSState;
    status_bit_e LVMSState;
    status_bit_e AIMSState;
} master_switch_states_t;

static inline void printMasterSwitchEnum(master_switch_e switchType, int indent)
{
    const char *switchNames[] = {"TSMS", "ASMS", "LVMS", "AIMS"};
    printf("%*sMaster Switch: %s\n", indent * 4, "", switchNames[switchType]);
}

static inline void printMasterSwitchStates(master_switch_states_t states, int indent)
{
    printf("%*sTSMS State: ", indent * 4, "");
    printStatusBit(states.TSMSState, 0);
    printf("%*sASMS State: ", indent * 4, "");
    printStatusBit(states.ASMSState, 0);
    printf("%*sLVMS State: ", indent * 4, "");
    printStatusBit(states.LVMSState, 0);
    printf("%*sAIMS State: ", indent * 4, "");
    printStatusBit(states.AIMSState, 0);
}