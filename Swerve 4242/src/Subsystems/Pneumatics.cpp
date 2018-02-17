#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;


Pneumatics::Pneumatics() : Subsystem("Pneumatics") {

		pressureSensor = new AnalogInput(0);
		compressor = new Compressor(1);
		piston1 = new DoubleSolenoid(0,1);
		piston2 = new DoubleSolenoid(4,5);
		piston3 = new DoubleSolenoid(2,3);//2 and 3 might not be the correct numbers, they are simply there so that there is some sort of number there
		LiveWindow::GetInstance()->AddSensor("Pneumatics", "Pressure Sensor", pressureSensor);

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
	#ifdef REAL
		return MAX_PRESSURE <= pressureSensor0>GetVoltage();
	#else
		return true;
	#endif
}

void Pneumatics::WritePressure() {
	SmartDashboard::PutNumber("Pressure", pressureSensor->GetVoltage());
}

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

void Pneumatics::IntakeRelease()//this is set to reverse because the default position is up and this will open it, change it to forward if reverse does not do the correct thing
{
	piston3->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::IntakeClose()//this is set to forward because the default position is up and this will close it, change it to reverse if forward does not do the correct thing
{
	piston3->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::IntakeStop()//this might not be needed, it is there simply in case it is needed
{
	piston3->Set(frc::DoubleSolenoid::kOff);
}
