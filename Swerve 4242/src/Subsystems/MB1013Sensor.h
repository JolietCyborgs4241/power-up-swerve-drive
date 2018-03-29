#pragma once

#include "../RobotMap.h"
#include "WPILib.h"
#include <Commands/Subsystem.h>

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