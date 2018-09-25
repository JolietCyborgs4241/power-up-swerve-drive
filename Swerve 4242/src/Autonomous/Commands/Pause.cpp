#include "Pause.h"
#include "Robot.h"
Pause::Pause(double timeout) {
    this->timeout = timeout;
}

// Called just before this Command runs the first time
void Pause::Initialize() {
    SetTimeout(timeout);
}

// Called repeatedly when this Command is scheduled to run
void Pause::Execute() {
    // pause
}

// Make this return true when this Command no longer needs to run execute()
bool Pause::IsFinished() {
    return IsTimedOut();
}

// Called once after isFinished returns true
void Pause::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pause::Interrupted() {
}
