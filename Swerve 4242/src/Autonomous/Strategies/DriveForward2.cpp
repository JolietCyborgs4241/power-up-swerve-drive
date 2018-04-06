#include "DriveForward2.h"
#include "Autonomous/Commands/AutoDriveForward.h"
#include "Robot.h"

#include "Commands/ClawControl.h"
#include "Commands/ElevatorControl.h"
#include "Commands/ResetPigeonYaw.h"

DriveForward2::DriveForward2() {
    AddSequential(new ResetPigeonYaw);
    AddSequential(new AutoDriveForward(0.5, 2));
	SmartDashboard::PutString("Status", "Drive forward 2 auto");

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
    // e.g. ifx Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
}
