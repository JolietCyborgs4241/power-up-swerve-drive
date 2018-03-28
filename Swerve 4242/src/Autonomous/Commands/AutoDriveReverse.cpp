#include "AutoDriveReverse.h"
#include "Robot.h"

AutoDriveReverse::AutoDriveReverse(double time) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::driveTrain);
    timeout = time;
}

// Called just before this Command runs the first time
void AutoDriveReverse::Initialize() {
	SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveReverse::Execute() {
	Robot::driveTrain->DriveReverse();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveReverse::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDriveReverse::End() {
	Robot::driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveReverse::Interrupted() {

}
