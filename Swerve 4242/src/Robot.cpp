#include "Robot.h"

#include "Autonomous/Strategies/CenterSwitch.h"
#include "Autonomous/Strategies/DriveForward2.h"
#include "Autonomous/Strategies/LeftAuto.h"
#include "Autonomous/Strategies/LeftAutoSwitch.h"
#include "Autonomous/Strategies/MidAuto.h"
#include "Autonomous/Strategies/NoAuto.h"
#include "Autonomous/Strategies/RightAuto.h"
#include "Autonomous/Strategies/RightAutoSwitch.h"
#include "Autonomous/Strategies/StraightSwitch.h"

#include <thread>

using namespace frc;

OI* Robot::oi = NULL;

DriveTrain* Robot::driveTrain = NULL;
Pigeon* Robot::pigeon = NULL;
Elevator* Robot::elevator = NULL;
Pneumatics* Robot::pneumatics = NULL;

LIDARLite* Robot::leftLidarLite = NULL;
LIDARLite* Robot::rightLidarLite = NULL;

bool Robot::gyroAssist = false;
PigeonPID* Robot::gyroAssistPID = NULL;

bool Robot::fieldCentric = true;
bool Robot::elevatorPositionControl = false;
bool Robot::useUpperLimitSwitch = true;

MB1013Sensor* Robot::mb1013Sensor = NULL;

std::string Robot::gameData = "";
bool Robot::recievedGameData = false;
Timer* Robot::autoTimer = new Timer();

void Robot::RobotInit() {
    RobotMap::init();

    oi = new OI();

    elevator = new Elevator();
    pneumatics = new Pneumatics();

    driveTrain = new DriveTrain();
    pigeon = new Pigeon();

    gyroAssistPID = new PigeonPID();
    gyroAssistPID->SetSetpoint(0);

    mb1013Sensor = new MB1013Sensor();

    leftLidarLite = new LIDARLite(13);
    rightLidarLite = new LIDARLite(14);

    chooser.AddDefault("NoAuto", 1);
    chooser.AddObject("DriveForward-2", 2);
    chooser.AddObject("LeftAuto", 3);
    chooser.AddObject("RightAuto", 4);
    chooser.AddObject("StraightSwitch", 5);
    chooser.AddObject("CenterSwitch", 6);
    chooser.AddObject("MidAuto", 7);
    chooser.AddObject("LeftAutoSwitch", 8);
    chooser.AddObject("RightAutoSwitch", 9);

    SmartDashboard::PutData("Auto Modes", &chooser);

    CameraServer::GetInstance()->StartAutomaticCapture(0);

    lw = LiveWindow::GetInstance();

    driveTrain->SetWheelbase(24, 22, 24);
    FLOffset = 0;
    FROffset = 0;
    RLOffset = 0;
    RROffset = 0;

    // FL, FR, RL, RR
    driveTrain->SetOffsets(FLOffset, FROffset, RLOffset, RROffset);

    driveTrain->frontLeft->Enable();
    driveTrain->frontRight->Enable();
    driveTrain->rearLeft->Enable();
    driveTrain->rearRight->Enable();

    pneumatics->Start();
}

void Robot::DisabledInit() {
    // Makes sure that enabling the robot doesn't
    // make the elevator shoot to the last position
    elevatorPositionControl = false;
    // RobotMap::elevatorMotor->Set(0);
}

void Robot::DisabledPeriodic() {
}

void Robot::AutonomousInit() {
    pigeon->Update();
    pigeon->SaveTilt();

    driveTrain->EnablePIDs();

    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

    autoTimer->Reset();
    autoTimer->Start();
}

void Robot::AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();

    if (!recievedGameData && autoTimer->Get() < 8) {
        gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

        if (gameData.length() > 0) {
            recievedGameData = true;
            SmartDashboard::PutString("FMS Data!", gameData);

            int command = chooser.GetSelected();
            switch (command) {
            case 1:
                autonomousCommand.reset(new NoAuto());
                break;
            case 2:
                autonomousCommand.reset(new DriveForward2());
                break;
            case 3:
                autonomousCommand.reset(new LeftAuto());
                break;
            case 4:
                autonomousCommand.reset(new RightAuto());
                break;
            case 5:
                autonomousCommand.reset(new StraightSwitch());
                break;
            case 6:
                autonomousCommand.reset(new CenterSwitch());
                break;
            case 7:
                autonomousCommand.reset(new MidAuto());
                break;
            case 8:
                autonomousCommand.reset(new LeftAutoSwitch());
                break;
            case 9:
                autonomousCommand.reset(new RightAutoSwitch());
                break;
            default:
                autonomousCommand.reset(new NoAuto());
            }
            if (autonomousCommand.get() != NULL) {
                autonomousCommand->Start();
            }
        } else if (!recievedGameData && autoTimer->Get() >= 8) {
            // didn't actually receive game data, but we only want to one auto once
            recievedGameData = true;

            int command = chooser.GetSelected();
            switch (command) {
            case 1:
                autonomousCommand.reset(new NoAuto());
                break;
            case 2:
                autonomousCommand.reset(new DriveForward2());
                break;
            case 3:
                // make it run baseline code
                gameData = "RRR"; // fake data on right side
                autonomousCommand.reset(new LeftAuto());
                break;
            case 4:
                // make it run baseline code
                gameData = "LLL"; // fake data on left side
                autonomousCommand.reset(new RightAuto());
                break;
            case 5:
                // straight switch deals with no data
                autonomousCommand.reset(new StraightSwitch());
                break;
            case 6:
                // center switch deals with no data
                autonomousCommand.reset(new CenterSwitch());
                break;
            case 7:
                // mid auto deals with no data
                autonomousCommand.reset(new MidAuto());
                break;
            case 8:
                // goes to baseline with no data
                autonomousCommand.reset(new LeftAutoSwitch());
                break;
            case 9:
                // goes to baseline with no data
                autonomousCommand.reset(new RightAutoSwitch());
                break;
            default:
                autonomousCommand.reset(new NoAuto());
            }
            if (autonomousCommand.get() != NULL) {
                autonomousCommand->Start();
            }
        }
    }
}

