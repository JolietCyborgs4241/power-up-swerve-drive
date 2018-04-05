#include "BackAdjust.h"
#include "Robot.h"

#include "Subsystems/BackPositionPID.h"
#include "Subsystems/PigeonPID.h"

BackAdjust::BackAdjust(double pos, double angle) {
    Requires(Robot::driveTrain);

    posPID = new BackPositionPID();
    pigeonPID = new PigeonPID();

    posPID->SetSetpoint(pos);
    pigeonPID->SetSetpoint(angle);

    timer = new Timer();
}

// Called just before this Command runs the first time
void BackAdjust::Initialize() {
    posPID->Enable();
    pigeonPID->Enable();
    SetTimeout(4);
}

// Called repeatedly when this Command is scheduled to run
void BackAdjust::Execute() {
    SmartDashboard::PutNumber("Back-Adjust", posPID->GetOutput());
    Robot::driveTrain->DriveForward(posPID->GetOutput(), pigeonPID->GetOutput());

    if (posPID->OnTarget() && timer->Get() <= 0) {
        timer->Start();
    } else {
        timer->Stop();
        timer->Reset();
    }
}

// Make this return true when this Command no longer needs to run execute()
bool BackAdjust::IsFinished() {

    return // IsFinished conditions

        // check if gyro error is crazy, then just stop
        fabs(pigeonPID->GetDegError()) > 25 ||

        // We were on pos target for 1.5 secondsh
        // timer->Get() >= 1.5 ||
        posPID->OnTarget() ||

        // did I fall over? lol
        Robot::pigeon->AmTilted() ||

        // shit we hit scale?
        Robot::mb1013Sensor->SmoothedDistanceFeet() > 4.1 ||

        // did I hit something?
        // Robot::pigeon->WasCollision() ||

        // gone on for too long
        IsTimedOut();
}

// Called once after isFinished returns true
void BackAdjust::End() {
    Robot::driveTrain->Stop();

    posPID->Disable();
    pigeonPID->Disable();

    timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackAdjust::Interrupted() {
    End();
}
