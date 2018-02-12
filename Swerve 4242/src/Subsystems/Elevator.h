#ifndef Elevator_H
#define Elevator_H


#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Elevator : public Subsystem {
private:
	WPI_TalonSRX* ElevatorMotor;

public:
	Elevator();
	void InitDefaultCommand();
	void MoveElevator();
};

#endif  // Elevator_H
