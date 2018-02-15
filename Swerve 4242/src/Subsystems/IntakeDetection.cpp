#include "IntakeDetection.h"
#include "../RobotMap.h"
<<<<<<< HEAD
#include "Robot.h"
=======
#include "Ultrasonic.h"

using namespace frc;
>>>>>>> ef27af94b6fd453e3544b4e37f5159ca6c11e0ad

IntakeDetection::IntakeDetection() : Subsystem("IntakeDetection") {
	DigitalInput* echo = new DigitalInput(6);
	DigitalOutput* trigger = new DigitalOutput(5);
	ultra = new Ultrasonic(trigger, echo);
	ultra->SetAutomaticMode(true);
}

void IntakeDetection::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double IntakeDetection::GetRangeInches() {
	return ultra->GetRangeInches();
}

bool IntakeDetection::HasCube() {
	return GetRangeInches() < 3.0;
}
