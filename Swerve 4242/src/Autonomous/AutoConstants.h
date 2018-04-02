#pragma once

#include "WPILib.h"
#include <Commands/Subsystem.h>

using namespace frc;

class AutoConstants : public Subsystem {
  public:
    AutoConstants();

    static constexpr double LIDAR_SWITCH_DISTNACE = 12.5;
    static constexpr double LIDAR_SCALE_DISTNACE = 26.5;
};