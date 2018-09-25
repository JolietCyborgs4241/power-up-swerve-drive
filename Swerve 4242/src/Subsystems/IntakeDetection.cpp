#include "IntakeDetection.h"
#include "../RobotMap.h"
#include "Robot.h"
#include "Ultrasonic.h"

using namespace frc;

IntakeDetection::IntakeDetection() : Subsystem("IntakeDetection") {
	DigitalInput* echo = new DigitalInput(9);
	DigitalOutput* trigger = new DigitalOutput(8);
	ultra = new Ultrasonic(trigger, echo);
	ultra->SetAutomaticMode(true);

}

void IntakeDetection::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double IntakeDetection::GetRangeInches() {
	double value = ultra->GetRangeInches();
	if (!ultra->IsRangeValid() || value > 150.0) {
		value = -1.0;
	}
	return value;
}

bool IntakeDetection::HasCube(int range) {
	double value = ultra->GetRangeInches();
	//new AnalogTrigger();
	return value < 3.0 && value > 0.0;
}

