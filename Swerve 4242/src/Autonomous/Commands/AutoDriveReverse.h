#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveReverse : public Command {
  public:
    AutoDriveReverse(double speed, double timeout);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    double timeout;
    double speed;
};