#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class MoveToScale : public Command {
  public:
    MoveToScale();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};