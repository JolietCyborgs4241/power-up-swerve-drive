#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>

#include <math.h>

class PigeonPID : public PIDSubsystem {
  private:
    const double kP = 0.01;
    const double kI = 0.0;
    const double kD = 0.0;
    const double kF = 0.0;

    const double kTolerance = 3;  // degrees
    const double kMaxSpeed = 0.5; // motor speed

    double output;

  public:
    PigeonPID();
    void InitDefaultCommand();
    double ReturnPIDInput();
    void UsePIDOutput(double output);

    bool IsEnabled();
    double GetOutput();
    double GetDegError();
};