#include "ElevatorPosControl.h"
#include "Robot.h"

ElevatorPosControl::ElevatorPosControl() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void ElevatorPosControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorPosControl::Execute() {
	int posNum = 0;
	if (posNum == 1)
	{
		Robot::elevator->ElevatorPos1();
		posNum = 2;
	}
	else if (posNum == 2)
	{
		Robot::elevator->ElevatorPos2();
		posNum = 3;
	}
	else if (posNum == 3)
	{
		Robot::elevator->ElevatorPos3();
		posNum = 4;
	}
	else if (posNum == 4)
	{
		Robot::elevator->ElevatorPos4();
		posNum = 1;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorPosControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorPosControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorPosControl::Interrupted() {

}
