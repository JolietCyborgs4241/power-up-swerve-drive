/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "StraightSwitch.h"
#include "Robot.h"

#include "Autonomous/AutoConstants.h"
#include "Autonomous/Commands/AutoDriveForward.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/Pause.h"

#include "Commands/ClawControl.h"
#include "Commands/ElevatorPosControl.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"

StraightSwitch::StraightSwitch() {
    AddSequential(new SetElevatorPosition);
    AddSequential(new ResetPigeonYaw(DRIVE_FORWARD_ANGLE));

    SmartDashboard::PutString("Status", "In Straight Switch");
    SmartDashboard::PutString("Status", Robot::gameData);

    const double speed = 0.5;
    const double timeout = 2;

    if (Robot::gameData.length() == 3) {
        if (Robot::gameData[0] == 'R') {
            SmartDashboard::PutString("Status", "SS: go straight for switch");
            AddParallel(new AutoElevatorPosControl(2));
            AddSequential(new AutoDriveForward(speed, timeout));
            AddSequential(new Pause(0.5));
            AddSequential(new DropCube);
        } else if (Robot::gameData[0] == 'L') {
            SmartDashboard::PutString("Status", "SS: left side - just drive forward");
            AddSequential(new AutoDriveForward(speed, timeout));
        } else {
            SmartDashboard::PutString("Status", "SS: go for baseline - no owner?");
            AddSequential(new AutoDriveForward(speed, timeout));
        }
    } else {
        SmartDashboard::PutString("Status", "SS: go for baseline - no data");
        AddSequential(new AutoDriveForward(speed, timeout));
    }
}
