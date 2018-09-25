#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;

Pneumatics::Pneumatics() : Subsystem("Pneumatics") {
<<<<<<< HEAD
	compressor = new Compressor(1);
	rampPiston = new DoubleSolenoid(3,4); //4,5      Not sure if these are the parameters for the main bot or not.

	SingleClaw1 = new Solenoid (7);
	SingleClaw2 = new Solenoid (6);


	//rampPiston = new DoubleSolenoid(4,5);
	//holdRampPiston1 = new DoubleSolenoid(6,7);
	//holdRampPiston2 = new DoubleSolenoid(8, 9);
=======
    compressor = new Compressor(0);

    clawPiston1 = new DoubleSolenoid(0, 1);
    clawPiston2 = new DoubleSolenoid(2, 3);

    pusherPiston = new frc::DoubleSolenoid(6, 7);
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

void Pneumatics::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void Pneumatics::Start() {
#ifdef REAL
    compressor->Start();
#endif
    CloseClaw();
    RetractPiston();
}

void Pneumatics::OpenClaw() {
<<<<<<< HEAD
	clawPiston1->Set(frc::DoubleSolenoid::kReverse);
	clawPiston2->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::CloseClaw() {
	clawPiston1->Set(frc::DoubleSolenoid::kForward);
	clawPiston2->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::StopClaw() {
	clawPiston1->Set(frc::DoubleSolenoid::kOff);
	clawPiston2->Set(frc::DoubleSolenoid::kOff);
}

void Pneumatics::RaiseRamp() {
	// added to push end of ramp up
	//rampPiston->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::LowerRamp() {
	// added to push end of ramp up
	//rampPiston->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::DeployRamp() {
	//holdRampPiston1->Set(frc::DoubleSolenoid::kReverse);
	//holdRampPiston2->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::ActuateSingleSolenoid() {
	SingleClaw1->Set(true);
	SingleClaw2->Set(true);
}
void Pneumatics::TurnOffSingleSolenoid() {
	SingleClaw1->Set(false);
	SingleClaw2->Set(false);
}
void Pneumatics::HoldRamp() {


	//holdRampPiston1->Set(frc::DoubleSolenoid::kForward);
	//holdRampPiston2->Set(frc::DoubleSolenoid::kReverse);
=======
    clawPiston1->Set(frc::DoubleSolenoid::kForward);
    clawPiston2->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::CloseClaw() {
    clawPiston1->Set(frc::DoubleSolenoid::kReverse);
    clawPiston2->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::PushPiston() {
    pusherPiston->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::RetractPiston() {
    pusherPiston->Set(frc::DoubleSolenoid::kForward);
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}
