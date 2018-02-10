#ifndef RampWinch_H
#define RampWinch_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class RampWinch : public Subsystem {
private:

	WPI_TalonSRX* WinchMotor;

public:
	RampWinch();
	void InitDefaultCommand();
	void ReleaseRamp();
};

#endif  // RampWinch_H
