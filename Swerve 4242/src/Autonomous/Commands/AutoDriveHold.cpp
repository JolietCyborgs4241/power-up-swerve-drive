#include "AutoDriveHold.h"
#include "Robot.h"

#include "Subsystems/PigeonPID.h"

AutoDriveHold::AutoDriveHold(double y, double x, double angle, double timeout) {
    Requires(Robot::driveTrain);

    pigeonPID = new PigeonPID();
    pigeonPID->SetSetpoint(angle);

    this->y = y;
    this->x = x;
    this->timeout = timeout;
}

// Called just before this Command runs the first time
void AutoDriveHold::Initialize() {
    pigeonPID->Enable();
    SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveHold::Execute() {
    Robot::driveTrain->Crab(y, x, pigeonPID->GetOutput(), true);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveHold::IsFinished() {

    return // IsFinished conditions

        // check if gyro error is crazy, then just stop
        fabs(pigeonPID->GetDegError()) > 25 ||

        // did I hit something?
        // Robot::pigeon->WasCollision() ||

        // gone on for too long
        IsTimedOut();
}

// Called once after isFinished returns true
void AutoDriveHold::End() {
    Robot::driveTrain->Stop();

    pigeonPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveHold::Interrupted() {
    End();
}
