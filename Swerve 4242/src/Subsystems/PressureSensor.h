#ifndef PressureSensor_H
#define PressureSensor_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
using namespace frc;

class PressureSensor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AnalogInput* sensor;
public:
	PressureSensor();
	void InitDefaultCommand();
	double Pressure();
};

#endif  // PressureSensor_H
