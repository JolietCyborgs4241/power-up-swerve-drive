/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakeServo.h"
#include "../RobotMap.h"

IntakeServo::IntakeServo() : Subsystem("ExampleSubsystem")
{
	IntakeDropServo = new Servo(8);
}

void IntakeServo::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void IntakeServo::IntakeDefault()
{
	IntakeDropServo -> SetAngle(180);
}
void IntakeServo::IntakeDrop()
{
	IntakeDropServo -> SetAngle(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
