#pragma once

#include "Commands/Command.h"
#include "Subsystems/BackPositionPID.h"
#include "Subsystems/LIDARLite.h"
#include "Subsystems/PigeonPID.h"
#include "WPILib.h"

class BackAdjust : public Command {
  private:
    double timeout;
    Timer* timer;

  public:
    BackAdjust(double pos, double angle);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    BackPositionPID* posPID;
    PigeonPID* pigeonPID;
};