#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class ElevatorControl : public Command {
  public:
    ElevatorControl();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};