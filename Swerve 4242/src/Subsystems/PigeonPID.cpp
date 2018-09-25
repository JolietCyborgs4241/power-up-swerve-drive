#include "PigeonPID.h"

#include "Robot.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
<<<<<<< HEAD
#include <Subsystems/Pigeon.h>
#include "../RobotMap.h"
#include "../Robot.h"
#include "Subsystems/DriveTrain.h"

PigeonPID::PigeonPID() : PIDSubsystem("PigeonPID", 0.1, 0.0, 0.0) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetAbsoluteTolerance(1);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange(-1, 1);
}

double PigeonPID::ReturnPIDInput() {
	return	RobotMap::pigeon->GetYaw();
=======

PigeonPID::PigeonPID() : PIDSubsystem("PigeonPID", kP, kI, kD) {
    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.

    pid = GetPIDController();
    pid->SetContinuous(true);
    pid->SetAbsoluteTolerance(kTolerance);

    pid->SetInputRange(0, 360);
    pid->SetOutputRange(-kMaxSpeed, kMaxSpeed);

    pid->SetP(kP);
    pid->SetI(kI);
    pid->SetD(kD);

    pid->SetF(kF);
}

void PigeonPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff

double PigeonPID::ReturnPIDInput() {
    return Robot::pigeon->GetYaw();
}

<<<<<<< HEAD
void PigeonPID::UsePIDOutput(double output) {
	Robot::twistPID_Value = output;
	//RobotMap::angleDrive = (output);
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
=======
void PigeonPID::UsePIDOutput(double out) {
    output = out;

    //	if (output > 0) {
    //		output += 0.2;
    //	} else if (output < 0) {
    //		output -= 0.2;
    //	}

    // When on target don't adjust
    // if (OnTarget()) {
    //     output = 0;
    // }
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

bool PigeonPID::IsEnabled() {
    return pid->IsEnabled();
}
<<<<<<< HEAD
=======

double PigeonPID::GetOutput() {
    if (!IsEnabled()) {
        return 0;
    }

    return output;
}

double PigeonPID::GetDegError() {
    return pid->GetError();
}
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
