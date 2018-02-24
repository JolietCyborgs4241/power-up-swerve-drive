#ifndef Pigeon_H
#define Pigeon_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"
#include "PIDSource.h"

class Pigeon : public Subsystem {
private:
	double current_Accel;
	double previous_Accel;
	double DriveJerk;

public:
	Pigeon();
	void CalibratePigeon();
	void InitDefaultCommand();
	double GetYaw();
	double GetAccelAngle();
	void ResetYaw();

	PigeonIMU* pigeon;
};

#endif  // Pigeon_H
