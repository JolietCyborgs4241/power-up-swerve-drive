#include "PigeonPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
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

	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
}

void PigeonPID::UsePIDOutput(double output) {
	Robot::twistPID_Value = output;
	//RobotMap::angleDrive = (output);
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void PigeonPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
