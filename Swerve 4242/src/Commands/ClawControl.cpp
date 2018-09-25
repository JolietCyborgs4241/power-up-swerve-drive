#include "ClawControl.h"
#include "Robot.h"

ClawControl::ClawControl() {
<<<<<<< HEAD
	Requires(Robot::pneumatics);
=======
    // Requires(Robot::pneumatics);
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

// Called just before this Command runs the first time
void ClawControl::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ClawControl::Execute() {
    Robot::pneumatics->OpenClaw();
}

// Make this return true when this Command no longer needs to run execute()
bool ClawControl::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void ClawControl::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawControl::Interrupted() {
    Robot::pneumatics->CloseClaw();
}
