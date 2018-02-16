#include "PigeonPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/Pigeon.h>
#include "../RobotMap.h"

PigeonPID::PigeonPID() : PIDSubsystem("PigeonPID", 1.0, 0.0, 0.0) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double PigeonPID::ReturnPIDInput() {
	return	RobotMap::Pigeon->GetYaw();

	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
}

void PigeonPID::UsePIDOutput(double output) {
	//RobotMap::angleDrive = (output);
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void PigeonPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
