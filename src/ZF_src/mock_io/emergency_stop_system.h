#pragma once

#include <stdbool.h>

// A struct to represent the state of the emergency stop system
typedef struct
{
    bool watchdog_detected; // Remote is being detected by the vehicle
    bool estop_signalled;   // E-stop button state
    bool go_signalled;      // GO switch state
} emergency_stop_system_states_t;

static inline void printEmergencyStopSystemStates(emergency_stop_system_states_t states, int indent)
{
    printf("%*sWatchdog Detected: %s\n", indent * 4, "", states.watchdog_detected ? "true" : "false");
    printf("%*sE-stop Signalled: %s\n", indent * 4, "", states.estop_signalled ? "true" : "false");
    printf("%*sGo Signalled: %s\n", indent * 4, "", states.go_signalled ? "true" : "false");
}
