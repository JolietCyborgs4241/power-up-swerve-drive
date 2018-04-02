#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveForward : public Command {
  public:
    AutoDriveForward(double speed, double timeout);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    double timeout;
    double speed;
};