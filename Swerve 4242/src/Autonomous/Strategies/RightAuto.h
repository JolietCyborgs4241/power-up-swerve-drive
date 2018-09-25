#pragma once

#include "WPILib.h"
#include <Commands/CommandGroup.h>

// PositionDrive direction. Right so the argument is false
#define RIGHT false

class RightAuto : public frc::CommandGroup {
  public:
    RightAuto();
};