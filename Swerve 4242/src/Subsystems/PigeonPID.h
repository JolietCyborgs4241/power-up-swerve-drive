#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/PIDSubsystem.h>

#include <math.h>
#include "ctre/Phoenix.h"
class PigeonPID : public PIDSubsystem {
<<<<<<< HEAD
public:
	PigeonPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif  // PigeonPID_H
=======
  private:
    const double kP = 0.04;
    const double kI = 0.0;
    const double kD = 0.0;
    const double kF = 0.0;

    const double kTolerance = 3;  // degrees
    const double kMaxSpeed = 0.5; // motor speed

    double output;

    std::shared_ptr<PIDController> pid;

  public:
    PigeonPID();
    void InitDefaultCommand();
    double ReturnPIDInput();
    void UsePIDOutput(double output);

    bool IsEnabled();
    double GetOutput();
    double GetDegError();
};
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
