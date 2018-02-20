#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;

Pneumatics::Pneumatics() : Subsystem("Pneumatics") {
	compressor = new Compressor(1);
	clawPiston1 = new DoubleSolenoid(6,7);
	clawPiston2 = new DoubleSolenoid(4,5);
	rampPiston = new DoubleSolenoid(2,3);
	holdRampPiston = new DoubleSolenoid(0,1);
}

void Pneumatics::InitDefaultCommand() {
	//Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Pneumatics::Start() {
	#ifdef REAL
		compressor->Start();
	#endif
}

bool Pneumatics::IsPressurized() {
	return true;
//	#ifdef REAL
//		return MAX_PRESSURE <= pressureSensor0>GetVoltage();
//	#else
//		return true;
//	#endif
}

void Pneumatics::WritePressure() {
	//SmartDashboard::PutNumber("Pressure", pressureSensor->GetVoltage());
}

void Pneumatics::ExtendPiston() {
	clawPiston1->Set(frc::DoubleSolenoid::kForward);
	clawPiston2->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::RetractPiston() {
	clawPiston1->Set(frc::DoubleSolenoid::kReverse);
	clawPiston2->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::StopPiston() {
	clawPiston1->Set(frc::DoubleSolenoid::kOff);
	clawPiston2->Set(frc::DoubleSolenoid::kOff);
}

void Pneumatics::PushRampEndUp() {
	// added to push end of ramp up
	rampPiston->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::RampHold() {
	holdRampPiston->Set(frc::DoubleSolenoid::kForward);
}

