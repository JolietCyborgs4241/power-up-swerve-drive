/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "StraightSwitch.h"
#include "Robot.h"

#include "Autonomous/Commands/AutoDriveForward.h"
#include "Autonomous/Commands/AutoStop.h"
#include "Autonomous/Commands/DropCube.h"

#include "Commands/ClawControl.h"
#include "Commands/ElevatorPosControl.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"

StraightSwitch::StraightSwitch() {

    AddSequential(new ResetPigeonYaw);
    AddSequential(new SetElevatorPosition);

    AddSequential(new ElevatorPosControl(2));
    AddSequential(new AutoDriveForward(2));
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
}
