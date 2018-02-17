// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include <Subsystems/Pigeon.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "CameraServer.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static WPI_TalonSRX* driveTrainFrontLeftDrive;
	static WPI_TalonSRX* driveTrainFrontRightDrive;
	static WPI_TalonSRX* driveTrainRearLeftDrive;
	static WPI_TalonSRX* driveTrainRearRightDrive;
	static AnalogInput* driveTrainFrontLeftPos;
	static WPI_TalonSRX* driveTrainFrontLeftSteer;
	static PIDController* driveTrainFrontLeft;
	static AnalogInput* driveTrainFrontRightPos;
	static WPI_TalonSRX* driveTrainFrontRightSteer;
	static PIDController* driveTrainFrontRight;
	static AnalogInput* driveTrainRearLeftPos;
	static WPI_TalonSRX* driveTrainRearLeftSteer;
	static PIDController* driveTrainRearLeft;
	static AnalogInput* driveTrainRearRightPos;
	static WPI_TalonSRX* driveTrainRearRightSteer;
	static PIDController* driveTrainRearRight;
	static WPI_TalonSRX* elevatorMotor;
	static WPI_TalonSRX* rampWinchMotor;
	static Pigeon* pigeon;
	//static CameraServer* Cam;

	static void init();
};
#endif
