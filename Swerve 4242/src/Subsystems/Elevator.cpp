#include "Elevator.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "Robot.h"
using namespace frc;

Elevator::Elevator() : Subsystem("Elevator") {

	ElevatorMotor = new WPI_TalonSRX(4);


}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Elevator::MoveElevator() {
	ElevatorMotor -> Set (Robot::oi->getPS4Joy());
}
