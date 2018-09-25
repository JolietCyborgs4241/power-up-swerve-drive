#pragma once

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <Commands/Subsystem.h>

class Elevator : public Subsystem {
<<<<<<< HEAD
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
	double ElevatorPos1();
	double ElevatorPos2();
	double ElevatorPos3();
	double ElevatorPos4();
	int ElevatorPosIncrement();
	int ElevatorPosDecrement();
	int ElevatorPosNum;
};

#endif  // Elevator_H
=======
  private:
    const double kP = 0.6;
    const double kI = 0.0;
    const double kD = 0.0;
    const double kF = 0.0;

    const double PEAK_UP_SPEED = 0.75;
    const double PEAK_DOWN_SPEED = -0.4;

    // Talon PID 0
    const int kPIDLoopIdx = 0;

    // Talon timeout
    const int kTimeoutMs = 10;

    double startingPosition = 0;

    WPI_TalonSRX* elevatorMotor;

  public:
    Elevator();
    void InitDefaultCommand();
    void PositionUpdate();
    void MoveElevator();

    void SetStartingPosition();
    double GetDistance();
    double GetPIDError();

    void PosDefault();
    void PosVault();
    void PosSwitch();
    void PosScaleLow();
    void PosScaleHigh();

    const int POSITION_DEFAULT = 200;
    const int POSITION_VAULT = 3000;
    const int POSITION_SWITCH = 16000;
    const int POSITION_SCALE_LOW = 18000;
    const int POSITION_SCALE_HIGH = 25000;
};
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
