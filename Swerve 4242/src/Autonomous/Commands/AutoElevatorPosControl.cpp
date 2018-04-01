#include "AutoElevatorPosControl.h"
#include "Robot.h"
#include "Subsystems/Elevator.h"

AutoElevatorPosControl::AutoElevatorPosControl(int ElevatorCycleNum) {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    // Requires(Robot::elevator);
    ElevatorPosNum = ElevatorCycleNum;
}

// Called just before this Command runs the first time
void AutoElevatorPosControl::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void AutoElevatorPosControl::Execute() {
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
}

// Make this return true when this Command no longer needs to run execute()
bool AutoElevatorPosControl::IsFinished() {
    return fabs(Robot::elevator->GetDistance() - Robot::elevator->POSITION_SCALE_LOW) < 300;
}

// Called once after isFinished returns true
void AutoElevatorPosControl::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoElevatorPosControl::Interrupted() {
}
