#include "AutoDriveAngle.h"
#include "Robot.h"

AutoDriveAngle::AutoDriveAngle(double speed, double angle, double timeout) {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(Robot::driveTrain);

    this->speed = speed;
    this->angle = angle;
    this->timeout = timeout;
}

// Called just before this ommand runs the first time
void AutoDriveAngle::Initialize() {
    SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveAngle::Execute() {
    Robot::driveTrain->DriveAngle(speed, angle);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveAngle::IsFinished() {
    return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDriveAngle::End() {
    Robot::driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveAngle::Interrupted() {
}
