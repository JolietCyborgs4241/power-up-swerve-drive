#include "RightAuto.h"
#include "Robot.h"

#include "Autonomous/AutoConstants.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/PositionDrive.h"
#include "Commands/SetElevatorPosition.h"

RightAuto::RightAuto() {
    AddSequential(new SetElevatorPosition);

    if (Robot::gameData[1] == 'R') {
        AddSequential(new PositionDrive(LIDAR_SCALE_DISTANCE, 180, RIGHT));
        AddSequential(new AutoElevatorPosControl(4));
        AddSequential(new DropCube);
    } else if (Robot::gameData[0] == 'R') {
        AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, 180, RIGHT));
        AddSequential(new AutoElevatorPosControl(3));
        AddSequential(new DropCube);
    } else {
        AddSequential(new PositionDrive(LIDAR_SWITCH_DISTANCE, 180, RIGHT));
    }
}
