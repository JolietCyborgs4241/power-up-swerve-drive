#ifndef PigeonPID_H
#define PigeonPID_H

#include <Commands/PIDSubsystem.h>
#include "ctre/Phoenix.h"
#include "WPILib.h"
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

#endif  // PigeonPID_H
