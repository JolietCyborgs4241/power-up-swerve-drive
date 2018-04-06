#include "PositionDrive.h"
#include "Robot.h"

#include "Subsystems/PigeonPID.h"
#include "Subsystems/PositionPID.h"

PositionDrive::PositionDrive(double pos, double angle, bool left) {
    Requires(Robot::driveTrain);

    if (left) {
        posPID = new PositionPID(Robot::rightLidarLite);
        directionAdjust = 1;
    } else {
        posPID = new PositionPID(Robot::leftLidarLite);
        directionAdjust = -1;
    }

    pigeonPID = new PigeonPID();

    posPID->SetSetpoint(pos);
    pigeonPID->SetSetpoint(angle);

    timer = new Timer();
}

// Called just before this Command runs the first time
void PositionDrive::Initialize() {
    posPID->Enable();
    pigeonPID->Enable();
    SetTimeout(9);
}

// Called repeatedly when this Command is scheduled to run
void PositionDrive::Execute() {
    Robot::driveTrain->DriveLeft(posPID->GetOutput() * directionAdjust, pigeonPID->GetOutput());

    // lol this is wrong, it stops it when just OnTarget() is true too
    // TODO: Fix
    if (posPID->OnTarget() && timer->Get() <= 0) {
        timer->Start();
    } else if (posPID->OnTarget()) {
        // do nothing
    } else {
        timer->Stop();
        timer->Reset();
    }
}

// Make this return true when this Command no longer needs to run execute()
bool PositionDrive::IsFinished() {

    return // IsFinished conditions

        // check if gyro error is crazy, then just stop
        fabs(pigeonPID->GetDegError()) > 25 ||

        // We were on pos target for 1.5 secondsh
        // timer->Get() >= 0.3 ||

        posPID->OnTarget() ||

        // did I fall over? lol
        Robot::pigeon->AmTilted() ||

        // did I hit something?
        // Robot::pigeon->WasCollision() ||

        // gone on for too long
        IsTimedOut();
}

// Called once after isFinished returns true
void PositionDrive::End() {
    Robot::driveTrain->Stop();

    posPID->Disable();
    pigeonPID->Disable();

    timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PositionDrive::Interrupted() {
    End();
}
