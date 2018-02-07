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
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Subsystems/DriveTrain.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ResetPigeonYaw.h"




    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
	pi = 3.14159;
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	driverJoystickLeft = new Joystick(0); //Ps4

	driverJoystickRight = new Joystick(1); //Xbox

	a = new JoystickButton(driverJoystickRight, 1);
	b = new JoystickButton(driverJoystickRight, 2);
	xb = new JoystickButton(driverJoystickRight, 3);
	y = new JoystickButton(driverJoystickRight, 4);
	lb = new JoystickButton(driverJoystickRight, 5);
	rb = new JoystickButton(driverJoystickRight, 6);
	back = new JoystickButton(driverJoystickRight, 7);
	start = new JoystickButton(driverJoystickRight, 8);
	//^Xbox^
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
//	l1->WhenPressed(new PositionArm);
//ps4
	/*o = new JoystickButton(driverJoystickRight, 3);
	o->WhenPressed(new FeederWheelIn);*/




    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//cout << "OI Constructor Complete" << endl;
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getDriverJoystickLeft() {
	return driverJoystickLeft;
}
Joystick* OI::getDriverJoystickRight() {
	return driverJoystickRight;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
bool OI::getL1()
{
	return driverJoystickRight->GetRawButton(5);
}
double OI::getJoystickMagnitude() {
	if(driverJoystickRight->GetMagnitude() < .1)
		return 0;
	else
		if (driverJoystickRight->GetY()<0)
			return -driverJoystickRight->GetMagnitude();
		else
			return driverJoystickRight->GetMagnitude();
}
double OI::getJoystickZ() {
	Zjoy = driverJoystickRight->GetRawAxis(4);
	Zadj = pow(Zjoy, 3);
	if(fabs(Zadj) < 0.05)
			return 0;
	else
		return Zadj;
}
double OI::getJoystickX() {
	Xjoy = driverJoystickRight->GetX();
	Xadj = pow(Xjoy, 3);
	if (fabs(Xadj) < 0.05)
		return 0;
	else
		return Xadj;
}
double OI::getJoystickY() {
	Yjoy = driverJoystickRight->GetY();
	Yadj = pow(Yjoy, 3);
	if (fabs(Yadj) < 0.05)
		return 0;
	else
		return Yadj;
}
