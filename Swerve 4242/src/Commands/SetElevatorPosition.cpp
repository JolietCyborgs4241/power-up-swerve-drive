#include "SetElevatorPosition.h"
#include "Robot.h"

SetElevatorPosition::SetElevatorPosition() {

}

// Called just before this Command runs the first time
void SetElevatorPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetElevatorPosition::Execute() {
	Robot::elevator->SetStartingPosition();
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorPosition::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetElevatorPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetElevatorPosition::Interrupted() {

}
