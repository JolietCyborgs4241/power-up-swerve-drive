#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class EjectCube : public frc::Command {
  public:
    EjectCube();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};