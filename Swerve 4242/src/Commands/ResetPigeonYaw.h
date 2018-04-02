#pragma once

#include "Commands/Command.h"
#include "WPILib.h"
class ResetPigeonYaw : public Command {
  private:
    double offset;

  public:
    ResetPigeonYaw(double offset = 0);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};