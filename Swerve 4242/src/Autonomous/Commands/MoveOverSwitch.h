#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class MoveOverSwitch : public Command {
  public:
    MoveOverSwitch();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};