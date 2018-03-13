#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Elevator : public Subsystem {
private:
	const double kP = 0.6;
	const double kI = 0.000;
	const double kD = 0.0;
	const double kF = 0.0;

	const double peakSpeed = 0.75;

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

	void DropClaw();
	void ElevatorPosDefault();
	void ElevatorVault();
	void ElevatorSwitch();
	void ElevatorScaleLow();
	void ElevatorScaleHigh();
	int ElevatorPosIncrement();
	int ElevatorPosDecrement();
	int ElevatorPosNum;
};

#endif  // Elevator_H
