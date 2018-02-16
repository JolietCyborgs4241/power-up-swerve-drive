#include "IntakeDetection.h"
#include "../RobotMap.h"
#include "Robot.h"

#include "Ultrasonic.h"

using namespace frc;




IntakeDetection::IntakeDetection() : Subsystem("IntakeDetection") {
	ultra = new Ultrasonic(1, 0);
	ultra->SetAutomaticMode(true);
}

void IntakeDetection::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

double IntakeDetection::GetRangeInches() {
	return ultra->GetRangeInches();
}

bool IntakeDetection::HasCube() {
	return ultra->GetRangeInches() < 3.0;
}
