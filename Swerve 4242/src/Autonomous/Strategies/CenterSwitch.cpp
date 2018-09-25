#include "CenterSwitch.h"
#include "Robot.h"

#include "Autonomous/Commands/AutoDriveForward.h"
#include "Autonomous/Commands/AutoStop.h"
#include "Autonomous/Commands/DropCube.h"

#include "Commands/ClawControl.h"
#include "Commands/ElevatorPosControl.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"

CenterSwitch::CenterSwitch() {
    AddSequential(new ResetPigeonYaw);
    AddSequential(new SetElevatorPosition);

    AddSequential(new ElevatorPosControl(3));
    AddSequential(new AutoDriveForward(0.5, 2));
    AddSequential(new DropCube);

    /*
        std::string gameData;

        int count = 100;
        while (count-- > 0) {
                gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
                if (gameData.length() > 0) {
                        break;
                }
        }

        if (gameData.length() > 0) {
                if (gameData[0] == 'R') {
                        AddSequential(new ElevatorPosControl(4));
                        AddSequential(new AutoDriveForward);
                        AddSequential(new DropCube);
                } else {
                        AddSequential(new AutoDriveForward);
                }
        } else {
                AddSequential(new AutoDriveForward);
        }*/

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
}
