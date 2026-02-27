#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <pthread.h>
// #include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>
#include <inttypes.h>
// #include "utils/scheduling.h"
// #include "utils/flags.h"
#include "vehicle_state.h"
#include "messages.h"

typedef enum
{
    SM_MASTER_SWITCH_STATE_ALL_OFF, // All systems are off
    // States for master switches sequence during startup
    SM_MASTER_SWITCH_STATE_ASMS_ON,   // ASMS is on, others are off
    SM_MASTER_SWITCH_STATE_TSMS_ON,   // ASMS and TSMS are on, LVMS is off
    SM_MASTER_SWITCH_STATE_LVMS_ON,   // ASMS, TSMS, and LVMS are all on; vehicle fully powered
    SM_MASTER_SWITCH_STATE_UNDEFINED, // Undefined state, used for error checking or default
} sm_master_switch_state_e;

typedef enum
{
    SIREN_LATCH_NONE,
    SIREN_LATCH_ESTOP,
} sm_siren_latch_e;

typedef struct
{
    sm_master_switch_state_e master_switch_state;
    ami_operational_mode_t op_mode;
    as_state_e autonomous_state;
    bool ai_connected;       // retains connection for up to 10 cycles of invalid messages (wrong handshake bit)
    bool ai_message_invalid; // per cycle
    bool motor_control_enabled;
    bool steering_control_enabled;
    bool brakes_locked;
    bool speed_capped;           // low speed mode for joystick driving. TODO: Vehicle model must cap speed demands at walking space
    bool lock_all_user_controls; // extra lock over controls: needed for autonomous state machine
    // This is for where we are in a state where motor controls are unlocked and red TSAL light is flashing,
    // but AI hasn't completed state transition song and dance to AS_DRIVE
    bool previous_go_signal;
    uint64_t handshake_miss_counter;
    uint64_t siren_counter;
    uint64_t siren_auto_switch_off_afer;
    uint64_t siren_auto_to_beeping_afer;
    sm_siren_latch_e siren_latch;
    uint64_t as_ready_counter;
    uint64_t shutdown_actions_counter;

} state_machine_hidden_state_t;

static inline void printSMMasterSwitchState(sm_master_switch_state_e state, int indent)
{
    const char *stateNames[] = {
        "All Off", "ASMS On", "TSMS On", "LVMS On", "Undefined"};
    printf("%*sMaster Switch State: %s\n", indent * 4, "", stateNames[state]);
}

static inline void printStateMachineHiddenState(state_machine_hidden_state_t state, int indent)
{
    printf("%*sMaster Switch State: ", indent * 4, "");
    printSMMasterSwitchState(state.master_switch_state, 0);
    printf("%*sOperational Mode: ", indent * 4, "");
    printAMI_OperationalMode(state.op_mode, 0);
    printf("%*sAutonomous State: %d\n", indent * 4, "", state.autonomous_state);
    printf("%*sMotor Control Enabled: %s\n", indent * 4, "", state.motor_control_enabled ? "true" : "false");
    printf("%*sSteering Control Enabled: %s\n", indent * 4, "", state.steering_control_enabled ? "true" : "false");
    printf("%*sBrakes Locked: %s\n", indent * 4, "", state.brakes_locked ? "true" : "false");
    printf("%*sSpeed Capped: %s\n", indent * 4, "", state.speed_capped ? "true" : "false");
    printf("%*sLock All User Controls: %s\n", indent * 4, "", state.lock_all_user_controls ? "true" : "false");
    printf("%*sPrevious GO Signal: %s\n", indent * 4, "", state.previous_go_signal ? "true" : "false");
    printf("%*sHandshake Miss Counter: %" PRIu64 "\n", indent * 4, "", state.handshake_miss_counter);
}

