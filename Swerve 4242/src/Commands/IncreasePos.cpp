#include "IncreasePos.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"
IncreasePos::IncreasePos() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void IncreasePos::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IncreasePos::Execute() {
Robot::elevator->ElevatorPosIncrement();
}

// Make this return true when this Command no longer needs to run execute()
bool IncreasePos::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void IncreasePos::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncreasePos::Interrupted() {

}
