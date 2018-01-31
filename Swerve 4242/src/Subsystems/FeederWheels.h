#ifndef FeederWheels_H
#define FeederWheels_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"

class FeederWheels : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX* FeederWheel1;
	WPI_TalonSRX* FeederWheel2;

public:
	FeederWheels();
	void InitDefaultCommand();
};

#endif  // FeederWheels_H
