#ifndef MESSAGES_H
#define MESSAGES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*************************************************************/
/*      DEFINES                                              */
/*************************************************************/

#define VCU_STATUS_ID 0x120

#define VCU2LOG_DYNAMICS1 0x500
#define AI2LOG_DYNAMICS2_ID 0x501
#define VCU2LOG_STATUS_ID 0x502

#define AI2VCU_STATUS_ID 0x510
#define AI2VCU_DRIVE_F_ID 0x511
#define AI2VCU_DRIVE_R_ID 0x512
#define AI2VCU_STEER_ID 0x513
#define AI2VCU_BRAKE_ID 0x514

#define VCU2AI_STATUS_ID 0x520
#define VCU2AI_DRIVE_F_ID 0x521
#define VCU2AI_DRIVE_R_ID 0x522
#define VCU2AI_STEER_ID 0x523
#define VCU2AI_BRAKE_ID 0x524
#define VCU2AI_SPEEDS_ID 0x525
#define VCU2AI_WHEEL_COUNTS_ID 0x526

/*************************************************************/
/*      ENUM DEFINITIONS                                             */
/*************************************************************/

typedef enum as_state_e
{
    AS_OFF = 1,
    AS_READY = 2,
    AS_DRIVING = 3,
    AS_EMERGENCY_BRAKE = 4,
    AS_FINISHED = 5,
} as_state_e;

typedef enum ami_state_e
{
    AMI_NOT_SELECTED = 0,
	AMI_ACCELERATION = 1,
	AMI_SKIDPAD = 2,
	AMI_AUTOCROSS = 3,
	AMI_TRACK_DRIVE = 4,
	AMI_STATIC_INSPECTION_A = 5,
	AMI_STATIC_INSPECTION_B = 6,
	AMI_AUTONOMOUS_DEMO = 7,
} ami_state_e;

typedef enum handshake_receive_bit_e
{
    HANDSHAKE_RECEIVE_BIT_OFF = 0,
	HANDSHAKE_RECEIVE_BIT_ON = 1,
} handshake_receive_bit_e;

typedef enum res_go_signal_bit_e
{
    RES_GO_SIGNAL_NO_GO = 0,
	RES_GO_SIGNAL_GO = 1,
} res_go_signal_bit_e;

typedef enum mission_status_e
{
    MISSION_NOT_SELECTED = 0,
    MISSION_SELECTED = 1,
    MISSION_RUNNING = 2,
    MISSION_FINISHED = 3,
} mission_status_e;

typedef enum direction_request_e
{
    DIRECTION_NEUTRAL = 0,
    DIRECTION_FORWARD = 1,
} direction_request_e;

typedef enum estop_request_e
{
    ESTOP_NO = 0,
    ESTOP_YES = 1,
} estop_request_e;

typedef enum handshake_send_bit_e
{
    HANDSHAKE_SEND_BIT_OFF = 0,
    HANDSHAKE_SEND_BIT_ON = 1,
} handshake_send_bit_e;

typedef enum status_bit_e
{
    OFF = 0,
    ON = 1,
} status_bit_e;


/*************************************************************/
/*      STRUCT DEFINITIONS                                              */
/*************************************************************/

typedef struct ai2vcu_brake_struct
{
    uint8_t     hyd_press_f_req_pct;
    uint8_t     hyd_press_r_req_pct;
} ai2vcu_brake_t;

typedef struct ai2vcu_drive_f_struct
{
    uint16_t     front_axle_trq_request;
    uint16_t     front_motor_speed_max;
} ai2vcu_drive_f_t;

typedef struct ai2vcu_drive_r_struct
{
    uint16_t     rear_axle_trq_request;
    uint16_t     rear_motor_speed_max;
} ai2vcu_drive_r_t;

