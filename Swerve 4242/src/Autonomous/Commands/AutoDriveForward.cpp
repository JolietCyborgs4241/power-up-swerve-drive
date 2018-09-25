#include "AutoDriveForward.h"
#include "Robot.h"

AutoDriveForward::AutoDriveForward(double speed, double timeout) {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(Robot::driveTrain);

    this->speed = speed;
    this->timeout = timeout;
}

// Called just before this ommand runs the first time
void AutoDriveForward::Initialize() {
    SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward::Execute() {
    Robot::driveTrain->DriveForward(speed, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward::IsFinished() {
    return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDriveForward::End() {
    Robot::driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForward::Interrupted() {
}
