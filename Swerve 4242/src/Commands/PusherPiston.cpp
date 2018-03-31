#include "PusherPiston.h"
#include "Robot.h"

PusherPiston::PusherPiston() {
    // Requires(Robot::pneumatics);
}

// Called just before this Command runs the first time
void PusherPiston::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void PusherPiston::Execute() {
    Robot::pneumatics->PushPiston();
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
    Robot::pneumatics->RetractPiston();
}
