#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class MoveToBaseline : public Command {
  public:
    MoveToBaseline();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};