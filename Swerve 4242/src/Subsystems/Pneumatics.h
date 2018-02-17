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
	//VV For Extending Piston VV
	DoubleSolenoid* piston1;
	DoubleSolenoid* piston2;
	//^^ For Extending Piston ^^

	DoubleSolenoid* piston3;
	DoubleSolenoid* piston4;
	DoubleSolenoid* piston5;


public:
	Pneumatics();
	void InitDefaultCommand();

	void Start();

	bool IsPressurized();
	void WritePressure();

	//VV For Extending Piston VV
	void ExtendPiston();
	void RetractPiston();
	void StopPiston();
	//^^ For Extending Piston ^^

	//VV For Intake Piston VV
	void IntakeUp();
	void IntakeDown();
	//VV might not be needed, just there as a just in case it is needed
	void IntakeStop();
	//^^ For Intake Piston ^^

	void RampEndUp();
	void RampHold();

};

#endif  // Pneumatics_H
