#include "RampWinchExtend.h"

RampWinchExtend::RampWinchExtend() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::rampWinch);
}

// Called just before this Command runs the first time
void RampWinchExtend::Initialize() {
	SetTimeout(4);
}

// Called repeatedly when this Command is scheduled to run
void RampWinchExtend::Execute() {
	Robot::rampWinch->ExtendRamp();
}

// Make this return true when this Command no longer needs to run execute()
bool RampWinchExtend::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RampWinchExtend::End() {
	Robot::rampWinch->StopRamp();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RampWinchExtend::Interrupted() {
	Robot::rampWinch->StopRamp();
}
