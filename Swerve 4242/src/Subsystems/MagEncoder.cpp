#include "MagEncoder.h"
#include "../RobotMap.h"
#include "Encoder.h"

using namespace frc;

MagEncoder::MagEncoder() : Subsystem("MagEncoder") {
	enc = new Encoder(1, 0, false, Encoder::EncodingType::k2X);
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
double MagEncoder::GetDistance() {
	return enc->GetDistance();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
