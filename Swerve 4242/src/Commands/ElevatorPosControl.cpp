#include "ElevatorPosControl.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"

ElevatorPosControl::ElevatorPosControl(int ElevatorCycleNum) {
<<<<<<< HEAD
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevator);
	ElevatorPosNum = ElevatorCycleNum;

=======
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    // Requires(Robot::elevator);
    ElevatorPosNum = ElevatorCycleNum;
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

// Called just before this Command runs the first time
void ElevatorPosControl::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ElevatorPosControl::Execute() {
<<<<<<< HEAD
	if (ElevatorPosNum == 1)
	{
		Robot::elevator->ElevatorPos1();
	}
	else if (ElevatorPosNum == 2)
	{
		Robot::elevator->ElevatorPos2();
	}
	else if (ElevatorPosNum == 3)
	{
		Robot::elevator->ElevatorPos3();
	}
	else if (ElevatorPosNum == 4)
	{
		Robot::elevator->ElevatorPos4();
	}
	else
	{
		Robot::elevator->ElevatorPosDefault();
	}
=======
    switch (ElevatorPosNum) {
    case 0:
        Robot::elevator->PosDefault();
        break;
    case 1:
        Robot::elevator->PosVault();
        break;
    case 2:
        Robot::elevator->PosSwitch();
        break;
    case 3:
        Robot::elevator->PosScaleLow();
        break;
    case 4:
        Robot::elevator->PosScaleHigh();
        break;
    default:
        Robot::elevator->PosDefault();
    }
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorPosControl::IsFinished() {
<<<<<<< HEAD
	return false;
=======
    return true;
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

// Called once after isFinished returns true
void ElevatorPosControl::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorPosControl::Interrupted() {
}
