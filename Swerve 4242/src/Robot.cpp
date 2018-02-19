// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
#include "Autonomous/MidAuto.h"
#include "Autonomous/LeftAuto.h"
#include "Autonomous/RightAuto.h"
using namespace frc;

OI* Robot::oi = NULL;

DriveTrain* Robot::driveTrain = NULL;
Pigeon* Robot::pigeon = NULL;
Elevator* Robot::elevator = NULL;
Pneumatics* Robot::pneumatics = NULL;
IntakeDetection* Robot::intakeDetection = NULL;
IntakeServo* Robot::intakeServo = NULL;
ElevatorPosControl* Robot::elevatorPosControl = NULL;
CycleElevator* Robot::cycleElevator = NULL;
Joystick *exampleStick = NULL;


void Robot::RobotInit() {
	//VV for d'pad control on ps4 controller VV
	exampleStick = new Joystick(1);
//	double Joystick::GetAxis(kYAxis 9) const;
	//^^ for d'pad control on ps4 controller ^^
	RobotMap::init();

	oi = new OI();

	elevator = new Elevator();
	pneumatics = new Pneumatics();

	intakeDetection = new IntakeDetection();



	driveTrain = new DriveTrain();
	pigeon = new Pigeon();

	chooser.AddDefault("Auto", new MidAuto());
	chooser.AddObject("LeftAuto",new LeftAuto());
	chooser.AddObject("RightAuto",new RightAuto());
	//CameraServer::GetInstance()->SetQuality(30);
	//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
    // Create an image

	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	prevTrigger = false;

	driveTrain->SetWheelbase(24, 22, 24);
	FLOffset = 0;
	FROffset = 0;
	RLOffset = 0;
	RROffset = 0;

	//Read XXVolt from SmartDashboard with wheels aligned.  Subtract 2.5 from each value and put in function below.
	//FL, FR, RL, RR
	driveTrain->SetOffsets(FLOffset, FROffset, RLOffset, RROffset);

	driveTrain->frontLeft->Enable();
	driveTrain->frontRight->Enable();
	driveTrain->rearLeft->Enable();
	driveTrain->rearRight->Enable();

	//pneumatics->Start();

	frc::SmartDashboard::PutData("Auto Modes", &chooser);


}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

void Robot::AutonomousInit() {
	autonomousCommand.reset(chooser.GetSelected());
	if (autonomousCommand.get() != NULL) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	cycleTime = GetClock();
	incnum = 1;
	//pigeon->pidgeon->EnterCalibrationMode(ctre::phoenix::sensors::PigeonIMU::Temperature, 0);
}

void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("CycleTime", GetClock() - cycleTime);
	cycleTime = GetClock();

	driveTrain->Crab(-oi->getJoystickZ(),-oi->getJoystickX(),oi->getJoystickY(), true);
	Dashboard();


	//elevator->PositionUpdate();
	elevator->MoveElevator();
	SmartDashboard::PutNumber("Pigeon-temp", pigeon->pidgeon->GetTemp());

	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

void Robot::Dashboard() {
	//Joystick Variables

	SmartDashboard::PutNumber("RightStickY", oi->getDriverJoystickRight()->GetY());
	SmartDashboard::PutNumber("RightStickX", oi->getDriverJoystickRight()->GetX());
	SmartDashboard::PutNumber("RightStickZ", oi->getDriverJoystickRight()->GetZ());

	//Wheel Module Voltages
	SmartDashboard::PutNumber("FrontLeftVol",  driveTrain->frontLeftPos->GetAverageVoltage());
	SmartDashboard::PutNumber("FrontRightVol", driveTrain->frontRightPos->GetAverageVoltage());
	SmartDashboard::PutNumber("RearLeftVol",   driveTrain->rearLeftPos->GetAverageVoltage());
	SmartDashboard::PutNumber("RearRightVol",  driveTrain->rearRightPos->GetAverageVoltage());
	//Wheel Module Errors
	SmartDashboard::PutNumber("FLError", driveTrain->frontLeft->GetError());
	SmartDashboard::PutNumber("FRError", driveTrain->frontRight->GetError());
	SmartDashboard::PutNumber("RLError", driveTrain->rearLeft->GetError());
	SmartDashboard::PutNumber("RRError", driveTrain->rearRight->GetError());
	//Wheel Module Setpoints
	SmartDashboard::PutNumber("FLSetPoint", driveTrain->frontLeft->GetSetpoint());
	SmartDashboard::PutNumber("FRSetPoint", driveTrain->frontRight->GetSetpoint());
	SmartDashboard::PutNumber("RLSetPoint", driveTrain->rearLeft->GetSetpoint());
	SmartDashboard::PutNumber("RRSetPoint", driveTrain->rearRight->GetSetpoint());

	SmartDashboard::PutNumber("DriveGyro", pigeon->GetYaw());


	SmartDashboard::PutNumber("IntakeDetection-Range",    intakeDetection->GetRangeInches());
	SmartDashboard::PutBoolean("IntakeDetection-Valid",   intakeDetection->ultra->IsRangeValid());
	SmartDashboard::PutBoolean("IntakeDetection-Enabled", intakeDetection->ultra->IsEnabled());

	SmartDashboard::PutNumber("Elevator-Distance", elevator->GetDistance());
	SmartDashboard::PutNumber("Elevator-Error", elevator->GetPIDError());
<<<<<<< HEAD
	SmartDashboard::PutNumber("Elevator-SetPoint", cycleElevator->ElevatorCycleNum);
=======
<<<<<<< HEAD
	*/
	SmartDashboard::PutNumber("Elevator-SetPoint", cycleElevator->ElevatorCycleNum);

>>>>>>> parent of 5b37c8e... revert 'commented stuff out to get 4243 working'
}

START_ROBOT_CLASS(Robot);
