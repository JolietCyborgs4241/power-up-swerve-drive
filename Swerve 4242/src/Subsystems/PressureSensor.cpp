#include "PressureSensor.h"
#include "../RobotMap.h"
#include "WPILib.h"
using namespace frc;

PressureSensor::PressureSensor() : Subsystem("ExampleSubsystem") {
	sensor = new AnalogInput(5);
}

void PressureSensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double PressureSensor::Pressure() {
	return 250 * (sensor->GetAverageVoltage() / 5.0) - 25;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
