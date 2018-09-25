#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class ToggleLimitSwitch : public Command {
  public:
    ToggleLimitSwitch();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};