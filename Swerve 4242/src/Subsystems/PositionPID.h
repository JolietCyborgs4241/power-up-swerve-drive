#pragma once

#include "Subsystems/LIDARLite.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>

#include <math.h>

class PositionPID : public PIDSubsystem {
  private:
    const double kP = 0.4;
    const double kI = 0.0;
    const double kD = 0.0;
    const double kF = 0.0;

    const double kTolerance = 0.3; // feet
    const double kMaxSpeed = 0.6;  // motor speed

    double output;
    LIDARLite* lidar;

  public:
    PositionPID(LIDARLite* lidar);
    void InitDefaultCommand();
    double ReturnPIDInput();
    void UsePIDOutput(double output);

    bool IsEnabled();
    double GetOutput();
    double GetPosFeetError();
};