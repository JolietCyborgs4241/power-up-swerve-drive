#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveAngle : public Command {
  public:
    AutoDriveAngle(double speed, double angle, double timeout);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    double timeout;
    double speed;
    double angle;
};