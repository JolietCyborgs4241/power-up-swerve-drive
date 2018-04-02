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

    //	AddSequential(new AutoStop(), 3.0);
    //	if (gameData.length() > 0) {
    //		if (gameData[1] == 'L') {
    //			//scale Positioning
    //			//AddSequential(new MoveToScale);
    //			//AddParallel(new ElevatorToScale);
    //			//AddSequential(new MoveOverScale);
    //			//AddSequential(new DropCube);
    //		} else if (gameData[0] == 'L') {
    //			//Switch Positioning
    //			//AddSequential(new MoveToSwitch);
    //			//AddParallel(new ElevatorToSwitch);
    //			//AddSequential(new MoveOverSwitch);
    //			//AddSequential(new DropCube);
    //		} else {
    //			//Cross field to score scale
    //			//AddSequential(new MoveToBaseline);
    //		}
    //	}


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
}
