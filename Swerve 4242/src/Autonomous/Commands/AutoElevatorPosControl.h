#pragma once

#include "Commands/Command.h"
#include "WPILib.h"
#include <cmath>

class AutoElevatorPosControl : public Command {
  public:
    AutoElevatorPosControl(int ElevatorCycleNum);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
    int ElevatorPosNum;
};