static inline void __sm_startup_shutdown(state_machine_hidden_state_t *state, vehicle_state_t *vehicle_state)
{
    if ((state->op_mode == AMI_OP_MODE_SHUTDOWN_ACTIONS) || (state->op_mode == AMI_OP_MODE_SHUTDOWN_OFF))
    {
        // TODO: Add timing emulation for shutdown. and latch the shutdown state
        if (!(bool)vehicle_state->master_switch_e.LVMSState)
        {
            //TODO: there neds to be a transition here to shutdown off BEFORE all off
            state->master_switch_state = SM_MASTER_SWITCH_STATE_ALL_OFF;
            state->op_mode = AMI_OP_MODE_OFF;
        }

        // TODO: Revise the logic for applying the brakes or not. I don't thin
        return;
    }
    // Enforce turning on AS->TS->LV in that order
    if (!(bool)vehicle_state->master_switch_e.ASMSState)
    {
        if ((state->op_mode != AMI_OP_MODE_OFF) && (state->op_mode != AMI_OP_MODE_UNDEFINED))
        {
            state->op_mode = AMI_OP_MODE_SHUTDOWN_ACTIONS;
        };
        state->master_switch_state = SM_MASTER_SWITCH_STATE_ALL_OFF;
        return;
    }
    if (!(bool)vehicle_state->master_switch_e.TSMSState)
    {
        state->master_switch_state = SM_MASTER_SWITCH_STATE_ASMS_ON;
        return;
    }
    if (!(bool)vehicle_state->master_switch_e.LVMSState)
    {
        state->master_switch_state = SM_MASTER_SWITCH_STATE_TSMS_ON;
        return;
    }
    state->master_switch_state = SM_MASTER_SWITCH_STATE_LVMS_ON;
    return;
}

