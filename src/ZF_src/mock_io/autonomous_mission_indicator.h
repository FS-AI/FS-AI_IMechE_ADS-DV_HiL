#pragma once
#include <stdbool.h>
#include "messages.h"

// Structure to hold vehicle diagnostic data
typedef struct
{
    float tractionBatteryVoltage;
    float auxiliaryBatteryVoltage;
    bool contactorState;
    bool hvilOpenCircuit;
    bool allShutdownRequest;
    // Add other diagnostic flags as needed
} ami_vehicle_diagnostic_data_t;

static inline void printAMIVehicleDiagnosticData(ami_vehicle_diagnostic_data_t data, int indent)
{
    // TODO: add  these back in if we decide to implement functionality behind them. Otherwise they are just UI clutter
    printf("%*sData: [Not Implemented]\n", indent * 4, "");
    return;
    printf("%*sTraction Battery Voltage: %.2f\n", indent * 4, "", data.tractionBatteryVoltage);
    printf("%*sAuxiliary Battery Voltage: %.2f\n", indent * 4, "", data.auxiliaryBatteryVoltage);
    printf("%*sContactor State: %s\n", indent * 4, "", data.contactorState ? "true" : "false");
    printf("%*sHVIL Open Circuit: %s\n", indent * 4, "", data.hvilOpenCircuit ? "true" : "false");
    printf("%*sAll Shutdown Request: %s\n", indent * 4, "", data.allShutdownRequest ? "true" : "false");
}

typedef enum
{
    AMI_OP_MODE_OFF,
    AMI_OP_MODE_STARTING_UP, // TODO: ... naaaaaah
    AMI_OP_MODE_PUSHBAR,
    AMI_OP_MODE_DRIVE_MANUAL,
    AMI_OP_MODE_AUTONOMOUS,
    AMI_OP_MODE_AUXILIARY,
    AMI_OP_MODE_CHARGE,
    AMI_OP_MODE_EMERGENCY,
    AMI_OP_MODE_SHUTDOWN_ACTIONS,
    AMI_OP_MODE_SHUTDOWN_OFF,
    AMI_OP_MODE_UNDEFINED, // Undefined state, used for error checking or default
} ami_operational_mode_t;
static inline void printAMI_OperationalMode(ami_operational_mode_t mode, int indent)
{
    const char *modeNames[] = {
        "OFF", "STARTING_UP", "PUSHBAR", "DRIVE_MANUAL", "AUTONOMOUS",
        "AUXILIARY", "CHARGE", "EMERGENCY", "SHUTDOWN_ACTIONS", "SHUTDOWN_OFF", "UNDEFINED"};
    printf("%*sOperational Mode: %s\n", indent * 4, "", modeNames[mode]);
}

// Structure to hold traction battery data
typedef struct
{
    int batterySOC;
    float batteryVoltage;
    float batteryCurrent;
    float maxCellTemperature;
    float minCellVoltage;
    float maxCellVoltage;
} ami_traction_battery_data_t;
static inline void printAMITractionBatteryData(ami_traction_battery_data_t data, int indent)
{
    // TODO: add  these back in if we decide to implement functionality behind them. Otherwise they are just UI clutter
    printf("%*sData: [Not Implemented]\n", indent * 4, "");
    return;
    printf("%*sBattery SOC: %d\n", indent * 4, "", data.batterySOC);
    printf("%*sBattery Voltage: %.2f\n", indent * 4, "", data.batteryVoltage);
    printf("%*sBattery Current: %.2f\n", indent * 4, "", data.batteryCurrent);
    printf("%*sMax Cell Temperature: %.2f\n", indent * 4, "", data.maxCellTemperature);
    printf("%*sMin Cell Voltage: %.2f\n", indent * 4, "", data.minCellVoltage);
    printf("%*sMax Cell Voltage: %.2f\n", indent * 4, "", data.maxCellVoltage);
}

// Structure to hold braking system data
typedef struct
{
    char brakingControllerStatus[20];
    char ebsStatus[20];
    float frontAxleBrakePressure;
    float rearAxleBrakePressure;
} ami_braking_system_data_t;
static inline void printAMIBrakingSystemData(ami_braking_system_data_t data, int indent)
{
    // TODO: add  these back in if we decide to implement functionality behind them. Otherwise they are just UI clutter
    printf("%*sData: [Not Implemented]\n", indent * 4, "");
    return;
    printf("%*sBraking Controller Status: %s\n", indent * 4, "", data.brakingControllerStatus);
    printf("%*sEBS Status: %s\n", indent * 4, "", data.ebsStatus);
    printf("%*sFront Axle Brake Pressure: %.2f\n", indent * 4, "", data.frontAxleBrakePressure);
    printf("%*sRear Axle Brake Pressure: %.2f\n", indent * 4, "", data.rearAxleBrakePressure);
}

// Touchscreen display API
typedef struct
{
    ami_state_e mission;
    as_state_e autonomous_state;
    ami_operational_mode_t op_mode;
    ami_vehicle_diagnostic_data_t ami_vehicle_diagnostic_data;
    ami_traction_battery_data_t ami_traction_battery_data;
    ami_braking_system_data_t ami_braking_system_data;
} AMIScreenState;

static inline void printAMIScreenState(AMIScreenState state, int indent)
{
    printAmiState(state.mission, indent);
    printAsState(state.autonomous_state, indent);
    printAMI_OperationalMode(state.op_mode, indent);
    printf("%*sVehicle Diagnostic Data:\n", indent * 4, "");
    printAMIVehicleDiagnosticData(state.ami_vehicle_diagnostic_data, indent + 1);
    printf("%*sTraction Battery Data:\n", indent * 4, "");
    printAMITractionBatteryData(state.ami_traction_battery_data, indent + 1);
    printf("%*sBraking System Data:\n", indent * 4, "");
    printAMIBrakingSystemData(state.ami_braking_system_data, indent + 1);
}