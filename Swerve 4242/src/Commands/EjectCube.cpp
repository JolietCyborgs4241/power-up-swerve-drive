#include "EjectCube.h"
#include "Robot.h"

EjectCube::EjectCube() {
    // Requires(Robot::pneumatics);
}

// Called just before this Command runs the first time
void EjectCube::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void EjectCube::Execute() {
    Robot::pneumatics->PushPiston();
    Robot::pneumatics->OpenClaw();
}

// Make this return true when this Command no longer needs to run execute()
bool EjectCube::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void EjectCube::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectCube::Interrupted() {
}
