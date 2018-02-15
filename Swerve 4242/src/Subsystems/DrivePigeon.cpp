#include "DrivePigeon.h"
#include "../RobotMap.h"
#include <cmath>
#include "SPI.h"

#include "ctre/phoenix/Sensors/PigeonIMU.h"
#include "ctre/Phoenix.h"

DrivePigeon::DrivePigeon() : Subsystem("DrivePigeon") {
	pidgey = new PigeonIMU(RobotMap::driveTrainRearRightDrive);
	data = new double [3];
	acceldata = new double [3];
	current_Accel = 0;
	previous_Accel = 0;
	DriveJerk = 0;
	angle_error = 0;
	angle = 0;
	turnratio=0;
}
void DrivePigeon::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DrivePigeon::CalibratePigeon(){

}

double DrivePigeon::GetYaw() {
	double dataD[3] = {};
	pidgey->GetYawPitchRoll(dataD);
	angle = dataD[0];
	turnratio = angle/360;
	angle_error = (angle - (360 * turnratio));
	return  fmod(angle, 360);


}
void DrivePigeon::GetAccelAngle(){
	double accData[3] = {};
	current_Accel = pidgey->GetAccelerometerAngles(accData);
	DriveJerk = current_Accel - previous_Accel;
	previous_Accel = current_Accel - previous_Accel;


//	return accelangle;

}

void DrivePigeon::ResetYaw(){
	pidgey->SetYaw(0.0, 0);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
