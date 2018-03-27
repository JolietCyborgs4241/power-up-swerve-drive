#include <Commands/ToggleTwistPID.h>
#include "Robot.h"

ToggleTwistPID::ToggleTwistPID() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleTwistPID::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleTwistPID::Execute() {
	Robot::gyroAssist = !Robot::gyroAssist;
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleTwistPID::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleTwistPID::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleTwistPID::Interrupted() {

}
