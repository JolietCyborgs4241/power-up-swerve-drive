#include "AutoDriveForward.h"
#include "Robot.h"
AutoDriveForward::AutoDriveForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::driveTrain);
}

// Called just before this Command runs the first time
void AutoDriveForward::Initialize() {
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward::Execute() {
	Robot::driveTrain->DriveForward();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDriveForward::End()
{
	Robot::driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForward::Interrupted()
{

}
