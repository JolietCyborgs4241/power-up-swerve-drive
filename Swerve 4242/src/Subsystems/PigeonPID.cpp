#include "PigeonPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/Pigeon.h>
#include "../RobotMap.h"
#include "../Robot.h"
#include "Subsystems/DriveTrain.h"

PigeonPID::PigeonPID() : PIDSubsystem("PigeonPID", 0.015, 0.001, 0.0) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetAbsoluteTolerance(3);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange(-0.35, 0.35);
	GetPIDController()->SetP(0.001);
	GetPIDController()->SetF(0);
	GetPIDController()->SetI(0.000);
	GetPIDController()->SetD(0.00);

}

double PigeonPID::ReturnPIDInput() {
	return	Robot::pigeon->GetYaw();

	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
}

void PigeonPID::UsePIDOutput(double output) {
//	if (output > 0) {
//		output += 0.2;
//	} else if (output < 0) {
//		output -= 0.2;
//	}
	if (OnTarget()) {
		output = 0;
	}

	Robot::twistPID_Value = -output;
	//RobotMap::angleDrive = (output);
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void PigeonPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double PigeonPID::PosError() {
	return GetPIDController()->GetError();
}
