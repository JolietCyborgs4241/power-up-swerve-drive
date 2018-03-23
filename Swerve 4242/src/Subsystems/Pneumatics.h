#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Pneumatics : public Subsystem {
private:
	static constexpr double MAX_PRESSURE = 2.55;

	Compressor* compressor;

	// Claw Pistons (should be actuated together)
	DoubleSolenoid* clawPiston1;
	DoubleSolenoid* clawPiston2;

	// Piston to raise ramp
	DoubleSolenoid* rampPiston;

	// Pistons to hold the ramp
	Solenoid* holdRampPiston1;
	Solenoid* holdRampPiston2;

public:
	Pneumatics();
	void InitDefaultCommand();

	void Start();

	void OpenClaw();
	void CloseClaw();
	void StopClaw();
};

#endif  // Pneumatics_H
