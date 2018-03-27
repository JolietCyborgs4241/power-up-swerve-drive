#include "ToggleLimitSwitch.h"
#include "Robot.h"

ToggleLimitSwitch::ToggleLimitSwitch() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleLimitSwitch::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleLimitSwitch::Execute() {
	Robot::useUpperLimitSwitch = !Robot::useUpperLimitSwitch;
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLimitSwitch::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleLimitSwitch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLimitSwitch::Interrupted() {

}
