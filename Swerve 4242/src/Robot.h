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
#include <Subsystems/Pigeon.h>
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "SmartDashboard/SendableChooser.h"

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/IntakeDetection.h"
#include "Subsystems/PressureSensor.h"
#include "Subsystems/MB1013Sensor.h"
#include "Commands/ElevatorPosControl.h"
#include "Subsystems/PigeonPID.h"
#include "Subsystems/LIDARLite.h"

using namespace frc;

class Robot : public IterativeRobot {
public:
	//Command *autonomousCommand;
	static OI *oi;
	static DriveTrain* driveTrain;
	static Pigeon* pigeon;
	static Elevator* elevator;
	static Pneumatics* pneumatics;
	static IntakeDetection* intakeDetection;
	static ElevatorPosControl* elevatorPosControl;


	static double twistPID_Value;
	static bool twistPID_Enabled;
	static PigeonPID* twistPID;

	static bool fieldCentric_Enabled;

	static PressureSensor* pressureSensor;
	static MB1013Sensor* mb1013Sensor;
	static LIDARLite* lidarLite;

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
	double FLOffset;
	double FROffset;
	double RLOffset;
	double RROffset;
	bool prevTrigger;
	Preferences* Prefs;
	int turnDegree;
	int turnDirection;
	float driveForwardAngle;
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
	//SendableChooser* LEDChooser;
	float cycleTime;
	int incnum;
	//Command *autonomousCommand;
};
#endif
