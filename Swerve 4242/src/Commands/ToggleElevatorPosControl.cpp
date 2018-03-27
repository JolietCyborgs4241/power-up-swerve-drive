#include "ToggleElevatorPosControl.h"

ToggleElevatorPosControl::ToggleElevatorPosControl() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleElevatorPosControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleElevatorPosControl::Execute() {
	Robot::elevatorPositionControl = !Robot::elevatorPositionControl;
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleElevatorPosControl::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleElevatorPosControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleElevatorPosControl::Interrupted() {

}
