#include "MoveToSwitch.h"

MoveToSwitch::MoveToSwitch() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveToSwitch::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveToSwitch::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MoveToSwitch::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveToSwitch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToSwitch::Interrupted() {

}
