#include "PositionPID.h"

#include "Robot.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

PositionPID::PositionPID(LIDARLite* lidar) : PIDSubsystem("PositionPID", kP, kI, kD) {
    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.

    if (lidar == NULL) {
        return;
    }

    this->lidar = lidar;

    GetPIDController()->SetContinuous(false);

    GetPIDController()->SetAbsoluteTolerance(kTolerance);
    GetPIDController()->SetOutputRange(-kMaxSpeed, kMaxSpeed);

    GetPIDController()->SetP(kP);
    GetPIDController()->SetI(kI);
    GetPIDController()->SetD(kD);

    GetPIDController()->SetF(kF);
}

void PositionPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

double PositionPID::ReturnPIDInput() {
    return lidar->SmoothedDistanceFeet();
}

void PositionPID::UsePIDOutput(double out) {
    output = out;
    SmartDashboard::PutNumber("POS-out", out);
}

bool PositionPID::IsEnabled() {
    return GetPIDController()->IsEnabled();
}

double PositionPID::GetOutput() {
    if (!IsEnabled()) {
        return 0;
    }

    return output;
}

double PositionPID::GetPosFeetError() {
    return GetPIDController()->GetError();
}