typedef struct ai2vcu_status_struct
{
    uint8_t                     handshake;
    uint8_t                     estop_request;
    uint8_t                     mission_status;
    uint8_t                     direction_request;
    uint8_t                     lap_counter;
    uint8_t                     cones_count_actual;
    uint16_t                    cones_count_all;
    uint8_t                     veh_speed_actual;
    uint8_t                     veh_speed_demand;
} ai2vcu_status_t;

typedef struct ai2vcu_steer_struct
{
    int16_t     steer_request;
} ai2vcu_steer_t;

typedef struct vcu2ai_brake_struct
{
    uint8_t     hyd_press_f_pct;
    uint8_t     hyd_press_f_req_pct;
    uint8_t     hyd_press_r_pct;
    uint8_t     hyd_press_r_req_pct;
    uint8_t     status_brk;
    uint8_t     status_ebs;
} vcu2ai_brake_t;

typedef struct vcu2ai_drive_f_struct
{
    int16_t     front_axle_trq;
    uint16_t    front_axle_trq_request;
    uint16_t    front_axle_trq_max;
} vcu2ai_drive_f_t;

typedef struct vcu2ai_drive_r_struct
{
    int16_t     rear_axle_trq;
    uint16_t    rear_axle_trq_request;
    uint16_t    rear_axle_trq_max;
} vcu2ai_drive_r_t;

typedef struct vcu2ai_speeds_struct
{
    uint16_t    fl_wheel_speed;
    uint16_t    fr_wheel_speed;
    uint16_t    rl_wheel_speed;
    uint16_t    rr_wheel_speed;
} vcu2ai_speeds_t;

typedef struct vcu2ai_status_struct
{
    uint8_t                     handshake;
    uint8_t                     shutdown_request; // Not implemented in state machine.TODO: Clarify trigger conditions
    uint8_t                     as_switch_status;
    uint8_t                     ts_switch_status;
    uint8_t                     go_signal;
    uint8_t                     steering_status;
    uint8_t                     as_state;
    uint8_t                     ami_state;
    uint8_t                     fault_status;
    uint8_t                     warning_status; // Not implemented in state machine. TODO: Clarify trigger conditions
    uint8_t                     warn_batt_temp_high; // Not implemented in state machine. Outside Scope
    uint8_t                     warn_batt_soc_low; // Not implemented in state machine. Outside Scope
    uint8_t                     ai_estop_request;
    uint8_t                     hvil_open_fault; // Not implemented in state machine. Outside Scope
    uint8_t                     hvil_short_fault; // Not implemented in state machine. Outside Scope
    uint8_t                     ebs_fault; // Not implemented in state machine. Outside Scope
    uint8_t                     offboard_charger_fault; // Not implemented in state machine. Outside Scope
    uint8_t                     ai_comms_lost;
    uint8_t                     autonomous_braking_fault;
    uint8_t                     mission_status_fault;
    uint8_t                     charge_procedure_fault; // Not implemented in state machine. Outside Scope
    uint8_t                     bms_fault; // Not implemented in state machine. Outside Scope
    uint8_t                     brake_plausibility_fault;
    uint8_t                     shutdown_cause;
} vcu2ai_status_t;

typedef struct vcu2ai_steer_struct
{
    int16_t     angle;
    uint16_t    angle_max;
    int16_t     angle_request;
} vcu2ai_steer_t;

typedef struct vcu2ai_wheel_counts_struct
{
    uint16_t    fl_pulse_count;
    uint16_t    fr_pulse_count;
    uint16_t    rl_pulse_count;
    uint16_t    rr_pulse_count;
} vcu2ai_wheel_counts_t;

typedef struct ai2vcu_data_struct
{
    ai2vcu_status_t ai_status;
    ai2vcu_drive_f_t ai_drive_f;
    ai2vcu_drive_r_t ai_drive_r;
    ai2vcu_steer_t ai_steer;
    ai2vcu_brake_t ai_brake;
} ai2vcu_data_t;

