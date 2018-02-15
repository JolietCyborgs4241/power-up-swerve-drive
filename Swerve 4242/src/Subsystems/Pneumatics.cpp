#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;
Pneumatics::Pneumatics() :
		Subsystem("Pneumatics")

{
		pressureSensor = new AnalogInput(0);
		compressor = new Compressor(1);
		piston1 = new DoubleSolenoid(0,1);
		piston2 = new DoubleSolenoid(4,5);
		LiveWindow::GetInstance()->AddSensor("Pneumatics", "Pressure Sensor", pressureSensor);
}

void Pneumatics::InitDefaultCommand() {

	 //Set the default command for a subsystem here.
	 //SetDefaultCommand(new MySpecialCommand());
}
void Pneumatics::Start()
{
	#ifdef REAL
		compressor->Start();
	#endif
}
bool Pneumatics::IsPressurized() {
	#ifdef REAL
		return MAX_PRESSURE <= pressureSensor0>GetVoltage();
	#else
		return true;
	#endif
}

void Pneumatics::WritePressure() {
	SmartDashboard::PutNumber("Pressure", pressureSensor->GetVoltage());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

//VV Everything down is for extending/retracting pistion VV
void Pneumatics::ExtendPiston()
{
	piston1->Set(frc::DoubleSolenoid::kForward);
	piston2->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::RetractPiston()
{
	piston1->Set(frc::DoubleSolenoid::kReverse);
	piston2->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::StopPiston()
{
	piston1->Set(frc::DoubleSolenoid::kOff);
	piston2->Set(frc::DoubleSolenoid::kOff);
}
