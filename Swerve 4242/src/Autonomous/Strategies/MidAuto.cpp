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
#include "Autonomous/Commands/AutoDriveForward.h"

MidAuto::MidAuto() {
    AddSequential(new SetElevatorPosition);
    AddSequential(new ResetPigeonYaw(DRIVE_FORWARD_ANGLE));

    SmartDashboard::PutString("Status", "In Mid Auto");
    SmartDashboard::PutString("Status", Robot::gameData);

    if (Robot::gameData.length() == 3) {
        if (Robot::gameData[0] == 'R') {
            SmartDashboard::PutString("Status", "M: go for right");
            AddParallel(new AutoElevatorPosControl(2));
            AddSequential(new AutoDriveAngle(0.5, CENTER_DRIVE_ANGLE, 2));
            AddSequential(new AutoDriveForward(0.5, 1));
            AddSequential(new Pause(0.5));
            // Drive Forward
            AddSequential(new DropCube);
        } else if (Robot::gameData[0] == 'L') {
            SmartDashboard::PutString("Status", "M: go for left");
            AddParallel(new AutoElevatorPosControl(2));
            AddSequential(new AutoDriveAngle(0.5, 135, 2));
            AddSequential(new AutoDriveForward(0.5, 1));
            AddSequential(new Pause(0.5));
            // Drive Forward
            AddSequential(new DropCube);
        } else {
            SmartDashboard::PutString("Status", "M: go for baseline - no owner?");
            AddSequential(new AutoDriveAngle(0.5, CENTER_DRIVE_ANGLE, 2));
        }
    } else {
        SmartDashboard::PutString("Status", "M: go for baseline - no data");
        AddSequential(new AutoDriveAngle(0.5, CENTER_DRIVE_ANGLE, 2));
    }
}
