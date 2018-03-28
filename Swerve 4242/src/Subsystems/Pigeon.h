#ifndef Pigeon_H
#define Pigeon_H

#include <math.h>

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"
#include "PIDSource.h"

class Pigeon : public Subsystem {
private:
	PigeonIMU* pigeon;

	double const COLLISION_THRESHOLD_DELTA_G = 0.3;
	double const TILTED_THRESHOLD_DEGREES = 10;

	double previous_accel_X = 0;
	double previous_accel_Y = 0;

	double yaw = 0;
	double pitch = 0;
	double roll = 0;

public:
	Pigeon();
	void CalibratePigeon();
	void InitDefaultCommand();
	void Update();
	bool AmTilted();
	double GetYaw();
	bool WasCollision();
	void ResetYaw();
};

#endif  // Pigeon_H
