#pragma once

#include "WPILib.h"
#include <Commands/CommandGroup.h>

// PositionDrive direction. Left so the argument is true
#define LEFT true

class LeftAutoSwitch : public frc::CommandGroup {
  public:
    LeftAutoSwitch();
};