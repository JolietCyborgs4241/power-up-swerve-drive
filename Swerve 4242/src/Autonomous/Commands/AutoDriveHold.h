#pragma once

#include "Commands/Command.h"
#include "Subsystems/LIDARLite.h"
#include "Subsystems/PigeonPID.h"
#include "Subsystems/PositionPID.h"
#include "WPILib.h"

class AutoDriveHold : public Command {
  private:
    double y;
    double x;
    double timeout;

  public:
    AutoDriveHold(double y, double x, double angle, double timeout);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    PigeonPID* pigeonPID;
};