typedef struct vcu2ai_data_struct
{
    vcu2ai_status_t vcu_status;
    vcu2ai_brake_t vcu_brake;
    vcu2ai_drive_f_t vcu_drive_f;
    vcu2ai_drive_r_t vcu_drive_r;
    vcu2ai_speeds_t vcu_speeds;
    vcu2ai_steer_t vcu_steer;
    vcu2ai_wheel_counts_t vcu_wheel_counts;
} vcu2ai_data_t;

static inline void print_ai2vcu_data(const ai2vcu_data_t *data) {
    // Debug function to inspect the data
    printf("ai2vcu_data:\n");
    printf("  ai_status:\n");
    printf("    handshake: %d\n", data->ai_status.handshake);
    printf("    estop_request: %d\n", data->ai_status.estop_request);
    printf("    mission_status: %d\n", data->ai_status.mission_status);
    printf("    direction_request: %d\n", data->ai_status.direction_request);
    printf("    lap_counter: %d\n", data->ai_status.lap_counter);
    printf("    cones_count_actual: %d\n", data->ai_status.cones_count_actual);
    printf("    cones_count_all: %d\n", data->ai_status.cones_count_all);
    printf("    veh_speed_actual: %d\n", data->ai_status.veh_speed_actual);
    printf("    veh_speed_demand: %d\n", data->ai_status.veh_speed_demand);

    printf("  ai_drive_f:\n");
    printf("    front_axle_trq_request: %d\n", data->ai_drive_f.front_axle_trq_request);
    printf("    front_motor_speed_max: %d\n", data->ai_drive_f.front_motor_speed_max);

    printf("  ai_drive_r:\n");
    printf("    rear_axle_trq_request: %d\n", data->ai_drive_r.rear_axle_trq_request);
    printf("    rear_motor_speed_max: %d\n", data->ai_drive_r.rear_motor_speed_max);

    printf("  ai_steer:\n");
    printf("    steer_request: %d\n", data->ai_steer.steer_request);

    printf("  ai_brake:\n");
    printf("    hyd_press_f_req_pct: %d\n", data->ai_brake.hyd_press_f_req_pct);
    printf("    hyd_press_r_req_pct: %d\n", data->ai_brake.hyd_press_r_req_pct);
}

