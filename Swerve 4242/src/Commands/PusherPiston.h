#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class PusherPiston : public frc::Command {
  public:
    PusherPiston();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};