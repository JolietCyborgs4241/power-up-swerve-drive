#ifndef IntakeDetection_H
#define IntakeDetection_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "Ultrasonic.h"

class IntakeDetection : public Subsystem {
private:

public:
	IntakeDetection();
	void InitDefaultCommand();

	double GetRangeInches();
	bool HasCube(int range);
	Ultrasonic* ultra;
};

#endif  // IntakeDetection_H
