#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>

#include <math.h>

class PositionPID : public PIDSubsystem {
  private:
    const double kP = 0.1;
    const double kI = 0.0;
    const double kD = 0.0;
    const double kF = 0.0;

    const double kTolerance = 0.5; // feet
    const double kMaxSpeed = 0.5;  // motor speed

    double output;

  public:
    PositionPID();
    void InitDefaultCommand();
    double ReturnPIDInput();
    void UsePIDOutput(double output);

    bool IsEnabled();
    double GetOutput();
    double GetPosFeetError();
};