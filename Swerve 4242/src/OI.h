// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include <math.h>
class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* driverJoystickLeft;
	Joystick* driverJoystickRight;
	JoystickButton* a;
	JoystickButton* b;
	JoystickButton* xb;
	JoystickButton* y;
	JoystickButton* lb;
	JoystickButton* rb;
	JoystickButton* back;
	JoystickButton* start;
	JoystickButton* ljoy;
	JoystickButton* rjoy;
	//^Xbox^
	JoystickButton* xp;
	JoystickButton* circle;
	JoystickButton* tri;
	JoystickButton* sq; //square
	JoystickButton* r1;
	JoystickButton* l1;
	JoystickButton* r2;
	JoystickButton* l2;
	JoystickButton* r3;
	JoystickButton* l3;
	JoystickButton* pad; //touchpad
	JoystickButton* shr; //share
	JoystickButton* opt; //options
	JoystickButton* ps; //PS button
	//^PS4^

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	double pi;
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	Joystick* getDriverJoystickRight();
	Joystick* getDriverJoystickLeft();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	double getJoystickMagnitude();
	double getJoystickZ();
	double getJoystickX();
	double getJoystickY();
	double getPS4Joy();
	bool getL1();
	double Xadj = 0.0;
	double Xjoy = 0.0;
	double Yadj = 0.0;
	double Yjoy = 0.0;
	double Zjoy = 0.0;
	double Zadj = 0.0;
	double Ps4Yjoy = 0.0;
	double Ps4Yadj = 0.0;
};
#endif
