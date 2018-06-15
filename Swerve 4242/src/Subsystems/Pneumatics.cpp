#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;

Pneumatics::Pneumatics() : Subsystem("Pneumatics") {
    compressor = new Compressor(4);

    clawPiston1 = new DoubleSolenoid(0, 1);
    clawPiston2 = new DoubleSolenoid(2, 3);

    pusherPiston = new frc::DoubleSolenoid(6, 7);
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
}
