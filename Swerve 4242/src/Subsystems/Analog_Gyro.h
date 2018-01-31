#ifndef Analog_Gyro_H
#define Analog_Gyro_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"

class Analog_Gyro : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
int angle;
double angle_error;
public:
	Analog_Gyro();
	ADXRS450_Gyro* Gyro;
	void InitDefaultCommand();
	void CalibrateGyro();
	double GetGyroAngle();
	void ResetGyro();

};

#endif  // Analog_Gyro_H
