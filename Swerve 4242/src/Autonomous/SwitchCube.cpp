/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SwitchCube.h"
#include "Robot.h"
#include "Commands/ClawControl.h"
#include "Autonomous/AutoDriveForward.h"
#include "Commands/ElevatorPosControl.h"
#include "Autonomous/AutoStop.h"
#include "Commands/IntakeActuate.h"
#include "Commands/ResetPigeonYaw.h"
#include "Autonomous/DropCube.h"

SwitchCube::SwitchCube() {
	AddSequential(new ResetPigeonYaw);

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
	}

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
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
