#ifndef DrivePigeon_H
#define DrivePigeon_H

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

	PigeonIMU* pidgeon;

public:
	Pigeon();
	void CalibratePigeon();
	void InitDefaultCommand();
	double GetYaw();
	double GetAccelAngle();
	void ResetYaw();
};

#endif  // DrivePigeon_H