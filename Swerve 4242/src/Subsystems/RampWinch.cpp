#include "RampWinch.h"
#include "../RobotMap.h"
#include "Robot.h"
#include "ctre/Phoenix.h"
using namespace frc;

RampWinch::RampWinch() : Subsystem("RampWinch") {

	WinchMotor = new WPI_TalonSRX(2);

}

void RampWinch::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void RampWinch::ReleaseRamp() {



}
