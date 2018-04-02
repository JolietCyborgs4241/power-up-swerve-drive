#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class DropCube : public Command {
  public:
    DropCube();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};