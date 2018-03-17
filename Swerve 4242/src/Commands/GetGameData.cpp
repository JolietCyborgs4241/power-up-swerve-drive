#include "GetGameData.h"
#include "Robot.h"
GetGameData::GetGameData() {
	//Requires(Robot::pigeon);
}

// Called just before this Command runs the first time
void GetGameData::Initialize() {
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void GetGameData::Execute() {
	//Robot::gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
}

// Make this return true when this Command no longer needs to run execute()
bool GetGameData::IsFinished() {
	//return Robot::gameData.length() > 0;
}

// Called once after isFinished returns true
void GetGameData::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetGameData::Interrupted() {

}
