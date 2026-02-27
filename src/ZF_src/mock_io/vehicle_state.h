#pragma once

#include <stdbool.h>
#include "master_switch.h"
#include "emergency_stop_system.h"
#include "autonomous_system_status_indicator.h"
#include "tractive_system_active_light.h"
#include "autonomous_mission_indicator.h"
#include "messages.h"

//changed due to switch states being different on Simulink design
typedef enum vehicle_operating_condition
{
    UNDEFINED,
    VEH_OP_COND_ON_GROUND,
    VEH_OP_COND_STATIC_WHEELS_ON,
    VEH_OP_COND_STATIC_WHEELS_OFF
    
} vehicle_operating_condition_e;
static inline void printVehicleOpCond(vehicle_operating_condition_e vehCond, int indent)
{
    const char *vehicleOpCondNames[] = {"UNDEFINED","On Jack (Wheels ON)", "On Jack (Wheels OFF)","On Ground"};
    printf("%*sVehicle Operating Condition: %s\n", indent * 4, "", vehicleOpCondNames[vehCond]);
}

// Enum to represent the state of the Multi-Purpose Port (MPP)
typedef enum
{
    MPP_None,              // No device connected
    MPP_AutonomousDriving, // Autonomous driving dongle
    MPP_JoystickUmbilical, // TODO: Maybe push this out to its own thing? Not required for current work task so skipping.
    MPP_ChargerComms,      // TODO: Maybe push this out to its own thing? Not required for current work task so skipping.
} mpp_e;

static inline void printMPP_Type(mpp_e mppType, int indent)
{
    const char *mppTypeNames[] = {"None", "Autonomous Driving", "Joystick Umbilical", "Charger Comms"};
    printf("%*sMPP Type: %s\n", indent * 4, "", mppTypeNames[mppType]);
}

typedef enum
{ // TODO: Dependent on timers, but this needs to be added too
    SIREN_OFF,
    SIREN_CONTINUOUS,
    SIREN_BEEPING,
} vehicle_state_siren_e;

static inline void printVehicleStateSiren(vehicle_state_siren_e sirenState, int indent)
{
    const char *sirenStateNames[] = {"Off", "Continuous", "Beeping"};
    printf("%*sSiren State: %s\n", indent * 4, "", sirenStateNames[sirenState]);
}

typedef struct
{
    bool motor_control_enabled;
    bool steering_control_enabled;
    bool brakes_locked;
    bool speed_capped;           // low speed mode for joystick driving. TODO: Vehicle model must cap speed demands at walking space
    bool lock_all_user_controls; // extra lock over controls: needed for autonomous state machine
} vehicle_state_actuator_locks_t;

static inline void printVehicleStateActuatorLocks(vehicle_state_actuator_locks_t locks, int indent)
{
    printf("%*sMotor Control Enabled: %s\n", indent * 4, "", locks.motor_control_enabled ? "true" : "false");
    printf("%*sSteering Control Enabled: %s\n", indent * 4, "", locks.steering_control_enabled ? "true" : "false");
    printf("%*sBrakes Locked: %s\n", indent * 4, "", locks.brakes_locked ? "true" : "false");
    printf("%*sSpeed Capped: %s\n", indent * 4, "", locks.speed_capped ? "true" : "false");
    printf("%*sLock All User Controls: %s\n", indent * 4, "", locks.lock_all_user_controls ? "true" : "false");
}

// A struct to represent the state of all switches
typedef struct
{
    // Switches
    master_switch_states_t master_switch_e;
    emergency_stop_system_states_t EStop;
    bool AIComputerIgnitionSwitchedOn;
    // MPP
    mpp_e MPPType; // State of the Multi-Purpose Port
    // Indicators
    assi_led_state_e ASSILedState;
    tsal_led_state_e TSALLedState;
    AMIScreenState AMIScreenState;
    // Internal State
    bool joystick_dead_mans_switch_pressing;

    vehicle_state_siren_e siren;
    vehicle_state_actuator_locks_t vehicle_state_actuator_locks;
    bool ai_connected;

    vehicle_operating_condition_e VehicleOperatingCondition;
} vehicle_state_t;

static inline void printVehicleState(vehicle_state_t state, int indent)
{
    printf("\n%*s#===inputs===\n", indent * 4, "");
    printf("%*sMaster Switch States:\n", indent * 4, "");
    printMasterSwitchStates(state.master_switch_e, indent + 1);
    printf("%*sEmergency Stop System States:\n", indent * 4, "");
    printEmergencyStopSystemStates(state.EStop, indent + 1);
    printf("%*sAI Computer Ignition Switched On: %s\n", indent * 4, "", state.AIComputerIgnitionSwitchedOn ? "true" : "false");
    printMPP_Type(state.MPPType, indent);
    printf("%*sJoystick Dead Man's Switch Pressing: %s\n", indent * 4, "", state.joystick_dead_mans_switch_pressing ? "true" : "false");

    printf("\n%*s#===outputs===\n", indent * 4, "");
    printVehicleStateSiren(state.siren, indent);
    printASSI_LED_State(state.ASSILedState, indent);
    printTSAL_LED_State(state.TSALLedState, indent);
    printf("%*sAMIScreen State:\n", indent * 4, "");
    printAMIScreenState(state.AMIScreenState, indent + 1);

    printf("\n%*s#===internal flags (hidden)===\n", indent * 4, "");
    printf("%*sVehicle Actuator Locks:\n", indent * 4, "");
    printVehicleStateActuatorLocks(state.vehicle_state_actuator_locks, indent + 1);
    printf("%*sVCU Connected to AI: %s\n", indent * 4, "", state.ai_connected ? "true" : "false");
    printVehicleOpCond(state.VehicleOperatingCondition, indent);
}