#include "ElevatorPosControl.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"

ElevatorPosControl::ElevatorPosControl(int ElevatorCycleNum) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevator);
	ElevatorPosNum = ElevatorCycleNum;

}

// Called just before this Command runs the first time
void ElevatorPosControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorPosControl::Execute() {
	switch (ElevatorPosNum){
	case 1:
		Robot::elevator->ElevatorVault();
		break;
	case 2:
		Robot::elevator->ElevatorSwitch();
		break;
	case 3:
		Robot::elevator->ElevatorScaleLow();
		break;
	case 4:
		Robot::elevator->ElevatorScaleHigh();
		break;
	default:
		Robot::elevator->ElevatorPosDefault();

	}
}
// Make this return true when this Command no longer needs to run execute()
bool ElevatorPosControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorPosControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorPosControl::Interrupted() {

}
