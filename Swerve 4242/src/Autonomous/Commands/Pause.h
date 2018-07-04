#pragma once

#include "Commands/Command.h"
#include "WPILib.h"
class Pause : public Command {
  public:
    Pause(double timeout);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

  private:
    double timeout;
};