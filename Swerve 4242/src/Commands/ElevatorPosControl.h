#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class ElevatorPosControl : public Command {
  public:
    ElevatorPosControl(int ElevatorCycleNum);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
    int ElevatorPosNum;
};