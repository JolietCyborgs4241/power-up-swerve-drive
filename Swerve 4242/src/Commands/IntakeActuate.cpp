/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakeActuate.h"
#include "Robot.h"

IntakeActuate::IntakeActuate() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires (Robot::pneumatics);
}

// Called just before this Command runs the first time
void IntakeActuate::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeActuate::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeActuate::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeActuate::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeActuate::Interrupted() {

}
