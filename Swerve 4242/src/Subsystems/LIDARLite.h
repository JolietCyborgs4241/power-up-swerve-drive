#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/Subsystem.h>

using namespace frc;

class LIDARLite : public Subsystem {
  private:
    Counter* counter;

    double last_distance = -1;
    double SMOOTH_WEIGHT = 0.7;
    double MAX_DISTANCE = 1800;

    double calibration_offset = -10;

  public:
    LIDARLite(int source);
    void InitDefaultCommand();
    double DistanceCM();
    double SmoothedDistanceCM();
    double SmoothedDistanceFeet();
};