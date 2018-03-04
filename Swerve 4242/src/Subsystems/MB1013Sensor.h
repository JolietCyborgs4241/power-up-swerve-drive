#ifndef MB1013Sensor_H
#define MB1013Sensor_H

#include <Commands/Subsystem.h>
#include "../RobotMap.h"
#include "WPILib.h"
using namespace frc;
class MB1013Sensor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
AnalogInput* MB1013;
public:
	MB1013Sensor();
	void InitDefaultCommand();
	double ReadSensor();
};

#endif  // MB1013Sensor_H
