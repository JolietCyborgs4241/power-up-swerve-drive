#pragma once

#include "Commands/Command.h"
#include "Subsystems/PigeonPID.h"
#include "Subsystems/PositionPID.h"
#include "WPILib.h"

class PositionDrive : public Command {
  public:
    PositionDrive(double pos, double angle);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    double timeout;
    PositionPID* posPID;
    PigeonPID* pigeonPID;
};