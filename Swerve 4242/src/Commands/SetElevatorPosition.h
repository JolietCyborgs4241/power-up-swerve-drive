#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class SetElevatorPosition : public Command {
  public:
    SetElevatorPosition();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
