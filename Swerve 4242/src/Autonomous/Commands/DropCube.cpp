#include "DropCube.h"
#include "Robot.h"

DropCube::DropCube() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DropCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DropCube::Execute() {
	Robot::pneumatics->OpenClaw();
}

// Make this return true when this Command no longer needs to run execute()
bool DropCube::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DropCube::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DropCube::Interrupted() {

}
