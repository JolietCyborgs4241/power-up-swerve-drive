#include "MagEncoder.h"
#include "../RobotMap.h"

MagEncoder::MagEncoder() : Subsystem("MagEncoder") {
	enc = new Encoder (1, 0, false, Encoder::EncodingType::k2X);
	enc->SetMaxPeriod(.1);
	enc->SetMinRate(10);
	enc->SetDistancePerPulse(5);
	enc->SetReverseDirection(true);
	enc->SetSamplesToAverage(7);
}

void MagEncoder::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void MagEncoder::DriveDistance() {
	enc->GetDistance();
}
bool MagEncoder::AutoDriveTest() {
	return false;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
