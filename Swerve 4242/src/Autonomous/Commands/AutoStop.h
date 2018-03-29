#pragma once

#include <Commands/Command.h>

class AutoStop : public frc::Command {
  public:
    AutoStop();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
