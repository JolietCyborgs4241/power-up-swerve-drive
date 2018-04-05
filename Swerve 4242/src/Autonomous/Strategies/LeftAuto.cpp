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
    AddSequential(new ResetPigeonYaw(STRAFE_LEFT_ANGLE));

    SmartDashboard::PutString("Status", "In Left Auto");
    SmartDashboard::PutString("Status", Robot::gameData);

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
