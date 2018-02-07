#include "Elevator.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
using namespace frc;

Elevator::Elevator() : Subsystem("Elevator") {

	ElevatorMotorUp = new WPI_TalonSRX(4);
	ElevatorMotorDown = new WPI_TalonSRX(5);

}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Elevator::LiftElevator(){


}

void Elevator::LowerElevator(){


}
