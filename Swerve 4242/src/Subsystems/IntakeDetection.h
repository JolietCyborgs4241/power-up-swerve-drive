#ifndef IntakeDetection_H
#define IntakeDetection_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "Ultrasonic.h"


class IntakeDetection : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Ultrasonic* ultra;

public:
	IntakeDetection();
	void InitDefaultCommand();

	double GetRangeInches();
	bool HasCube();
};

#endif  // IntakeDetection_H
