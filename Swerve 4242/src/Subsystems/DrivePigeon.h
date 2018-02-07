#ifndef DrivePigeon_H
#define DrivePigeon_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"
#include "PIDSource.h"
class DrivePigeon : public Subsystem {
private:

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double* data;
	double* acceldata;
	double angle_error;
	int angle;
	double current_Accel;
	double previous_Accel;
	double DriveJerk;
	int turnratio;


public:
	DrivePigeon();
	void CalibratePigeon();
	void InitDefaultCommand();
	double GetYaw();
	void GetAccelAngle();
	void ResetYaw();
	PigeonIMU* pidgey;


};

#endif  // DrivePigeon_H
