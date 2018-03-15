#include "DeployRamp.h"

DeployRamp::DeployRamp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	startTime = 0;
	done = false;
}

// Called just before this Command runs the first time
void DeployRamp::Initialize() {
	startTime = GetClock();
}

// Called repeatedly when this Command is scheduled to run
void DeployRamp::Execute() {
	if (Robot::deployedRamp) {
		Robot::pneumatics->HoldRamp();
		Robot::deployedRamp = false;
		done = true;
	} else {
		//if (GetClock() - startTime > TIME_TO_RELEASE) {
			Robot::pneumatics->DeployRamp();
			Robot::deployedRamp = true;
			done = true;
		//}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DeployRamp::IsFinished() {
	return done;
}

// Called once after isFinished returns true
void DeployRamp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeployRamp::Interrupted() {

}
