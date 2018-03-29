#include "PigeonPID.h"

#include "Robot.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

PigeonPID::PigeonPID() : PIDSubsystem("PigeonPID", kP, kI, kD) {
    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.

    GetPIDController()->SetContinuous(true);
    GetPIDController()->SetAbsoluteTolerance(kTolerance);

    GetPIDController()->SetInputRange(0, 360);
    GetPIDController()->SetOutputRange(-kMaxSpeed, kMaxSpeed);

    GetPIDController()->SetP(kP);
    GetPIDController()->SetI(kI);
    GetPIDController()->SetD(kD);

    GetPIDController()->SetF(kF);
}

void PigeonPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

double PigeonPID::ReturnPIDInput() {
    return Robot::pigeon->GetYaw();
}

void PigeonPID::UsePIDOutput(double out) {
    output = out;

    //	if (output > 0) {
    //		output += 0.2;
    //	} else if (output < 0) {
    //		output -= 0.2;
    //	}

    // When on target don't adjust
    if (OnTarget()) {
        output = 0;
    }
}

bool PigeonPID::IsEnabled() {
    return GetPIDController()->IsEnabled();
}

double PigeonPID::GetOutput() {
    if (!IsEnabled()) {
        return 0;
    }

    return output;
}

double PigeonPID::GetDegError() {
    return GetPIDController()->GetError();
}