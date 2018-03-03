#include "DeployRamp.h"

DeployRamp::DeployRamp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DeployRamp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DeployRamp::Execute() {
	Robot::pneumatics->DeployRamp();
}

// Make this return true when this Command no longer needs to run execute()
bool DeployRamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DeployRamp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeployRamp::Interrupted() {
	Robot::pneumatics->HoldRamp();
}
