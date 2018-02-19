#include "Pneumatics.h"
#include "Robot.h"
using namespace frc;


Pneumatics::Pneumatics() : Subsystem("Pneumatics") {

		//pressureSensor = new AnalogInput(0);
	/*
		compressor = new Compressor(1);
		clawPiston1 = new DoubleSolenoid(0,1);
		clawPiston2 = new DoubleSolenoid(4,5);
		actuatePiston = new DoubleSolenoid(2,3);
		rampPiston = new DoubleSolenoid(2,3);
		holdRampPiston = new DoubleSolenoid(2,3);
		LiveWindow::GetInstance()->AddSensor("Pneumatics", "Pressure Sensor", pressureSensor);
		*/

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

//VV For extending/retracting piston VV
void Pneumatics::ExtendPiston()
{
//	clawPiston1->Set(frc::DoubleSolenoid::kForward);
	//clawPiston2->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::RetractPiston()
{
	//clawPiston1->Set(frc::DoubleSolenoid::kReverse);
	//clawPiston2->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::StopPiston()
{
//	clawPiston1->Set(frc::DoubleSolenoid::kOff);
//	clawPiston2->Set(frc::DoubleSolenoid::kOff);
}
//^^ For extending/retracting piston ^^

void Pneumatics::IntakeUp()//this is set to reverse because the default position is up and this will open it, change it to forward if reverse does not do the correct thing
{
	//actuatePiston->Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::IntakeDown()//this is set to forward because the default position is up and this will close it, change it to reverse if forward does not do the correct thing
{
	//actuatePiston->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::IntakeStop()//this might not be needed, it is there simply in case it is needed
{
	//actuatePiston->Set(frc::DoubleSolenoid::kOff);
}

void Pneumatics::PushRampEndUp()//added to push end of ramp up
{
	//rampPiston->Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::RampHold()
{
	//holdRampPiston->Set(frc::DoubleSolenoid::kForward);
}

