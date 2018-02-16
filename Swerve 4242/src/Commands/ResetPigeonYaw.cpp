#include "ResetPigeonYaw.h"
#include "Robot.h"
ResetPigeonYaw::ResetPigeonYaw() {
	//Requires(Robot::drivePigeon);
}

// Called just before this Command runs the first time
void ResetPigeonYaw::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ResetPigeonYaw::Execute() {
	Robot::drivePigeon->ResetYaw();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetPigeonYaw::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetPigeonYaw::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetPigeonYaw::Interrupted() {

}
