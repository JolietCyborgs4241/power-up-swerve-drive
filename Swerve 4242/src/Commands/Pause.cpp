#include "Pause.h"
#include "Robot.h"
Pause::Pause() {
	//Requires(Robot::pigeon);
}

// Called just before this Command runs the first time
void Pause::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Pause::Execute() {
	Robot::pigeon->ResetYaw();
}

// Make this return true when this Command no longer needs to run execute()
bool Pause::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void Pause::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pause::Interrupted() {

}
