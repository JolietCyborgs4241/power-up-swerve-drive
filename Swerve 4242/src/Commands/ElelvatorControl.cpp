#include "ElelvatorControl.h"

ElelvatorControl::ElelvatorControl() {
	Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void ElelvatorControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElelvatorControl::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ElelvatorControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElelvatorControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElelvatorControl::Interrupted() {

}
