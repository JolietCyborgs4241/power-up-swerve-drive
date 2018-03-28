/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "StrafeRightPos.h"
#include "Robot.h"

#include "Autonomous/Commands/PositionDrive.h"

StrafeRightPos::StrafeRightPos() {
    AddSequential(new PositionDrive(500, 0));
}
