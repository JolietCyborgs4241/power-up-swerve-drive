#include "RampWinch.h"
#include "../RobotMap.h"

RampWinch::RampWinch() : Subsystem("ExampleSubsystem") {
	//winchMotor = RobotMap::rampWinchMotor;
}

void RampWinch::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void RampWinch::ExtendRamp() {
	//winchMotor->Set(speed);
}

void RampWinch::StopRamp() {
	//winchMotor->Set(0);
}

void RampWinch::RetractRamp() {
	//winchMotor->Set(-speed);
}
