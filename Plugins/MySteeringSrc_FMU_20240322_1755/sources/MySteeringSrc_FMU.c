
#define CM_HAS_SINCOS 0		// Suppress warning for 32-bit targets.
#include "MathUtils.h"


// define class name and unique id
#define MODEL_IDENTIFIER MySteeringSrc_FMU
#define MODEL_GUID "{fdd63009-20c9-4231-8ae8-5192806f060a}"

// define model size
#define NUMBER_OF_REALS			33
#define NUMBER_OF_INTEGERS		0
#define NUMBER_OF_BOOLEANS		0
#define NUMBER_OF_STRINGS		0
#define NUMBER_OF_STATES		0
#define NUMBER_OF_EVENT_INDICATORS	0

// include fmu header files, typedefs and macros
#include "fmuTemplate.h"

// define all model variables and their value references
// conventions used here:
// - if x is a variable, then macro x_ is its variable reference
// - the vr of a variable is its index in array  r, i, b or s
// - if k is the vr of a real state, then k+1 is the vr of its derivative

// Parameters
#define iRack2StWhl_		0
#define Irot_			1
#define d_			2
#define RackRange_0_		3
#define RackRange_1_		4
#define TrqAmplify_		5
#define iSteer2Rack_		6

// Inputs
#define L_Inert_		11
#define R_Inert_		12
#define L_Frc_			13
#define R_Frc_			14
#define Trq_			15
#define PosSign_		16

// Outputs
#define TrqStatic_		20
#define L_iSteer2q_		21
#define R_iSteer2q_		22
#define L_q_			23
#define L_qp_			24
#define L_qpp_			25
#define R_q_			26
#define R_qp_			27
#define R_qpp_			28
#define Ang_			29
#define AngVel_			30
#define AngAcc_			31

// Parameters (intern)
// #define q_
// #define qp_
// #define qpp_

#define STATES {}


// called by fmiInstantiateModel
// Set values for all variables that define a start value
// Settings used unless changed by fmiSetX before fmiInitialize
static void
setStartValues (ModelInstance *comp)
{
//     r(q_) = 0;
//     r(qp_) = 0;
//     r(qpp_) = 0;
}


// called by fmiInitialize() after setting eventInfo to defaults
// Used to set the first time event, if any.
static void
initialize (ModelInstance *comp, fmiEventInfo *eventInfo)
{
    eventInfo->upcomingTimeEvent = fmiTrue;
    eventInfo->nextEventTime = -1;
}


// called by fmiGetReal, fmiGetContinuousStates and fmiGetDerivatives
static fmiReal
getReal (ModelInstance *comp, fmiValueReference vr)
{
    return 0<=vr && vr<NUMBER_OF_REALS ? r(vr) : 0;
}


// called by fmiEventUpdate() after setting eventInfo to defaults
// Used to set the next time event, if any.
static void
eventUpdate (ModelInstance *comp, fmiEventInfo *eventInfo)
{
    double val, Frc, mass;
    static double q=0, qp=0, qpp=0, lastT;
    const double kRackBuf = 1e6;
    const double dRackBuf = 1e4;
    double dt = (comp->time - lastT);

    r(iSteer2Rack_) = 1.0/r(iRack2StWhl_) * r(PosSign_);

    /*** Kinematics */
    mass = r(Irot_)/(r(iSteer2Rack_)*r(iSteer2Rack_)) + r(L_Inert_) + r(R_Inert_);

    /*** Kinetics */
    Frc	=  r(TrqAmplify_) * r(Trq_) / r(iSteer2Rack_)
    	+  (r(L_Frc_) + r(R_Frc_))
    	-  r(d_)/ r(iSteer2Rack_) * qp;

    /*** Limitation of rack buffers */
    if (q < r(RackRange_0_)) {
	double val = q - r(RackRange_0_);
	Frc += - kRackBuf * val - dRackBuf * qp;

    } else if (q > r(RackRange_1_)) {
	double val = q - r(RackRange_1_);
	Frc += - kRackBuf * val - dRackBuf * qp;
    }

    /*** DOF equation */
    qpp =	Frc / mass;

    /*** Integration */
    qp +=	qpp * dt;
    q +=	qp  * dt;

    /*** Assignment */
    r(L_q_) =	r(R_q_) =	q;
    r(L_qp_) =	r(R_qp_) =	qp;
    r(L_qpp_) =	r(R_qpp_) =	qpp;

    val = 1.0 / r(iSteer2Rack_);
    r(Ang_) =		val * q;
    r(AngVel_) =	val * qp;
    r(AngAcc_) =	val * qpp;

    r(L_iSteer2q_) = r(R_iSteer2q_) = r(iSteer2Rack_);

    /*
     * The signal TrqStatic is only an output signal or
     * an additional information!
     *
     * steering wheel torque, to keep the wheel in its position
     * under static conditions
     */
    r(TrqStatic_) = r(L_iSteer2q_) * r(L_Frc_) + r(R_iSteer2q_) * r(R_Frc_);
    lastT = comp->time;

#if 0
    comp->functions.logger(comp, comp->instanceName, fmiOK, "log",
			   "fmiDoStep: t=%g", comp->time);
#endif
}


// include code that implements the FMI based on the above definitions
#include "fmuTemplate.c"

