#ifndef PositionPID_H
#define PositionPID_H

#include <Commands/PIDSubsystem.h>
#include "ctre/Phoenix.h"
#include "WPILib.h"
#include <math.h>

class PositionPID : public PIDSubsystem {
public:
	PositionPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif  // PositionPID_H
