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
	Requires (Robot::intakeServo);
}

// Called just before this Command runs the first time
void IntakeActuate::Initialize() {
	SetTimeout(4);
}

// Called repeatedly when this Command is scheduled to run
void IntakeActuate::Execute() {
	/*
	Robot::pneumatics->IntakeDown();//choose one
	Robot::intakeServo->IntakeDrop();//choose one
	*/
	/*
	Timer *timer = new Timer();
	Robot::elevator->MoveElevatorAutoUp();
	timer++;
	if (Timer::HasPeriodPassed(1) == true);
	{
		Robot::elevator->MoveElevatorAutoDown();
		timer=0;
		timer++;
	}
	if (Timer::HasPeriodPassed(1) == true);
	{
		Robot::elevator->StopElevatorAuto();
		timer=0;
	}
	*/
	/*
	Robot::elevator->MoveElevatorAutoUp();
	SetTimeout(1);//this is not guaranteed to work, the SetTimeout might not allow
	Robot::elevator->MoveElevatorAutoDown();
	SetTimeout(1);//it to do anything, but it should allow it to move up and then
	Robot::elevator->StopElevatorAuto();
	SetTimeout(1);//down and bring it back down to the "default" position
	*/
	Robot::elevator->DropClaw();
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
