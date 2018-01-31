#include "Analog_Gyro.h"
#include "../RobotMap.h"
#include "ADXRS450_Gyro.h"
#include "SPI.h"
#include <cmath>

using namespace frc;

Analog_Gyro::Analog_Gyro() : Subsystem("Analog_Gyro") {
	Gyro = new ADXRS450_Gyro (SPI::kOnboardCS0);
	int angle = 0;
	double angle_error=0;
}

void Analog_Gyro::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
double Analog_Gyro::GetGyroAngle(){
	angle = Gyro->GetAngle();
	angle_error = abs(angle - (360 * (angle/360)));
	return angle_error;

}
void Analog_Gyro::ResetGyro(){
	Gyro->Reset();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
