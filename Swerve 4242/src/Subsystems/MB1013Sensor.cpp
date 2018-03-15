#include "MB1013Sensor.h"
#include "../RobotMap.h"
#include "WPILib.h"

using namespace frc;

MB1013Sensor::MB1013Sensor() : Subsystem("MB1013Sensor") {
	MB1013 = new AnalogInput(4);
}

void MB1013Sensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double MB1013Sensor::ReadSensor() {
	// Centimeters
	return ((5 / 5120.0) * (MB1013->GetAverageVoltage())) / 100.0;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