void Robot::TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.

    Scheduler::GetInstance()->RemoveAll();

    cycleTime = Timer::GetFPGATimestamp();

    pigeon->Update();
    pigeon->SaveTilt();

    driveTrain->EnablePIDs();

    pneumatics->CloseClaw();
    pneumatics->RetractPiston();
}

void Robot::TeleopPeriodic() {
    SmartDashboard::PutNumber("CycleTime", Timer::GetFPGATimestamp() - cycleTime);
    cycleTime = Timer::GetFPGATimestamp();

    // Drive Control
    // joystickY is -up, so invert to match +Y -> forward
    // joystickX is +right, so do nothing to match +X -> right
    // joystickZ is +right, so invert to match -twist -> clockwise (decrement angle on unit circle)
    if (gyroAssist) {
        driveTrain->Crab(-oi->getDriveLeftY(), oi->getDriveLeftX(), gyroAssistPID->GetOutput(), true);
    } else {
        driveTrain->Crab(-oi->getDriveLeftY(), oi->getDriveLeftX(), -oi->getDriveRightX(), fieldCentric);
    }

    /*
    // Elevator Control
    if (elevatorPositionControl) {
        elevator->PositionUpdate();
    } else {
        elevator->MoveElevator();
    }
    */

    elevator->MoveElevator();

    Dashboard();

    Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
    driveTrain->DisablePIDs();
    Dashboard();
}

void Robot::Dashboard() {
    // Joystick Variables
    SmartDashboard::PutNumber("DriveStickY", oi->getDriveJoystick()->GetY());
    SmartDashboard::PutNumber("DriveStickX", oi->getDriveJoystick()->GetX());
    SmartDashboard::PutNumber("DriveStickZ", oi->getDriveJoystick()->GetZ());

    // Wheel Module Voltages
    SmartDashboard::PutNumber("FrontLeftVol", driveTrain->frontLeftPos->GetAverageVoltage());
    SmartDashboard::PutNumber("FrontRightVol", driveTrain->frontRightPos->GetAverageVoltage());
    SmartDashboard::PutNumber("RearLeftVol", driveTrain->rearLeftPos->GetAverageVoltage());
    SmartDashboard::PutNumber("RearRightVol", driveTrain->rearRightPos->GetAverageVoltage());
    // Wheel Module Errors
    SmartDashboard::PutNumber("FLError", driveTrain->frontLeft->GetError());
    SmartDashboard::PutNumber("FRError", driveTrain->frontRight->GetError());
    SmartDashboard::PutNumber("RLError", driveTrain->rearLeft->GetError());
    SmartDashboard::PutNumber("RRError", driveTrain->rearRight->GetError());
    // Wheel Module Setpoints
    SmartDashboard::PutNumber("FLSetPoint", driveTrain->frontLeft->GetSetpoint());
    SmartDashboard::PutNumber("FRSetPoint", driveTrain->frontRight->GetSetpoint());
    SmartDashboard::PutNumber("RLSetPoint", driveTrain->rearLeft->GetSetpoint());
    SmartDashboard::PutNumber("RRSetPoint", driveTrain->rearRight->GetSetpoint());

    SmartDashboard::PutBoolean("LimitSwitch", RobotMap::elevatorUpperLimitSwitch->Get());

    SmartDashboard::PutNumber("Pigeon-Yaw", pigeon->GetYaw());
    SmartDashboard::PutBoolean("Pigeon-AmTilted", pigeon->AmTilted());
    SmartDashboard::PutBoolean("Pigeon-COLLIDED", pigeon->WasCollision());

    SmartDashboard::PutBoolean("Gyro-Assist", gyroAssist);
    SmartDashboard::PutNumber("GyroPID-Pos", gyroAssistPID->GetPosition());
    SmartDashboard::PutBoolean("GyroPID-OnTarget", gyroAssistPID->OnTarget());
    SmartDashboard::PutNumber("GyroPID-Twist", gyroAssistPID->GetOutput());
    SmartDashboard::PutNumber("GyroPID-Error", gyroAssistPID->GetDegError());

    SmartDashboard::PutNumber("Elevator-Distance", elevator->GetDistance());
    SmartDashboard::PutNumber("Elevator-Error", elevator->GetPIDError());

    SmartDashboard::PutNumber("LidarLite-Left", leftLidarLite->SmoothedDistanceFeet());
    SmartDashboard::PutNumber("LidarLite-Right", rightLidarLite->SmoothedDistanceFeet());

    SmartDashboard::PutNumber("Back-Distance", mb1013Sensor->SmoothedDistanceFeet());

    SmartDashboard::PutBoolean("FieldCentric", fieldCentric);
    SmartDashboard::PutBoolean("Use-UpperLimitSwitch", useUpperLimitSwitch);
    SmartDashboard::PutBoolean("Elevator-PositionControl", elevatorPositionControl);
    SmartDashboard::PutBoolean("Precision-Drive", driveTrain->precisionDrive);
}

START_ROBOT_CLASS(Robot);
