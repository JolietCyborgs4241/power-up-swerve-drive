#include "StrafeRightPos.h"
#include "Robot.h"

#include "Autonomous/AutoConstants.h"
#include "Autonomous/Commands/AutoElevatorPosControl.h"
#include "Autonomous/Commands/DropCube.h"
#include "Autonomous/Commands/PositionDrive.h"
#include "Commands/SetElevatorPosition.h"

StrafeRightPos::StrafeRightPos() {
    AddSequential(new SetElevatorPosition);
    AddSequential(new PositionDrive(12.5, 0, Robot::rightLidarLite));
    AddSequential(new AutoElevatorPosControl(3));
    AddSequential(new DropCube);
}
