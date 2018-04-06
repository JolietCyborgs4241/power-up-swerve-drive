#pragma once

#include "Subsystems/LIDARLite.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>

#include <math.h>

class BackPositionPID : public PIDSubsystem {
  private:
    const double kP = 0.18;
    const double kI = 0.0;
    const double kD = 0.0;
    const double kF = 0.0;

    const double kTolerance = 0.15; // feet
    const double kMaxSpeed = 0.4;   // motor speed

    double output;

    std::shared_ptr<PIDController> pid;

  public:
    BackPositionPID();
    void InitDefaultCommand();
    double ReturnPIDInput();
    void UsePIDOutput(double output);

    bool IsEnabled();
    double GetOutput();
    double GetPosFeetError();
};