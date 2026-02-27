
#define NWHEEL 4


#define FMI2_FUNCTION_PREFIX MyBrakeSrc_FMU_
#define MODEL_GUID "{8dda525c-73b1-4999-ba15-404c3219fe6c}"

// define model size
#define NUMBER_OF_REALS			NWHEEL+NWHEEL+1
#define NUMBER_OF_INTEGERS		0
#define NUMBER_OF_BOOLEANS		0
#define NUMBER_OF_STRINGS		0
#define NUMBER_OF_STATES		0
#define NUMBER_OF_EVENT_INDICATORS	0

// include fmu header files, typedefs and macros
#include "fmu2Template.h"

// define all model variables and their value references
// conventions used here:
// - if x is a variable, then macro x_ is its variable reference
// - the vr of a variable is its index in array  r, i, b or s
// - if k is the vr of a real state, then k+1 is the vr of its derivative

// Parameters
#define TrqDistrib_FL_	0	// a.k.a. Pedal2Trq_FL
#define TrqDistrib_FR_	1
#define TrqDistrib_RL_	2
#define TrqDistrib_RR_	3

// Inputs
#define Pedal_		4

// Outputs
#define Trq_WB_FL_	5
#define Trq_WB_FR_	6
#define Trq_WB_RL_	7
#define Trq_WB_RR_	8


#define STATES { }


// called by fmi2Instantiate
// Set values for all variables that define a start value
// Settings used unless changed by fmi2SetX before fmi2EnterInitializationMode
static void
setStartValues(ModelInstance *comp) {
    r(TrqDistrib_FL_) = 1000;
    r(TrqDistrib_FR_) = 1000;
    r(TrqDistrib_RL_) = 800;
    r(TrqDistrib_RR_) = 800;
    r(Pedal_)     = 0;
    r(Trq_WB_FL_) = 0;
    r(Trq_WB_FR_) = 0;
    r(Trq_WB_RL_) = 0;
    r(Trq_WB_RR_) = 0;
}


// called by fmi2GetReal, fmi2GetInteger, fmi2GetBoolean, fmi2GetString, fmi2ExitInitialization
// if setStartValues or environment set new values through fmi2SetXXX.
// Lazy set values for all variable that are computed from other variables.
static void
calculateValues(ModelInstance *comp) {
    if (comp->state == modelInitializationMode) {

        // set first time event, if any, using comp->eventInfo.nextEventTime
        comp->eventInfo.nextEventTimeDefined = fmi2True;
        comp->eventInfo.nextEventTime = -1;
    }
}


// called by fmi2GetReal, fmi2GetContinuousStates and fmi2GetDerivatives
static fmi2Real
getReal(ModelInstance* comp, fmi2ValueReference vr)
{
    return 0<=vr && vr<NUMBER_OF_REALS ? r(vr) : 0;
}


// used to set the next time event, if any.
static void
eventUpdate(ModelInstance *comp, fmi2EventInfo *eventInfo, int isTimeEvent, int isNewEventIteration)
{
    int i;
    for (i=0; i<NWHEEL; i++) {
        int i_trqdistrib = TrqDistrib_FL_ + i;
        int i_trq_wb     = Trq_WB_FL_     + i;

        r(i_trq_wb) = r(i_trqdistrib) * r(Pedal_);
    }
}


// include code that implements the FMI based on the above definitions
#include "fmu2Template.c"
