#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>
#include <math.h>

class PositionPID : public PIDSubsystem {
  public:
    PositionPID();
    double ReturnPIDInput();
    void UsePIDOutput(double output);
    void InitDefaultCommand();

    double output;
};