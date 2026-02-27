#pragma once

#include "messages.h"

// Enumeration of the ASSI LED states, combining color and pattern
typedef enum
{
    LED_OFF,                        // Off: AS_OFF
    LED_YELLOW_CONTINUOUS,          // Yellow continuous: AS_READY
    LED_YELLOW_AND_BLUE_CONTINUOUS, // Confirming AS_READY after 5 second timer (appears white)
    LED_YELLOW_FLASHING,            // Yellow flashing: AS_DRIVING
    LED_BLUE_CONTINUOUS,            // Blue continuous: AS_FINISHED
    LED_BLUE_FLASHING               // Blue flashing: EMERGENCY_BRAKE
} assi_led_state_e;

// Function to update the LED state based on the ASSI state
static inline void _updateASSIState(as_state_e state, assi_led_state_e *retval)
{
    switch (state)
    {
    case AS_OFF:
        *retval = LED_OFF;
        break;
    case AS_READY:
        *retval = LED_YELLOW_CONTINUOUS;
        break;
    case AS_DRIVING:
        *retval = LED_YELLOW_FLASHING;
        break;
    case AS_FINISHED:
        *retval = LED_BLUE_CONTINUOUS;
        break;
    case AS_EMERGENCY_BRAKE:
        *retval = LED_BLUE_FLASHING;
        break;
    default:
        // Handle unexpected states if necessary
        break;
    }
}

static inline void printASSI_LED_State(assi_led_state_e ledState, int indent)
{
    const char *ledStateNames[] = {
        "Off",
        "Yellow Continuous",
        "Yellow and Blue Continuous (white)",
        "Yellow Flashing",
        "Blue Continuous",
        "Blue Flashing"};
    printf("%*sASSI LED State: %s\n", indent * 4, "", ledStateNames[ledState]);
}
