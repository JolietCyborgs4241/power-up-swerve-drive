#include <Commands/MoveElelvator.h>
#include "Robot.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
using namespace frc;


MoveElelvator::MoveElelvator() {

	Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void MoveElelvator::Initialize() {

	Robot::elevator->MoveElevator();

}

// Called repeatedly when this Command is scheduled to run
void MoveElelvator::Execute() {

	Robot::elevator->MoveElevator();

}

// Make this return true when this Command no longer needs to run execute()
bool MoveElelvator::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveElelvator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElelvator::Interrupted() {

}