static inline void print_vcu2ai_data(const vcu2ai_data_t *data) {
    printf("vcu_status:\n");
    printf("  handshake: %d\n", data->vcu_status.handshake);
    printf("  shutdown_request: %d\n", data->vcu_status.shutdown_request);
    printf("  as_switch_status: %d\n", data->vcu_status.as_switch_status);
    printf("  ts_switch_status: %d\n", data->vcu_status.ts_switch_status);
    printf("  go_signal: %d\n", data->vcu_status.go_signal);
    printf("  steering_status: %d\n", data->vcu_status.steering_status);
    printf("  as_state: %d\n", data->vcu_status.as_state);
    printf("  ami_state: %d\n", data->vcu_status.ami_state);
    printf("  fault_status: %d\n", data->vcu_status.fault_status);
    printf("  warning_status: %d\n", data->vcu_status.warning_status);
    printf("  warn_batt_temp_high: %d\n", data->vcu_status.warn_batt_temp_high);
    printf("  warn_batt_soc_low: %d\n", data->vcu_status.warn_batt_soc_low);
    printf("  ai_estop_request: %d\n", data->vcu_status.ai_estop_request);
    printf("  hvil_open_fault: %d\n", data->vcu_status.hvil_open_fault);
    printf("  hvil_short_fault: %d\n", data->vcu_status.hvil_short_fault);
    printf("  ebs_fault: %d\n", data->vcu_status.ebs_fault);
    printf("  offboard_charger_fault: %d\n", data->vcu_status.offboard_charger_fault);
    printf("  ai_comms_lost: %d\n", data->vcu_status.ai_comms_lost);
    printf("  autonomous_braking_fault: %d\n", data->vcu_status.autonomous_braking_fault);
    printf("  mission_status_fault: %d\n", data->vcu_status.mission_status_fault);
    printf("  charge_procedure_fault: %d\n", data->vcu_status.charge_procedure_fault);
    printf("  bms_fault: %d\n", data->vcu_status.bms_fault);
    printf("  brake_plausibility_fault: %d\n", data->vcu_status.brake_plausibility_fault);
    printf("  shutdown_cause: %d\n", data->vcu_status.shutdown_cause);

    printf("vcu_brake:\n");
    printf("  hyd_press_f_pct: %d\n", data->vcu_brake.hyd_press_f_pct);
    printf("  hyd_press_f_req_pct: %d\n", data->vcu_brake.hyd_press_f_req_pct);
    printf("  hyd_press_r_pct: %d\n", data->vcu_brake.hyd_press_r_pct);
    printf("  hyd_press_r_req_pct: %d\n", data->vcu_brake.hyd_press_r_req_pct);
    printf("  status_brk: %d\n", data->vcu_brake.status_brk);
    printf("  status_ebs: %d\n", data->vcu_brake.status_ebs);

    printf("vcu_drive_f:\n");
    printf("  front_axle_trq: %d\n", data->vcu_drive_f.front_axle_trq);
    printf("  front_axle_trq_request: %u\n", data->vcu_drive_f.front_axle_trq_request);
    printf("  front_axle_trq_max: %u\n", data->vcu_drive_f.front_axle_trq_max);

    printf("vcu_drive_r:\n");
    printf("  rear_axle_trq: %d\n", data->vcu_drive_r.rear_axle_trq);
    printf("  rear_axle_trq_request: %u\n", data->vcu_drive_r.rear_axle_trq_request);
    printf("  rear_axle_trq_max: %u\n", data->vcu_drive_r.rear_axle_trq_max);

    printf("vcu_speeds:\n");
    printf("  fl_wheel_speed: %u\n", data->vcu_speeds.fl_wheel_speed);
    printf("  fr_wheel_speed: %u\n", data->vcu_speeds.fr_wheel_speed);
    printf("  rl_wheel_speed: %u\n", data->vcu_speeds.rl_wheel_speed);
    printf("  rr_wheel_speed: %u\n", data->vcu_speeds.rr_wheel_speed);

    printf("vcu_steer:\n");
    printf("  angle: %d\n", data->vcu_steer.angle);
    printf("  angle_max: %u\n", data->vcu_steer.angle_max);
    printf("  angle_request: %d\n", data->vcu_steer.angle_request);

    printf("vcu_wheel_counts:\n");
    printf("  fl_pulse_count: %u\n", data->vcu_wheel_counts.fl_pulse_count);
    printf("  fr_pulse_count: %u\n", data->vcu_wheel_counts.fr_pulse_count);
    printf("  rl_pulse_count: %u\n", data->vcu_wheel_counts.rl_pulse_count);
    printf("  rr_pulse_count: %u\n", data->vcu_wheel_counts.rr_pulse_count);
}

static inline void printAmiState(ami_state_e state, int indent) {
    const char* stateNames[] = {
        "NOT_SELECTED", "ACCELERATION", "SKIDPAD", "AUTOCROSS", "TRACK_DRIVE",
        "STATIC_INSPECTION_A", "STATIC_INSPECTION_B", "AUTONOMOUS_DEMO"
    };
    printf("%*sMission: %s\n", indent * 4, "", stateNames[state]);
}

static inline void printAsState(as_state_e asState, int indent) {
    const char* asStateNames[] = {
        "Undefined",  // Index 0 - not used
        "Off",        // AS_OFF
        "Ready",      // AS_READY
        "Driving",    // AS_DRIVING
        "Emergency Brake", // AS_EMERGENCY_BRAKE
        "Finished"    // AS_FINISHED
    };
    printf("%*sAutonomous System State: %s\n", indent * 4, "", asStateNames[asState]);
}

static inline void printStatusBit(status_bit_e status, int indent) {
    const char* statusNames[] = {"Off", "On"};
    printf("%*s%s\n", indent * 4, "", statusNames[status]);
}

#endif