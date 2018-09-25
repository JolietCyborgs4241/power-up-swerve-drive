#pragma once

#include "WPILib.h"
#include <Commands/CommandGroup.h>

// PositionDrive direction. Right so the argument is false
#define RIGHT false

class RightAutoSwitch : public frc::CommandGroup {
  public:
    RightAutoSwitch();
};