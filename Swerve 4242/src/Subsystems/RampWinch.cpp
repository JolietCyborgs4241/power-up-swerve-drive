#include "RampWinch.h"
#include "../RobotMap.h"

RampWinch::RampWinch() : Subsystem("ExampleSubsystem") {
	WinchMotor = new WPI_TalonSRX(2);
}

void RampWinch::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void RampWinch::ExtendRamp() {

	WinchMotor -> Set(1.0);

}

void RampWinch::StopRamp() {

	WinchMotor -> Set(0);

}

void RampWinch::RetractRamp() {

	WinchMotor -> Set(-1.0);

}
