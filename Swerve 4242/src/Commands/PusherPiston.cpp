#include "PusherPiston.h"
#include "Robot.h"

PusherPiston::PusherPiston() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(Robot::pneumatics);
}

// Called just before this Command runs the first time
void PusherPiston::Initialize() {
	Robot::pneumatics->PushPiston();
}

// Called repeatedly when this Command is scheduled to run
void PusherPiston::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool PusherPiston::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PusherPiston::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PusherPiston::Interrupted() {
	Robot::pneumatics->RetractPush();
}
