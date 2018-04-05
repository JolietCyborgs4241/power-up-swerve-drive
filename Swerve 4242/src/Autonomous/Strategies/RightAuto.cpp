#include "RightAuto.h"
#include "Robot.h"

#include "Autonomous/AutoConstants.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
#include "Autonomous/Commands/BackAdjust.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/Pause.h"
#include "Autonomous/Commands/PositionDrive.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"

RightAuto::RightAuto() {
    AddSequential(new SetElevatorPosition);
    AddSequential(new ResetPigeonYaw(STRAFE_RIGHT_ANGLE));

    SmartDashboard::PutString("Status", "In Right Auto");
    SmartDashboard::PutString("Status", Robot::gameData);

    if (Robot::gameData.length() == 3) {
        if (Robot::gameData[1] == 'R') {
            SmartDashboard::PutString("Status", "go for scale");
            AddParallel(new AutoElevatorPosControl(4));
            AddSequential(new PositionDrive(LIDAR_SCALE_DISTANCE, STRAFE_RIGHT_ANGLE, RIGHT));
            AddSequential(new Pause(PAUSE_AFTER_LIDAR_POS));
            AddSequential(new BackAdjust(ULTRASONIC_BACK_DISTANCE, STRAFE_RIGHT_ANGLE));
            AddSequential(new DropCube);
        } else if (Robot::gameData[0] == 'R') {
            SmartDashboard::PutString("Status", "go for switch");
            AddParallel(new AutoElevatorPosControl(3));
            AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, STRAFE_RIGHT_ANGLE, RIGHT));
            AddSequential(new Pause(PAUSE_AFTER_LIDAR_POS));
            AddSequential(new BackAdjust(ULTRASONIC_BACK_DISTANCE, STRAFE_RIGHT_ANGLE));
            AddSequential(new DropCube);
        } else {
            SmartDashboard::PutString("Status", "go for baseline");
            AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, STRAFE_RIGHT_ANGLE, RIGHT));
        }
    } else {
        SmartDashboard::PutString("Status", "go for baseline");
        AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, STRAFE_RIGHT_ANGLE, RIGHT));
    }
}
