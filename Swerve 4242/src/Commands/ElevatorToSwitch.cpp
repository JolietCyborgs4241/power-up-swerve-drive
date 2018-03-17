#include "ElevatorToSwitch.h"
#include "../Robot.h"

ElevatorToSwitch::ElevatorToSwitch() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ElevatorToSwitch::Initialize() {
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorToSwitch::Execute() {
	Robot::elevator->PosSwitch();
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorToSwitch::IsFinished() {
	//return Robot::elevator->;
}

// Called once after isFinished returns true
void ElevatorToSwitch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorToSwitch::Interrupted() {

}
