// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/ClawControl.h"
#include "Commands/RampEndUp.h"
#include "Commands/IntakeActuate.h"
#include "Commands/ElevatorPosControl.h"
#include "Commands/CycleElevator.h"
#include "Commands/DeployRamp.h"
OI::OI() {
	// Process operator interface input here.
	pi = 3.14159;

	driverJoystickLeft = new Joystick(0); //Ps4
	driverJoystickRight = new Joystick(1); //Xbox

	//Xbox
	a = new JoystickButton(driverJoystickRight, 1);
	b = new JoystickButton(driverJoystickRight, 2);
	xb = new JoystickButton(driverJoystickRight, 3);
	y = new JoystickButton(driverJoystickRight, 4);
	lb = new JoystickButton(driverJoystickRight, 5);
	rb = new JoystickButton(driverJoystickRight, 6);
	back = new JoystickButton(driverJoystickRight, 7);
	start = new JoystickButton(driverJoystickRight, 8);
	//^Xbox^

	//PS4
	sq = new JoystickButton(driverJoystickLeft, 1);
	xp = new JoystickButton(driverJoystickLeft, 2);
	circle = new JoystickButton(driverJoystickLeft, 3);
	tri = new JoystickButton(driverJoystickLeft, 4);
	l1 = new JoystickButton(driverJoystickLeft, 5);
	r1 = new JoystickButton(driverJoystickLeft, 6);
	l2 = new JoystickButton(driverJoystickLeft, 7);
	r2 = new JoystickButton(driverJoystickLeft, 8);
	shr = new JoystickButton(driverJoystickLeft, 9);
	opt = new JoystickButton(driverJoystickLeft, 10);
	l3 = new JoystickButton(driverJoystickLeft, 11);
	r3 = new JoystickButton(driverJoystickLeft, 12);
	ps = new JoystickButton(driverJoystickLeft, 13);
	pad = new JoystickButton(driverJoystickLeft, 14);
	//^PS4^


	//xbox
	a->WhenPressed(new ResetPigeonYaw);



	//l1->WhenPressed(new PositionArm);

	//ps4
	xp->ToggleWhenPressed(new ClawControl);
	sq->ToggleWhenPressed(new RampEndUp);
	tri->ToggleWhenPressed(new DeployRamp);
	//tri->WhenPressed(new ElevatorPosControl(Robot::cycleElevator->ElevatorCycleNum));
	pad->WhenPressed(new CycleElevator);
}

Joystick* OI::getDriverJoystickLeft() {
	return driverJoystickLeft;
}
Joystick* OI::getDriverJoystickRight() {
	return driverJoystickRight;
}

bool OI::getL1() {
	return driverJoystickRight->GetRawButton(5);
}

double OI::getJoystickMagnitude() {
	if(driverJoystickRight->GetMagnitude() < .1) {
		return 0;
	} else {
		if (driverJoystickRight->GetY() < 0) {
			return -driverJoystickRight->GetMagnitude();
		} else {
			return driverJoystickRight->GetMagnitude();
		}
	}
}

double OI::getJoystickZ() {
	return adjustJoystick(driverJoystickRight->GetRawAxis(4));
}

double OI::getJoystickX() {
	return adjustJoystick(driverJoystickRight->GetX());
}

double OI::getJoystickY() {
	return adjustJoystick(driverJoystickRight->GetY());
}

double OI::getPS4Joy() {
	return adjustJoystick(driverJoystickLeft->GetY());
}

double OI::adjustJoystick(double value) {
	// cube output
	double adjV = pow(value, 3);

	// add deadzone
	if (fabs(adjV) < 0.05) {
		return 0;
	} else {
		return adjV;
	}
}
