#ifndef MB1013Sensor_H
#define MB1013Sensor_H

#include <Commands/Subsystem.h>
#include "../RobotMap.h"
#include "WPILib.h"

using namespace frc;

class MB1013Sensor : public Subsystem {
private:
    AnalogInput* aInput;

    double last_distance = -1;
    double SMOOTH_WEIGHT = 0.7;
    double MAX_DISTANCE = 450;

public:
	MB1013Sensor();
	void InitDefaultCommand();
	double DistanceCM();
    double SmoothedDistanceCM();
};

#endif  // MB1013Sensor_H
