/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ToggleRampLift.h"
#include "Robot.h"
ToggleRampLift::ToggleRampLift() {
	//Requires(Robot::pneumatics);
}

// Called just before this Command runs the first time
void ToggleRampLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleRampLift::Execute() {
	if (Robot::deployedRamp) {
		if (Robot::rampLifted) {
			Robot::pneumatics->LowerRamp();
			Robot::rampLifted = false;
		} else {
			Robot::pneumatics->RaiseRamp();
			Robot::rampLifted = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleRampLift::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleRampLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleRampLift::Interrupted() {
}
