#include "ResetGyroAngle.h"
#include "ctre/Phoenix.h"
#include "Robot.h"
ResetGyroAngle::ResetGyroAngle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::analog_Gyro);
}

// Called just before this Command runs the first time
void ResetGyroAngle::Initialize() {
	Robot::analog_Gyro->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void ResetGyroAngle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ResetGyroAngle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ResetGyroAngle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetGyroAngle::Interrupted() {

}
