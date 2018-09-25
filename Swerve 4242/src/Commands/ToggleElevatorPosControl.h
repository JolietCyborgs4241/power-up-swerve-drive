#pragma once

#include "Commands/Command.h"
#include "Robot.h"
#include "WPILib.h"

class ToggleElevatorPosControl : public Command {
  public:
    ToggleElevatorPosControl();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};