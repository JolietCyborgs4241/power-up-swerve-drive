// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "SmartDashboard/SendableChooser.h"


#include "Subsystems/Vision.h"

using namespace frc;

class Robot : public IterativeRobot {
public:
	//Command *autonomousCommand;


	static Vision* vision;

	LiveWindow *lw;
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();

private:
	void Dashboard();
	void LEDSet(int led);
	bool prevTrigger;
	Preferences* Prefs;
	//SendableChooser* LEDChooser;
	float cycleTime;
	int incnum;
};
#endif
