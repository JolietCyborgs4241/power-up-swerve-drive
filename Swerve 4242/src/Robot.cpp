#include "Robot.h"
#include "Autonomous/MidAuto.h"
#include "Autonomous/LeftAuto.h"
#include "Autonomous/RightAuto.h"
#include "Autonomous/SwitchCube.h"
#include <Commands/PIDSubsystem.h>
#include <thread>

using namespace frc;

OI* Robot::oi = NULL;

DriveTrain* Robot::driveTrain = NULL;
Pigeon* Robot::pigeon = NULL;
Elevator* Robot::elevator = NULL;
Pneumatics* Robot::pneumatics = NULL;
IntakeDetection* Robot::intakeDetection = NULL;
LIDARLite* Robot::lidarLite = NULL;

double Robot::twistPID_Value = 0.0;
bool Robot::twistPID_Enabled = false;
PigeonPID* Robot::twistPID = NULL;

bool Robot::fieldCentric_Enabled = true;
bool Robot::deployedRamp = false;
bool Robot::rampLifted = false;

bool Robot::elevatorPositionControl_enabled = false;

PressureSensor* Robot::pressureSensor = NULL;
MB1013Sensor* Robot::mb1013Sensor = NULL;

void Robot::RobotInit() {
	RobotMap::init();

	oi = new OI();

	elevator = new Elevator();
	pneumatics = new Pneumatics();

	intakeDetection = new IntakeDetection();
	driveTrain = new DriveTrain();
	pigeon = new Pigeon();

	twistPID = new PigeonPID();
	twistPID->SetSetpoint(0);

	mb1013Sensor = new MB1013Sensor();

	/*lidarLite = new LIDARLite();
	std::thread lidarThread([]() {
		lidarLite->updateDistance();
	});*/

	chooser.AddDefault("NoAuto", new MidAuto());
	chooser.AddObject("MoveForward", new LeftAuto());
	chooser.AddObject("CubeInSwitch", new SwitchCube());
	//chooser.AddObject("RightAuto",new RightAuto());
	//CameraServer::GetInstance()->StartAutomaticCapture();
	//CameraServer::GetInstance()->SetQuality(30);
	CameraServer::GetInstance()->StartAutomaticCapture(0);
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

	pneumatics->Start();

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
}

void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("CycleTime", GetClock() - cycleTime);
	cycleTime = GetClock();

	pigeon->Update();

	if (twistPID_Enabled) {
		Robot::twistPID->Enable();
		twistPID_Value += oi->getJoystickZ()*2;
		driveTrain->Crab(twistPID_Value, -oi->getJoystickY(), oi->getJoystickX(), true);
	} else {
		Robot::twistPID->Disable();
		driveTrain->Crab(oi->getJoystickZ(), -oi->getJoystickY(), oi->getJoystickX(), fieldCentric_Enabled);
	}

	Dashboard();

	if (elevatorPositionControl_enabled) {
		elevator->PositionUpdate();
	} else {
		elevator->MoveElevator();
	}


	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

void Robot::Dashboard() {
	//Joystick Variables
	SmartDashboard::PutNumber("RightStickY", oi->getDriveJoystick()->GetY());
	SmartDashboard::PutNumber("RightStickX", oi->getDriveJoystick()->GetX());
	SmartDashboard::PutNumber("RightStickZ", oi->getDriveJoystick()->GetZ());

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

	SmartDashboard::PutNumber("IntakeDetection-Range", intakeDetection->GetRangeInches());

	SmartDashboard::PutBoolean("LimitSwitch", RobotMap::elevatorUpperLimitSwitch->Get());

	SmartDashboard::PutNumber("Pigeon-Yaw", pigeon->GetYaw());
	SmartDashboard::PutBoolean("Pigeon-AmTilted", pigeon->AmTilted());

	SmartDashboard::PutNumber("PigeonPID-Pos", twistPID->GetPosition());
	SmartDashboard::PutBoolean("PigeonPID-OnTarget", twistPID->OnTarget());
	SmartDashboard::PutNumber("PigeonPID-Twist", twistPID_Value);
	SmartDashboard::PutNumber("PigeonPID-Error", twistPID->PosError());

	SmartDashboard::PutBoolean("FieldCentric", fieldCentric_Enabled);
	SmartDashboard::PutBoolean("Twist-PID", twistPID_Enabled);

	SmartDashboard::PutNumber("Elevator-Distance", elevator->GetDistance());
	SmartDashboard::PutNumber("Elevator-Error", elevator->GetPIDError());
	SmartDashboard::PutBoolean("Elevator-PositionControl", elevatorPositionControl_enabled);

	//SmartDashboard::PutNumber("LidarLite", lidarLite->getDistance());

	//SmartDashboard::PutNumber("Pressure", pressureSensor->Pressure());
	SmartDashboard::PutNumber("Back-Distance", mb1013Sensor->ReadSensor());
}

START_ROBOT_CLASS(Robot);
