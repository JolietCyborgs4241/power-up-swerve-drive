#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class IntakeActuate : public frc::Command {
  public:
    IntakeActuate();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};