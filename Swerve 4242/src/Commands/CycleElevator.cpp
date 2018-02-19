#include "CycleElevator.h"
#include "Robot.h"
CycleElevator::CycleElevator() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void CycleElevator::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CycleElevator::Execute(int cycleNum) {
	ElevatorCycleNum = cycleNum;
//	double ElevatorCycleNumber(ElevatorCycleNum);
}

// Make this return true when this Command no longer needs to run execute()
bool CycleElevator::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CycleElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CycleElevator::Interrupted() {

}
