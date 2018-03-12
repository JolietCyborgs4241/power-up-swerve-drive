#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Elevator : public Subsystem {
private:
	const double kP = 0.1;
	const double kI = 0.0;
	const double kD = 0.0;
	const double kF = 0.0;

	const double peakSpeed = 0.2;

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

	double DropClaw();
	double ElevatorPosDefault();
	double ElevatorVault();
	double ElevatorSwitch();
	double ElevatorScaleLow();
	double ElevatorScaleHigh();
	int ElevatorPosIncrement();
	int ElevatorPosDecrement();
	int ElevatorPosNum;
};

#endif  // Elevator_H
