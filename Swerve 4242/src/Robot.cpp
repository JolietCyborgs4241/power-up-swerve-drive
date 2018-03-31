#include "Robot.h"

#include "Autonomous/Strategies/NoAuto.h"
#include "Autonomous/Strategies/DriveForward2.h"
#include "Autonomous/Strategies/StraightSwitch.h"
#include "Autonomous/Strategies/CenterSwitch.h"
#include "Autonomous/Strategies/StrafeRightPos.h"

#include <Commands/PIDSubsystem.h>
#include <thread>

using namespace frc;

OI* Robot::oi = NULL;

DriveTrain* Robot::driveTrain = NULL;
Pigeon* Robot::pigeon = NULL;
Elevator* Robot::elevator = NULL;
Pneumatics* Robot::pneumatics = NULL;

LIDARLite* Robot::leftLidarLite = NULL;
LIDARLite* Robot::rightLidarLite = NULL;

PigeonPID* Robot::twistPID = NULL;

bool Robot::gyroAssist = false;
bool Robot::fieldCentric = true;
bool Robot::elevatorPositionControl = false;
bool Robot::useUpperLimitSwitch = true;

MB1013Sensor* Robot::mb1013Sensor = NULL;

void Robot::RobotInit() {
	RobotMap::init();

	oi = new OI();

	elevator = new Elevator();
	pneumatics = new Pneumatics();

	driveTrain = new DriveTrain();
	pigeon = new Pigeon();

	twistPID = new PigeonPID();
	twistPID->SetSetpoint(0);

	mb1013Sensor = new MB1013Sensor();

	leftLidarLite = new LIDARLite(13);
	rightLidarLite = new LIDARLite(14);

	chooser.AddDefault("NoAuto", new NoAuto());
	chooser.AddObject("DriveForward-2", new DriveForward2());
	chooser.AddObject("StraightSwitch", new StraightSwitch());
    chooser.AddObject("CenterSwitch", new CenterSwitch());
    //chooser.AddObject("StrafePos", new StrafeRightPos());

	CameraServer::GetInstance()->StartAutomaticCapture(0);

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
	cycleTime = Timer::GetFPGATimestamp();
	incnum = 1;
}

void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("CycleTime", Timer::GetFPGATimestamp() - cycleTime);
	cycleTime = Timer::GetFPGATimestamp();

    // Drive Control
	if (gyroAssist) {
		twistPID->Enable();
        //twistPID->output += oi->getJoystickZ()*2;
		driveTrain->Crab(twistPID->output, -oi->getJoystickY(), oi->getJoystickX(), true);
	} else {
		Robot::twistPID->Disable();
		driveTrain->Crab(oi->getJoystickZ(), -oi->getJoystickY(), oi->getJoystickX(), fieldCentric);
	}

    // Elevator Control
	if (elevatorPositionControl) {
		elevator->PositionUpdate();
	} else {
		elevator->MoveElevator();
	}

	Dashboard();

	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	//lw->Run();
}

void Robot::Dashboard() {
	//Joystick Variables
	SmartDashboard::PutNumber("DriveStickY", oi->getDriveJoystick()->GetY());
	SmartDashboard::PutNumber("DriveStickX", oi->getDriveJoystick()->GetX());
	SmartDashboard::PutNumber("DriveStickZ", oi->getDriveJoystick()->GetZ());

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

	SmartDashboard::PutBoolean("LimitSwitch", RobotMap::elevatorUpperLimitSwitch->Get());

	SmartDashboard::PutNumber("Pigeon-Yaw", pigeon->GetYaw());
	SmartDashboard::PutBoolean("Pigeon-AmTilted", pigeon->AmTilted());
	SmartDashboard::PutBoolean("Pigeon-COLLIDED", pigeon->WasCollision());

	SmartDashboard::PutNumber("PigeonPID-Pos", twistPID->GetPosition());
	SmartDashboard::PutBoolean("PigeonPID-OnTarget", twistPID->OnTarget());
	SmartDashboard::PutNumber("PigeonPID-Twist", twistPID->output);
	SmartDashboard::PutNumber("PigeonPID-Error", twistPID->PosError());

	SmartDashboard::PutNumber("Elevator-Distance", elevator->GetDistance());
	SmartDashboard::PutNumber("Elevator-Error", elevator->GetPIDError());

	SmartDashboard::PutNumber("LidarLite-Left", leftLidarLite->SmoothedDistanceCM() * 0.032808399);
	SmartDashboard::PutNumber("LidarLite-Right", rightLidarLite->SmoothedDistanceCM() * 0.032808399);

	SmartDashboard::PutNumber("Back-Distance", mb1013Sensor->SmoothedDistanceCM() * 0.032808399);

	SmartDashboard::PutBoolean("FieldCentric", fieldCentric);
	SmartDashboard::PutBoolean("Twist-PID", gyroAssist);
    SmartDashboard::PutBoolean("Use-UpperLimitSwitch", useUpperLimitSwitch);
	SmartDashboard::PutBoolean("Elevator-PositionControl", elevatorPositionControl);
    SmartDashboard::PutBoolean("Precision-Drive", driveTrain->precisionDrive);
    SmartDashboard::PutNumber("Precision-Adjust", driveTrain->driveAdjust);
	//SmartDashboard::PutNumber("Pressure", pressureSensor->Pressure());
}

START_ROBOT_CLASS(Robot);
