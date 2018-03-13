#include "DecreasePos.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"
DecreasePos::DecreasePos() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void DecreasePos::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DecreasePos::Execute() {
Robot::elevator->ElevatorPosDecrement();
}

// Make this return true when this Command no longer needs to run execute()
bool DecreasePos::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DecreasePos::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DecreasePos::Interrupted() {

}
