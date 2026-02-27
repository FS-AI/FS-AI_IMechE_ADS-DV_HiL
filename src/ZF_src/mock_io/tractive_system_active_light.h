#pragma once

// Enumeration of the TSAL LED states
typedef enum
{
    TSAL_OFF,
    TSAL_GREEN,       // Green: Drive motors are disabled
    TSAL_RED_FLASHING // Red flashing: Drive motors are enabled
} tsal_led_state_e;

static inline void printTSAL_LED_State(tsal_led_state_e ledState, int indent)
{
    const char *ledStateNames[] = {
        "Off",
        "Green (Drive Motors Disabled)",
        "Red Flashing (Drive Motors Enabled)"};
    printf("%*sTSAL LED State: %s\n", indent * 4, "", ledStateNames[ledState]);
}
