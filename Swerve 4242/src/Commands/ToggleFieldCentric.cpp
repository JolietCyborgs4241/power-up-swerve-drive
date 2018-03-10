#include "ToggleFieldCentric.h"
#include "Robot.h"

ToggleFieldCentric::ToggleFieldCentric() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleFieldCentric::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleFieldCentric::Execute() {
	Robot::fieldCentric_Enabled = true;
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleFieldCentric::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleFieldCentric::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleFieldCentric::Interrupted() {
	Robot::fieldCentric_Enabled = false;
}