static inline void __sm_op_mode_transition(
    state_machine_hidden_state_t *hidden_state,
    vehicle_state_t *vehicle_state,
    ai2vcu_data_t *ai2vcu,
    vcu2ai_data_t *vcu2ai)
{
    // Reset per-cycle flags
    hidden_state->ai_message_invalid = false;

    // Sets vehicle operation mode based on state of initialization, and current MPP.
    // For simple op modes, we set internal state flags here.
    // For more complex ones, we call functions to handle their state machines

    // Set default output values unless explicitly asisgned by a state here:
    // Latch states: if we're in these states, ensure we stay there
    // Order matters; priority
    // Latch unknown state
    if (hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_UNDEFINED)
    {
        hidden_state->op_mode = AMI_OP_MODE_UNDEFINED;
        hidden_state->autonomous_state = AS_OFF;
        vehicle_state->siren = SIREN_OFF;
        return;
    }
    // Latch off state
    if (hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_ALL_OFF)
    {
        vehicle_state->siren = SIREN_OFF;
        hidden_state->op_mode = AMI_OP_MODE_OFF;
        hidden_state->brakes_locked = true; // TODO: Vefiry this! There must be states where the brakes are unlocked when the vehicle is off no?
        hidden_state->steering_control_enabled = false;
        hidden_state->motor_control_enabled = false;
        hidden_state->lock_all_user_controls = true;
        hidden_state->autonomous_state = AS_OFF;
        hidden_state->shutdown_actions_counter = 0;

        return;
    }
    if ((hidden_state->op_mode == AMI_OP_MODE_SHUTDOWN_ACTIONS))
    {
        // TODO: Add a post intialization delay latch (to simulate the VCU shutting down)
        if (hidden_state->shutdown_actions_counter > 300){
            hidden_state->op_mode = AMI_OP_MODE_SHUTDOWN_OFF;
        }
        hidden_state->brakes_locked = true;
        hidden_state->steering_control_enabled = false;
        hidden_state->motor_control_enabled = false;
        hidden_state->lock_all_user_controls = true;
        hidden_state->autonomous_state = AS_OFF;
        vehicle_state->siren = SIREN_OFF;
        hidden_state->shutdown_actions_counter++;
        return;
    }
    if ((hidden_state->op_mode == AMI_OP_MODE_SHUTDOWN_OFF))
    {
        // TODO: Add a post intialization delay latch (to simulate the VCU shutting down)
        hidden_state->op_mode = AMI_OP_MODE_SHUTDOWN_OFF;
        hidden_state->brakes_locked = true;
        hidden_state->steering_control_enabled = false;
        hidden_state->motor_control_enabled = false;
        hidden_state->lock_all_user_controls = true;
        hidden_state->autonomous_state = AS_OFF;
        hidden_state->shutdown_actions_counter = 0;
        return;
    }


    // Rest of these are actual live operating modes. We need to traverse the logic for them remaining enabled
    // TODO: Add a post intialization delay latch (to simulate the VCU starting up)

    // Select operating mode based on MPP
    if (hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_LVMS_ON)
    {
        if ((
            (hidden_state->op_mode == AMI_OP_MODE_STARTING_UP) || (hidden_state->op_mode == AMI_OP_MODE_OFF)) &&
            !vehicle_state->EStop.watchdog_detected
        ){
            hidden_state->op_mode = AMI_OP_MODE_SHUTDOWN_OFF; // TODO: check this
            return;
        }
        // Latch Emergency state
        if ((hidden_state->op_mode == AMI_OP_MODE_EMERGENCY) ||
            !vehicle_state->EStop.watchdog_detected ||
            vehicle_state->EStop.estop_signalled ||
            (ai2vcu->ai_status.estop_request == ESTOP_YES) ||
            ((hidden_state->handshake_miss_counter >= 50) && (hidden_state->autonomous_state != AS_OFF)) //
        )
        {
            hidden_state->op_mode = AMI_OP_MODE_EMERGENCY;
            hidden_state->autonomous_state = AS_EMERGENCY_BRAKE; // need to stick this here as we won't call autonomous state machine anymore from emergency mode!
            hidden_state->brakes_locked = true;
            hidden_state->steering_control_enabled = false;
            hidden_state->motor_control_enabled = false;
            hidden_state->lock_all_user_controls = true;
            if (hidden_state->siren_latch != SIREN_LATCH_ESTOP)
            {
                vehicle_state->siren = SIREN_CONTINUOUS;
                hidden_state->siren_counter = 0;
                hidden_state->siren_auto_switch_off_afer = 1500; // 15 seconds
                hidden_state->siren_latch = SIREN_LATCH_ESTOP;
            }
            return;
        }

        if (vehicle_state->MPPType == MPP_JoystickUmbilical)
        {
            // if (vehicle_state->master_switch_e.AIMSState == OFF)
            // {
                if (vehicle_state->joystick_dead_mans_switch_pressing)
                {
                    // TODO: Simulate timing logic for holding the dead man's switch for 5 seconds to enter the state,
                    // then latching logic to stay in until released
                    hidden_state->op_mode = AMI_OP_MODE_DRIVE_MANUAL;
                    hidden_state->brakes_locked = false; // Unlocks brakes when we're in an active mode.
                    hidden_state->motor_control_enabled = true;
                    hidden_state->steering_control_enabled = true;
                    hidden_state->speed_capped = true;
                    hidden_state->lock_all_user_controls = false;
                    hidden_state->autonomous_state = AS_OFF;
                    return;
                }
                else
                {
                    hidden_state->op_mode = AMI_OP_MODE_PUSHBAR;
                    hidden_state->motor_control_enabled = false;
                    hidden_state->steering_control_enabled = true;
                    hidden_state->brakes_locked = false; // Unlocks brakes when we're in an active mode.
                    hidden_state->lock_all_user_controls = false;
                    hidden_state->autonomous_state = AS_OFF;
                    return;
                }
            // }
            // else
            // {
            //     fprintf(stderr, "[Not Implemented Error!] TODO: @AgimG: Gather data for what happens when AIMS is on while Umbilical is plugged in!");
            //     hidden_state->op_mode = AMI_OP_MODE_UNDEFINED;
            //     hidden_state->autonomous_state = AS_OFF;
            //     return;
            // }
        }
        /*The following is a list of operating conditions that are not permissible when the ADS-DV is in its autonomous
        driving state (AS_DRIVING).  If any of these conditions are met, the VCU will execute an emergency stop to
        bring the vehicle to a halt.*/
        if (hidden_state->autonomous_state == AS_DRIVING)
        {
            /*AUTONOMOUS_BRAKING_FAULT  AI sets the DIRECTION_REQUEST (AI2VCU_Status message) to
            NEUTRAL while any of the wheel speed measurements are above 10rpm. */
            if (
                (vcu2ai->vcu_speeds.fl_wheel_speed > 10) &&
                (vcu2ai->vcu_speeds.fr_wheel_speed > 10) &&
                (vcu2ai->vcu_speeds.rl_wheel_speed > 10) &&
                (vcu2ai->vcu_speeds.rr_wheel_speed > 10) &&
                (ai2vcu->ai_status.direction_request == DIRECTION_NEUTRAL))
            {
                vcu2ai->vcu_status.autonomous_braking_fault = 1;
                hidden_state->op_mode = AMI_OP_MODE_EMERGENCY;
            };
            /*AI_COMMS_LOST_FAULT  10 consecutive messages are missed for any of the five AI2VCU CAN
            messages, or the AI handshake bit does not follow the VCU handshake within 100ms.*/
            if (hidden_state->handshake_miss_counter >= 50)
            {
                hidden_state->ai_connected = false;
                vcu2ai->vcu_status.ai_comms_lost = 1;
                hidden_state->op_mode = AMI_OP_MODE_EMERGENCY; // TODO: this is off by 1 cycle. Move it elsewhere?
            };
            /*BRAKE_PLAUSIBILITY_FAULT  When operating the drive motors in torque control mode, this fault
            is triggered if either front or rear drive motor torque request is greater than zero, and either hydraulic
            braking request (front or rear axle) is greater than zero. */
            if (
                ((ai2vcu->ai_drive_f.front_axle_trq_request > 0) || (ai2vcu->ai_drive_r.rear_axle_trq_request > 0)) &&
                ((ai2vcu->ai_brake.hyd_press_f_req_pct > 0) || (ai2vcu->ai_brake.hyd_press_r_req_pct > 0)))
            {
                vcu2ai->vcu_status.brake_plausibility_fault = 1;
                hidden_state->op_mode = AMI_OP_MODE_EMERGENCY;
            }
        }
        if (vehicle_state->MPPType == MPP_AutonomousDriving)
        {
            // Logic for autonomous or auxiliary mode here
            hidden_state->speed_capped = false;
            hidden_state->brakes_locked = false; // Unlocks brakes when we're in an active mode.

            if (vcu2ai->vcu_status.handshake == ai2vcu->ai_status.handshake)
            {
                hidden_state->ai_connected = true;
                hidden_state->ai_message_invalid = false;
                hidden_state->op_mode = AMI_OP_MODE_AUTONOMOUS;
                hidden_state->motor_control_enabled = true;  // TSAL red light is flashing
                if (hidden_state->autonomous_state != AS_DRIVING) hidden_state->lock_all_user_controls = true; // We don't allow user to go until they are AS_DRIVING

                switch (ai2vcu->ai_status.mission_status)
                {
                case MISSION_NOT_SELECTED:
                    hidden_state->autonomous_state = AS_OFF;
                    break;
                case MISSION_SELECTED:
                    if (vehicle_state->AMIScreenState.mission != AMI_NOT_SELECTED)
                    { //TODO: Verify this
                        switch (hidden_state->autonomous_state)
                        {
                        case AS_READY:
                            // TODO: Check whether the go off->on latches when in this state (i assume not, but best to confirm)
                            if ((ai2vcu->ai_drive_f.front_axle_trq_request == 0) &&
                                (ai2vcu->ai_drive_r.rear_axle_trq_request == 0) &&
                                (ai2vcu->ai_steer.steer_request == 0) &&
                                (ai2vcu->ai_status.direction_request == DIRECTION_NEUTRAL) &&
                                (abs(vcu2ai->vcu_steer.angle) <= 5) &&
                                ((vehicle_state->EStop.go_signalled) && (!hidden_state->previous_go_signal)) &&
                                (hidden_state->as_ready_counter >= 500) // 5 seconds
                            )
                            {
                                hidden_state->autonomous_state = AS_DRIVING;
                                vehicle_state->siren = SIREN_CONTINUOUS;
                                hidden_state->siren_counter = 0;
                                hidden_state->siren_auto_to_beeping_afer = 300; // 3 seconds
                                hidden_state->lock_all_user_controls = false;
                                hidden_state->motor_control_enabled = true;
                                hidden_state->steering_control_enabled = true;
                                hidden_state->speed_capped = false;
                            }
                            break;
                        case AS_OFF:
                            hidden_state->autonomous_state = AS_READY;
                            hidden_state->as_ready_counter = 0;
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        hidden_state->autonomous_state = AS_OFF;
                    }
                    break;
                case MISSION_RUNNING:
                    break;
                case MISSION_FINISHED:
                    switch (hidden_state->autonomous_state)
                    {
                    case AS_DRIVING:
                        if (
                            (vcu2ai->vcu_speeds.fl_wheel_speed < 10) &&
                            (vcu2ai->vcu_speeds.fr_wheel_speed < 10) &&
                            (vcu2ai->vcu_speeds.rl_wheel_speed < 10) &&
                            (vcu2ai->vcu_speeds.rr_wheel_speed < 10))
                        {
                            hidden_state->autonomous_state = AS_FINISHED;
                        }
                        else
                        {
                            /*
                            MISSION_STATUS_FAULT  AI sets the MISSION_STATUS (AI2VCU_Status message) to FINISHED
                            while any of the wheel speed measurements are above 10rpm.

                            See: section 4 of the spec*/
                            vcu2ai->vcu_status.mission_status_fault = 1;
                            hidden_state->op_mode = AMI_OP_MODE_EMERGENCY;
                        }
                        break;
                    case AS_READY:
                        // TODO: Verify this. The user manual says we can't transition from AS_READY to AS_FINISHED
                        // but I think I remember we did once... check and verify.
                        hidden_state->autonomous_state = AS_READY;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    hidden_state->op_mode = AMI_OP_MODE_UNDEFINED;
                    hidden_state->autonomous_state = AS_OFF;
                    break;
                }

                /*
                AUTONOMOUS_BRAKING_FAULT  AI sets the DIRECTION_REQUEST (AI2VCU_Status message) to
                NEUTRAL while any of the wheel speed measurements are above 10rpm.
                */
            }
            else
            {

                if ((hidden_state->op_mode == AMI_OP_MODE_AUTONOMOUS) && hidden_state->ai_connected)
                {
                    // flag current ai2vcu message as invalid and wait
                    hidden_state->ai_message_invalid = true;
                }
                else
                {
                    hidden_state->op_mode = AMI_OP_MODE_AUXILIARY;
                    hidden_state->autonomous_state = AS_OFF;
                }
            }
            // Internal flag updates
            hidden_state->previous_go_signal = vehicle_state->EStop.go_signalled;
        }
    }
    // TODO: Test whether we can actually move between states by swapping MPP. Currently assuming we can.
}

static inline void __sm_map_hidden_to_visible_outputs(state_machine_hidden_state_t *hidden_state, vehicle_state_t *vehicle_state, vcu2ai_data_t *vcu2ai, ai2vcu_data_t *ai2vcu)
{
    // ====================Vehicle State=========================
    // AMI
    vehicle_state->AMIScreenState.op_mode = hidden_state->op_mode;
    vehicle_state->AMIScreenState.autonomous_state = hidden_state->autonomous_state;
    // ASSI
    _updateASSIState(hidden_state->autonomous_state, &vehicle_state->ASSILedState);
    if ((hidden_state->autonomous_state == AS_READY) || (hidden_state->autonomous_state == AS_DRIVING))
    {
        if ((hidden_state->as_ready_counter >= 500) && (hidden_state->as_ready_counter <= 600))
        {
            vehicle_state->ASSILedState = LED_YELLOW_AND_BLUE_CONTINUOUS;
        }
        if (hidden_state->as_ready_counter < 700)
        {
            hidden_state->as_ready_counter++;
        }
    }

    // Locks
    vehicle_state->vehicle_state_actuator_locks.brakes_locked = hidden_state->brakes_locked;
    vehicle_state->vehicle_state_actuator_locks.lock_all_user_controls = hidden_state->lock_all_user_controls;
    vehicle_state->vehicle_state_actuator_locks.motor_control_enabled = hidden_state->motor_control_enabled;
    vehicle_state->vehicle_state_actuator_locks.speed_capped = hidden_state->speed_capped;
    vehicle_state->vehicle_state_actuator_locks.steering_control_enabled = hidden_state->steering_control_enabled;

    /*TSAL = Tractive System Active Light
        This indicator shows the status of the electric drivetrain:
        LED colour Meaning:
        Green=Drive motors are disabled
        Red (flashing)= Drive motors are enabled, and the vehicle is capable of moving under its own power*/
    if (hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_ALL_OFF)
        vehicle_state->TSALLedState = TSAL_OFF;
    if ((hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_LVMS_ON) && !hidden_state->motor_control_enabled)
        vehicle_state->TSALLedState = TSAL_GREEN;
    if ((hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_LVMS_ON) && hidden_state->motor_control_enabled)
        vehicle_state->TSALLedState = TSAL_RED_FLASHING;

    // Siren
    // Check to autodisable siren
    if (hidden_state->siren_auto_switch_off_afer != 0)
    {
        if (hidden_state->siren_counter >= hidden_state->siren_auto_switch_off_afer)
        {
            vehicle_state->siren = SIREN_OFF;
            hidden_state->siren_auto_switch_off_afer = 0;
        }
        hidden_state->siren_counter++;
    }
    if (hidden_state->siren_auto_to_beeping_afer != 0)
    {
        if (hidden_state->siren_counter >= hidden_state->siren_auto_to_beeping_afer)
        {
            vehicle_state->siren = SIREN_BEEPING;
            hidden_state->siren_auto_to_beeping_afer = 0;
        }
        hidden_state->siren_counter++;
    }
    // vcu2ai

    if (vcu2ai->vcu_status.handshake == ai2vcu->ai_status.handshake)
    {
        // handshake successful
        hidden_state->handshake_miss_counter = 0;
        vcu2ai->vcu_status.handshake = (handshake_receive_bit_e)(!(bool)vcu2ai->vcu_status.handshake); // toggle
    }
    else
    {
        hidden_state->handshake_miss_counter++;
        if (hidden_state->handshake_miss_counter >= 50)
        {
            hidden_state->ai_connected = false;

            // vehicle_state->ai_connected = true;
            // vcu2ai->vcu_status.ai_comms_lost = 1;
            // TODO: Check if this fault is raised if we're not in the AS_DRIVING state (i have raised it in that state elsewhere)

            // TODO: @ COnner, I need a check for this in the CAN module as I can't see it from my end.
            // The VCU also checks that the AI Computer is regularly sending the five ‘AI2VCU’ CAN messages, and will raise the ‘AI_COMMS_LOST’ fault if 10 consecutive messages are missed.
        }
    }
    vehicle_state->ai_connected = hidden_state->ai_connected;

    vcu2ai->vcu_status.as_switch_status = vehicle_state->master_switch_e.ASMSState;
    vcu2ai->vcu_status.ts_switch_status = vehicle_state->master_switch_e.TSMSState;
    vcu2ai->vcu_status.go_signal = (res_go_signal_bit_e)vehicle_state->EStop.go_signalled;
    vcu2ai->vcu_status.steering_status = (uint8_t)(hidden_state->steering_control_enabled && !hidden_state->lock_all_user_controls);
    vcu2ai->vcu_status.as_state = hidden_state->autonomous_state;
    vcu2ai->vcu_status.ami_state = vehicle_state->AMIScreenState.mission;
    vcu2ai->vcu_status.ai_estop_request = (uint8_t)hidden_state->op_mode == AMI_OP_MODE_EMERGENCY;

    // Shutdown Cause
    if (hidden_state->op_mode == AMI_OP_MODE_SHUTDOWN_ACTIONS)
        vcu2ai->vcu_status.shutdown_cause = 1; // TODO: Ask Ian or Adam about this because I do not understand what the spec means here...
    if (vcu2ai->vcu_status.hvil_open_fault)
        vcu2ai->vcu_status.shutdown_cause = 2; // Not Implemented
    if (vcu2ai->vcu_status.hvil_short_fault)
        vcu2ai->vcu_status.shutdown_cause = 3; // Not Implemented
    if (vcu2ai->vcu_status.ebs_fault)
        vcu2ai->vcu_status.shutdown_cause = 4; // Not Implemented
    if (vcu2ai->vcu_status.offboard_charger_fault)
        vcu2ai->vcu_status.shutdown_cause = 5; // Not Implemented
    if (vcu2ai->vcu_status.ai_comms_lost)
        vcu2ai->vcu_status.shutdown_cause = 6;
    if (vcu2ai->vcu_status.autonomous_braking_fault)
        vcu2ai->vcu_status.shutdown_cause = 7;
    if (vcu2ai->vcu_status.mission_status_fault)
        vcu2ai->vcu_status.shutdown_cause = 8;
    if (vcu2ai->vcu_status.charge_procedure_fault)
        vcu2ai->vcu_status.shutdown_cause = 9; // Not Implemented
    if (vcu2ai->vcu_status.bms_fault)
        vcu2ai->vcu_status.shutdown_cause = 10; // Not Implemented
    if (vcu2ai->vcu_status.brake_plausibility_fault)
        vcu2ai->vcu_status.shutdown_cause = 11;

    vcu2ai->vcu_status.fault_status = (uint8_t)(vcu2ai->vcu_status.shutdown_cause > 1);
    if (vcu2ai->vcu_status.fault_status){
        hidden_state->op_mode = AMI_OP_MODE_EMERGENCY;
    }

    // Hard reset
    if ((hidden_state->op_mode == AMI_OP_MODE_OFF) && (hidden_state->master_switch_state == SM_MASTER_SWITCH_STATE_ALL_OFF))
    {
        memset(vcu2ai, 0, sizeof(*vcu2ai));
        vcu2ai->vcu_steer.angle_max = 27.1; // TODO hack
    }
}

#define MANUAL_MODE_SPEED_LIMIT 50

static inline void __sm_squash_invalid_ai2vcu_commands(state_machine_hidden_state_t *hidden_state, ai2vcu_data_t *ai2vcu)
{
    // Based on vehicle state, we choose whether to allow ai2vcu commands to propagate to mock actuators.
    // This is all done with flags from state machine which will say what's allowed

    static ai2vcu_data_t old_ai2vcu = {0};

    if (hidden_state->lock_all_user_controls || (ai2vcu->ai_status.direction_request == DIRECTION_NEUTRAL))
    {
        // brakes
        ai2vcu->ai_brake.hyd_press_f_req_pct = 100;
        ai2vcu->ai_brake.hyd_press_r_req_pct = 100;
        // torque
        ai2vcu->ai_drive_f.front_axle_trq_request = 0;
        ai2vcu->ai_drive_f.front_motor_speed_max = 0;
        ai2vcu->ai_drive_r.rear_axle_trq_request = 0;
        ai2vcu->ai_drive_r.rear_motor_speed_max = 0;
        // steer
        ai2vcu->ai_steer.steer_request = 0;
    }
    else
    {
        // Controls unlocked
        if (!hidden_state->motor_control_enabled)
        {
            // torque //brakes are not necessarily locked
            ai2vcu->ai_status.direction_request = 0;
            ai2vcu->ai_drive_f.front_axle_trq_request = 0;
            ai2vcu->ai_drive_f.front_motor_speed_max = 0;
            ai2vcu->ai_drive_r.rear_axle_trq_request = 0;
            ai2vcu->ai_drive_r.rear_motor_speed_max = 0;
        }
        if (!hidden_state->steering_control_enabled)
        {
            ai2vcu->ai_steer.steer_request = old_ai2vcu.ai_steer.steer_request; // do nothing (not steer to zero; do NOTHING)
        }
        if (hidden_state->brakes_locked)
        {
            // brakes
            ai2vcu->ai_brake.hyd_press_f_req_pct = 100;
            ai2vcu->ai_brake.hyd_press_r_req_pct = 100;
            // torque
            ai2vcu->ai_drive_f.front_axle_trq_request = 0;
            ai2vcu->ai_drive_f.front_motor_speed_max = 0;
            ai2vcu->ai_drive_r.rear_axle_trq_request = 0;
            ai2vcu->ai_drive_r.rear_motor_speed_max = 0;
        }
        if (hidden_state->speed_capped)
        {
            ai2vcu->ai_drive_f.front_motor_speed_max = MANUAL_MODE_SPEED_LIMIT;
            ai2vcu->ai_drive_r.rear_motor_speed_max = MANUAL_MODE_SPEED_LIMIT;
        }
        if (hidden_state->ai_message_invalid && hidden_state->autonomous_state == AS_DRIVING)
        {
            // This is a missed cycle. ai2vcu commands are invalid. Overwrite them with prior cycle
            (*ai2vcu) = old_ai2vcu;
        }
    }
    old_ai2vcu = *ai2vcu;
}

typedef struct
{
    // Mock IO Components
    vehicle_state_t *vehicle_state;
    // pthread_mutex_t *vehicle_state_mutex;

    // Mapped CAN data components
    ai2vcu_data_t *ai2vcu;
    vcu2ai_data_t *vcu2ai;

    // persistent state
    state_machine_hidden_state_t *hidden_state;
} state_machine_kwargs_t;

typedef struct
{
    ai2vcu_data_t *ai2vcu;
    vcu2ai_data_t *vcu2ai;
    state_machine_hidden_state_t hidden_state;
    vehicle_state_t vehicle_state;
} state_machine_retval_t;

static inline state_machine_retval_t state_machine_iteration(state_machine_kwargs_t *kwargs)
{
    // pthread_mutex_lock(kwargs->vehicle_state_mutex);

    // Process State machines
    __sm_startup_shutdown(kwargs->hidden_state, kwargs->vehicle_state);
    __sm_op_mode_transition(kwargs->hidden_state, kwargs->vehicle_state, kwargs->ai2vcu, kwargs->vcu2ai);
    __sm_map_hidden_to_visible_outputs(kwargs->hidden_state, kwargs->vehicle_state, kwargs->vcu2ai, kwargs->ai2vcu);
    __sm_squash_invalid_ai2vcu_commands(kwargs->hidden_state,kwargs->ai2vcu);
    // pthread_mutex_unlock(kwargs->vehicle_state_mutex);
    state_machine_retval_t retval = {
        .ai2vcu = kwargs->ai2vcu,
        .vcu2ai = kwargs->vcu2ai,
        .hidden_state = *kwargs->hidden_state,
        .vehicle_state = *kwargs->vehicle_state};
    return retval;
}