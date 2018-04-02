#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class ToggleTwistPID : public Command {
  public:
    ToggleTwistPID();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};