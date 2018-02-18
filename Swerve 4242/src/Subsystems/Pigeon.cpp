#include <Subsystems/Pigeon.h>
#include "../RobotMap.h"

#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"

Pigeon::Pigeon() : Subsystem("Pigeon") {
	pidgeon = new PigeonIMU(RobotMap::driveTrainRearRightDrive);

	current_Accel = 0;
	previous_Accel = 0;
	DriveJerk = 0;
}

void Pigeon::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Pigeon::CalibratePigeon(){
	pidgeon->EnterCalibrationMode(
			ctre::phoenix::sensors::PigeonIMU::Accelerometer, 1000);
}

double Pigeon::GetYaw() {
	// Get yaw, which is the first value in data array
	double data[3] = {};
	pidgeon->GetYawPitchRoll(data);
	int angle = data[2];

	int turnratio = angle/360;
	double angle_error = (angle - (360 * turnratio));
	return  angle_error;
}

double Pigeon::GetAccelAngle(){
//	double data[3] = {};
//	current_Accel = pidgeon->GetAccelerometerAngles(data);
//	DriveJerk = current_Accel - previous_Accel;
//	previous_Accel = current_Accel - previous_Accel;
//
//	return accelangle;
	return 0;
}

void Pigeon::ResetYaw(){
	pidgeon->SetYaw(0.0, 0);
}
