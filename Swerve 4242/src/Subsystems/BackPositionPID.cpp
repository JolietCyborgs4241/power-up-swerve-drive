#include "BackPositionPID.h"

#include "Robot.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

BackPositionPID::BackPositionPID() : PIDSubsystem("BackPositionPID", kP, kI, kD) {
    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.

    pid = GetPIDController();
    pid->SetContinuous(false);

    pid->SetAbsoluteTolerance(kTolerance);
    pid->SetOutputRange(-kMaxSpeed, kMaxSpeed);

    pid->SetP(kP);
    pid->SetI(kI);
    pid->SetD(kD);

    pid->SetF(kF);
}

void BackPositionPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

double BackPositionPID::ReturnPIDInput() {
    return Robot::mb1013Sensor->SmoothedDistanceFeet();
}

void BackPositionPID::UsePIDOutput(double out) {
    output = out;
}

bool BackPositionPID::IsEnabled() {
    return pid->IsEnabled();
}

double BackPositionPID::GetOutput() {
    if (!IsEnabled()) {
        return 0;
    }

    if (output < 0.2 && output > 0.03) {
        output = 0.2;
    }
    if (output > -0.2 && output < -0.03) {
        output = -0.2;
    }
    return output;
}

double BackPositionPID::GetPosFeetError() {
    return pid->GetError();
}