#include "PositionPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "../RobotMap.h"
#include "../Robot.h"

PositionPID::PositionPID() : PIDSubsystem("PositionPID", 1.0, 0.0, 0.0) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	GetPIDController()->SetContinuous(false);
	GetPIDController()->SetAbsoluteTolerance(15);
	//GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange(-0.4, 0.4);
	GetPIDController()->SetP(0.01);
	GetPIDController()->SetF(0);
	GetPIDController()->SetI(0.000);
	GetPIDController()->SetD(0.00);
}

double PositionPID::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	Robot::rightLidarLite->Distance();
}

void PositionPID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
    output = output;
	//Robot::positionOutput = output;
}

void PositionPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
