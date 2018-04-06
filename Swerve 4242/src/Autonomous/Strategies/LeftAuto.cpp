#include "LeftAuto.h"
#include "Autonomous/Commands/AutoDriveForward.h"

#include "Robot.h"


#include "Commands/ClawControl.h"
#include "Commands/ElevatorControl.h"
#include "Commands/ResetPigeonYaw.h"
#include "Autonomous/Commands/MoveToSwitch.h"
#include "Autonomous/Commands/MoveOverScale.h"
#include "Autonomous/Commands/MoveOverSwitch.h"
#include "Autonomous/Commands/MoveToBaseline.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/Pause.h"
#include "Autonomous/Commands/PositionDrive.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
LeftAuto::LeftAuto() {

	AddSequential(new ResetPigeonYaw);
	AddSequential(new AutoDriveForward(2));
	std::string gameData;
	while(1) {
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		if (gameData.length() > 0) {
			break;
		}
	}

	AddSequential(new AutoStop(), 3.0);
	if (gameData.length() > 0) {
		if (gameData[1] == 'L') {
//			scale Positioning
			AddSequential(new MoveToScale);
			AddParallel(new AutoElevatorPosControl(4));
			AddSequential(new MoveOverScale);
			AddSequential(new DropCube);
		} else if (gameData[0] == 'L') {
			//Switch Positioning
			AddSequential(new MoveToSwitch);
			AddParallel(new AutoElevatorPosControl(2));
			AddSequential(new MoveOverSwitch);
			AddSequential(new DropCube);
		} else {
			//Cross field to score scale
			AddSequential(new MoveToBaseline);
		}
	}

    AddSequential(new ResetPigeonYaw);
    AddSequential(new AutoDriveForward(2));
    // std::string gameData;
    //	while(1) {
    //		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    //		if (gameData.length() > 0) {
    //			break;
    //		}
    //	}

#include "Autonomous/AutoConstants.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
#include "Autonomous/Commands/BackAdjust.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/Pause.h"
#include "Autonomous/Commands/PositionDrive.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"

LeftAuto::LeftAuto() {
    AddSequential(new SetElevatorPosition);
    AddSequential(new ResetPigeonYaw(STRAFE_LEFT_ANGLE));
>>>>>>> 1a5403826944b26ef7095fbfb0f705b2ad100337

    SmartDashboard::PutString("Status", "In Left Auto");
    SmartDashboard::PutString("Status", Robot::gameData);


    // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
    if (Robot::gameData.length() == 3) {
        if (Robot::gameData[1] == 'L') {
            SmartDashboard::PutString("Status", "L: go for scale");
            AddParallel(new AutoElevatorPosControl(4));
            AddSequential(new PositionDrive(LIDAR_SCALE_DISTANCE, STRAFE_LEFT_ANGLE, LEFT));
            AddSequential(new Pause(PAUSE_AFTER_LIDAR_POS));
            AddSequential(new BackAdjust(ULTRASONIC_BACK_DISTANCE, STRAFE_LEFT_ANGLE));
            AddSequential(new DropCube);
        } else if (Robot::gameData[0] == 'L') {
            SmartDashboard::PutString("Status", "L: go for switch");
            AddParallel(new AutoElevatorPosControl(3));
            AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, STRAFE_LEFT_ANGLE, LEFT));
            AddSequential(new Pause(PAUSE_AFTER_LIDAR_POS));
            AddSequential(new BackAdjust(ULTRASONIC_BACK_DISTANCE, STRAFE_LEFT_ANGLE));
            AddSequential(new DropCube);
        } else {
            SmartDashboard::PutString("Status", "L: go for baseline - no owner");
            AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, STRAFE_LEFT_ANGLE, LEFT));
        }
    } else {
        SmartDashboard::PutString("Status", "L: go for baseline - no data");
        AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, STRAFE_LEFT_ANGLE, LEFT));
    }
}
