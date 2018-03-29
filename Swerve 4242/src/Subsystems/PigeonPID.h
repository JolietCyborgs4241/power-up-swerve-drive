#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>
#include <math.h>

class PigeonPID : public PIDSubsystem {
  public:
    PigeonPID();
    double ReturnPIDInput();
    void UsePIDOutput(double output);
    void InitDefaultCommand();
    double PosError();

    double output;
};