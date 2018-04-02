#include "LeftAuto.h"
#include "Robot.h"

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
    AddSequential(new ResetPigeonYaw(0));

    SmartDashboard::PutString("Status", "In Left Auto");
    SmartDashboard::PutString("Status", Robot::gameData);

    if (Robot::gameData.length() == 3) {
        if (Robot::gameData[1] == 'L') {
            SmartDashboard::PutString("Status", "go for scale");
            AddParallel(new AutoElevatorPosControl(4));
            AddSequential(new PositionDrive(LIDAR_SCALE_DISTANCE, 0, LEFT));
            AddSequential(new Pause(0.2));
            AddSequential(new BackAdjust(4.20, 0));
            AddSequential(new DropCube);
        } else if (Robot::gameData[0] == 'L') {
            SmartDashboard::PutString("Status", "go for switch");
            AddParallel(new AutoElevatorPosControl(3));
            AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, 0, LEFT));
            AddSequential(new Pause(0.2));
            AddSequential(new BackAdjust(4.20, 0));
            AddSequential(new DropCube);
        } else {
            SmartDashboard::PutString("Status", "go for baseline");
            AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, 0, LEFT));
        }
    } else {
        SmartDashboard::PutString("Status", "go for baseline");
        AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, 0, LEFT));
    }
}
