#include <Subsystems/Pigeon.h>
#include "../RobotMap.h"

#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"

Pigeon::Pigeon() : Subsystem("Pigeon") {
	pigeon = new PigeonIMU(new WPI_TalonSRX(1));

	current_Accel = 0;
	previous_Accel = 0;
	DriveJerk = 0;
}

void Pigeon::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Pigeon::CalibratePigeon(){
	pigeon->EnterCalibrationMode(
			ctre::phoenix::sensors::PigeonIMU::Temperature, 0);
}

double Pigeon::GetYaw() {
	// Get yaw, which is the first value in data array
	double data[3] = {};
	pigeon->GetYawPitchRoll(data);
	double angle = data[0];
	return angle;

/*
	int turnratio = angle/360;
	double angle_error = (angle - (360 * turnratio));
	return  angle_error;*/
}

double Pigeon::GetAccelAngle(){
//	double data[3] = {};
//	current_Accel = pigeon->GetAccelerometerAngles(data);
//	DriveJerk = current_Accel - previous_Accel;
//	previous_Accel = current_Accel - previous_Accel;
//
//	return accelangle;
	return 0;
}

void Pigeon::ResetYaw(){
	pigeon->SetYaw(0.0, 0);
}

