#ifndef PigeonPID_H
#define PigeonPID_H

#include <Commands/PIDSubsystem.h>
#include "ctre/Phoenix.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"
class PigeonPID : public PIDSubsystem {
public:
	PigeonPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	double PosError();
};

#endif  // PigeonPID_H
