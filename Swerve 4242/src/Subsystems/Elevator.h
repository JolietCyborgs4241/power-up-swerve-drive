#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Elevator : public Subsystem {
private:
	const double kP = 0.6;
	const double kI = 0.0;
	const double kD = 0.0;
	const double kF = 0.0;

	const int POSITION_DEFAULT = 200;
	const int POSITION_VAULT = 3000;
	const int POSITION_SWITCH = 12000;
	const int POSITION_SCALE_LOW = 23000;
	const int POSITION_SCALE_HIGH = 26500;

	const double PEAK_UP_SPEED = 0.75;
	const double PEAK_DOWN_SPEED = -0.4;

	// Talon PID 0
	const int kPIDLoopIdx = 0;

	// Talon timeout
	const int kTimeoutMs = 10;

	WPI_TalonSRX* elevatorMotor;
public:
	Elevator();
	void InitDefaultCommand();
	void PositionUpdate();
	void MoveElevator();
	double GetDistance();
	double GetPIDError();

	void PosDefault();
	void PosVault();
	void PosSwitch();
	void PosScaleLow();
	void PosScaleHigh();
};

#endif  // Elevator_H
