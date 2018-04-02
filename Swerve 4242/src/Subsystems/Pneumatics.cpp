#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;

Pneumatics::Pneumatics() : Subsystem("Pneumatics") {
    compressor = new Compressor(0);

    clawPiston1 = new frc::Solenoid(2);
    clawPiston2 = new frc::Solenoid(5);

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
    clawPiston1->Set(true);
    clawPiston2->Set(true);
}

void Pneumatics::CloseClaw() {
    clawPiston1->Set(false);
    clawPiston2->Set(false);
}

void Pneumatics::PushPiston() {
    pusherPiston->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::RetractPiston() {
    pusherPiston->Set(frc::DoubleSolenoid::kForward);
}