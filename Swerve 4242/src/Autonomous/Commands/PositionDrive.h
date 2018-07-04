#pragma once

#include "Commands/Command.h"
#include "Subsystems/LIDARLite.h"
#include "Subsystems/PigeonPID.h"
#include "Subsystems/PositionPID.h"
#include "WPILib.h"

class PositionDrive : public Command {
  private:
    double timeout;
    double directionAdjust;
    bool hasBeenOnTarget;
    Timer* timer;

  public:
    PositionDrive(double pos, double angle, bool left);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    PositionPID* posPID;
    PigeonPID* pigeonPID;
};