#include "UpdatePigeon.h"
#include "Robot.h"
UpdatePigeon::UpdatePigeon() {
	//Requires(Robot::pigeon);
}

// Called just before this Command runs the first time
void UpdatePigeon::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void UpdatePigeon::Execute() {
	Robot::pigeon->Update();
}

// Make this return true when this Command no longer needs to run execute()
bool UpdatePigeon::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void UpdatePigeon::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdatePigeon::Interrupted() {

}
