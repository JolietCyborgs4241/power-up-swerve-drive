#ifndef RampWinch_H
#define RampWinch_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class RampWinch : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX* WinchMotor;
public:
	RampWinch();
	void InitDefaultCommand();
	void ExtendRamp();
	void RetractRamp();
	void StopRamp();
};

#endif  // RampWinch_H
