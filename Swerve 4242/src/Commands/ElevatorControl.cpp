#include "ElevatorControl.h"
#include "Robot.h"
ElevatorControl::ElevatorControl() {
	Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void ElevatorControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorControl::Execute() {
	Robot::elevator->MoveElevator();
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorControl::Interrupted() {

}
