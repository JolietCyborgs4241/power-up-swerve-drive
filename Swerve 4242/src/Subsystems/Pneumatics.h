#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Pneumatics : public Subsystem {
private:
	Compressor* compressor;
	AnalogInput* pressureSensor;

	static constexpr double MAX_PRESSURE = 2.55;
	//VV For Intake VV
	DoubleSolenoid* clawPiston1;
	DoubleSolenoid* clawPiston2;
	//^^ For Intake ^^

	DoubleSolenoid* piston3;
	DoubleSolenoid* piston4;
	DoubleSolenoid* piston5;


public:
	Pneumatics();
	void InitDefaultCommand();

	void Start();

	bool IsPressurized();
	void WritePressure();

	//VV For Intake VV
	void ExtendPiston();
	void RetractPiston();
	void StopPiston();
	//^^ For Intake ^^

	//VV For Intake Auto VV
	void IntakeUp();
	void IntakeDown();
	//VV might not be needed, just there as a just in case it is needed
	void IntakeStop();
	//^^ For Intake Auto ^^

	void RampEndUp();
	void RampHold();

};

#endif  // Pneumatics_H
