// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
#include "WPILib.h"
using namespace frc;
WPI_TalonSRX* RobotMap::driveTrainFrontLeftDrive = NULL;
WPI_TalonSRX* RobotMap::driveTrainFrontRightDrive = NULL;
WPI_TalonSRX* RobotMap::driveTrainRearLeftDrive = NULL;
WPI_TalonSRX* RobotMap::driveTrainRearRightDrive = NULL;

AnalogInput* RobotMap::driveTrainFrontLeftPos = NULL;
WPI_TalonSRX* RobotMap::driveTrainFrontLeftSteer = NULL;
PIDController* RobotMap::driveTrainFrontLeft = NULL;

AnalogInput* RobotMap::driveTrainFrontRightPos = NULL;
WPI_TalonSRX* RobotMap::driveTrainFrontRightSteer = NULL;
PIDController* RobotMap::driveTrainFrontRight = NULL;

AnalogInput* RobotMap::driveTrainRearLeftPos = NULL;
WPI_TalonSRX* RobotMap::driveTrainRearLeftSteer = NULL;
PIDController* RobotMap::driveTrainRearLeft = NULL;

AnalogInput* RobotMap::driveTrainRearRightPos = NULL;
WPI_TalonSRX* RobotMap::driveTrainRearRightSteer = NULL;
PIDController* RobotMap::driveTrainRearRight = NULL;
/*
double RobotMap::angleDrive = 0;*/
//Analog_Gyro* RobotMap::analog_Gyro = NULL;

WPI_TalonSRX* RobotMap::elevatorMotor = NULL;
DigitalInput* RobotMap::elevatorUpperLimitSwitch = NULL;
DigitalInput* RobotMap::elevatorBottomLimitSwitch = NULL;

//CameraServer* RobotMap::Cam = NULL;

void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();

	elevatorMotor = new WPI_TalonSRX(4);
	elevatorUpperLimitSwitch = new DigitalInput(0);
	elevatorBottomLimitSwitch = new DigitalInput(1);


	driveTrainFrontLeftDrive = new WPI_TalonSRX(6);
	
	driveTrainFrontRightDrive = new WPI_TalonSRX(2);
	
	driveTrainRearLeftDrive = new WPI_TalonSRX(8);
	
	driveTrainRearRightDrive = new WPI_TalonSRX(10);
	
    driveTrainRearRightPos = new AnalogInput(0);
	lw->AddSensor("DriveTrain", "RearRightPos", driveTrainRearRightPos);
	driveTrainRearRightSteer = new WPI_TalonSRX(1);
	driveTrainRearRight = new PIDController(0.6, 0.0, 0.0, driveTrainRearRightPos, driveTrainRearRightSteer, 0.02);
	lw->AddActuator("DriveTrain", "RearRight", driveTrainRearRight);
	driveTrainRearRight->SetContinuous(true);
	driveTrainRearRight->SetAbsoluteTolerance(0.1);
    driveTrainRearRight->SetInputRange(0.0, 5.0);
    driveTrainRearRight->SetOutputRange(-1, 1);

	driveTrainFrontLeftPos = new AnalogInput(2);
	lw->AddSensor("DriveTrain", "FrontLeftPos", driveTrainFrontLeftPos);
	driveTrainFrontLeftSteer = new WPI_TalonSRX(7);
	driveTrainFrontLeft = new PIDController(0.6, 0.0, 0.0, driveTrainFrontLeftPos, driveTrainFrontLeftSteer, 0.02);
	lw->AddActuator("DriveTrain", "FrontLeft", driveTrainFrontLeft);
	driveTrainFrontLeft->SetContinuous(true);
	driveTrainFrontLeft->SetAbsoluteTolerance(0.1);
    driveTrainFrontLeft->SetInputRange(0.0, 5.0);
    driveTrainFrontLeft->SetOutputRange(-1, 1);
	
    driveTrainFrontRightPos = new AnalogInput(3);
	lw->AddSensor("DriveTrain", "FrontRightPos", driveTrainFrontRightPos);
	driveTrainFrontRightSteer = new WPI_TalonSRX(3);
	driveTrainFrontRight = new PIDController(0.6, 0.0, 0.0, driveTrainFrontRightPos, driveTrainFrontRightSteer, 0.02);
	lw->AddActuator("DriveTrain", "FrontRight", driveTrainFrontRight);
	driveTrainFrontRight->SetContinuous(true);
	driveTrainFrontRight->SetAbsoluteTolerance(0.1);
    driveTrainFrontRight->SetInputRange(0.0, 5.0);
    driveTrainFrontRight->SetOutputRange(-1, 1);
	
    driveTrainRearLeftPos = new AnalogInput(1);
	lw->AddSensor("DriveTrain", "RearLeftPos", driveTrainRearLeftPos);
	driveTrainRearLeftSteer = new WPI_TalonSRX(9);
	driveTrainRearLeft = new PIDController(0.6, 0.0, 0.0, driveTrainRearLeftPos, driveTrainRearLeftSteer, 0.02);
	lw->AddActuator("DriveTrain", "RearLeft", driveTrainRearLeft);
	driveTrainRearLeft->SetContinuous(true);
	driveTrainRearLeft->SetAbsoluteTolerance(0.1);
    driveTrainRearLeft->SetInputRange(0.0, 5.0);
    driveTrainRearLeft->SetOutputRange(-1, 1);

	//driveTrainFrontLeftSteer->DisableSoftPositionLimits();
	//driveTrainFrontRightSteer->DisableSoftPositionLimits();
	//driveTrainRearLeftSteer->DisableSoftPositionLimits();
	//driveTrainRearRightSteer->DisableSoftPositionLimits();

	driveTrainFrontLeftPos->SetAverageBits(256);
	driveTrainFrontRightPos->SetAverageBits(256);
	driveTrainRearLeftPos->SetAverageBits(256);
	driveTrainRearRightPos->SetAverageBits(256);
}
