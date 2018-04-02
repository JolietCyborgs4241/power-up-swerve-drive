#pragma once

#include "Commands/Command.h"
#include "WPILib.h"
class UpdatePigeon : public Command {
  public:
    UpdatePigeon();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};