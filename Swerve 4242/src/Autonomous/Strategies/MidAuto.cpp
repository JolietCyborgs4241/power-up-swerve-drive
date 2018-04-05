#include "MidAuto.h"
#include "Robot.h"

#include "Autonomous/AutoConstants.h"
#include "Autonomous/Commands/AutoDriveAngle.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
#include "Autonomous/Commands/BackAdjust.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/Pause.h"
#include "Autonomous/Commands/PositionDrive.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"

MidAuto::MidAuto() {
    AddSequential(new SetElevatorPosition);
    AddSequential(new ResetPigeonYaw(DRIVE_FORWARD_ANGLE));

    SmartDashboard::PutString("Status", "In Mid Auto");
    SmartDashboard::PutString("Status", Robot::gameData);

    if (Robot::gameData.length() == 3) {
        if (Robot::gameData[0] == 'R') {
            SmartDashboard::PutString("Status", "go for right");
            AddParallel(new AutoElevatorPosControl(2));
            AddParallel(new AutoDriveAngle(0.5, CENTER_DRIVE_ANGLE, 2));
            // Drive Forward
            AddSequential(new DropCube);
        } else if (Robot::gameData[0] == 'L') {
            SmartDashboard::PutString("Status", "go for left");
            AddParallel(new AutoElevatorPosControl(2));
            AddParallel(new AutoDriveAngle(0.5, -CENTER_DRIVE_ANGLE, 2));
            // Drive Forward
            AddSequential(new DropCube);
        } else {
            SmartDashboard::PutString("Status", "go for baseline");
            AddSequential(new AutoDriveAngle(0.5, CENTER_DRIVE_ANGLE, 2));
        }
    } else {
        SmartDashboard::PutString("Status", "go for baseline");
        AddSequential(new AutoDriveAngle(0.5, CENTER_DRIVE_ANGLE, 2));
    }
}
