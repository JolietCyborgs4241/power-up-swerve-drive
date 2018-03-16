#include "Elevator.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "Robot.h"

using namespace frc;

Elevator::Elevator() : Subsystem("Elevator") {
	elevatorMotor = RobotMap::elevatorMotor;

	// Using Position Closed Loop Control from:
	// https://github.com/CrossTheRoadElec/Phoenix-Examples-Languages/blob/master/C%2B%2B/PositionClosedLoop/src/Robot.cpp

	// lets grab the 360 degree position of the MagEncoder's absolute position
	int absolutePosition = elevatorMotor->GetSelectedSensorPosition(0) & 0xFFF; // mask out the bottom12 bits, we don't care about the wrap arounds
	// use the low level API to set the quad encoder signal

	elevatorMotor->SetSelectedSensorPosition(
			absolutePosition,
			kPIDLoopIdx,
			kTimeoutMs);

	// choose the sensor and sensor direction
	elevatorMotor->ConfigSelectedFeedbackSensor(
			FeedbackDevice::CTRE_MagEncoder_Relative,
			kPIDLoopIdx,
			kTimeoutMs);

	elevatorMotor->SetStatusFramePeriod(
			StatusFrame::Status_1_General_,
			5,
			kTimeoutMs); // Talon will send new frame every 5ms


	elevatorMotor->SetSensorPhase(true);
	elevatorMotor->SetInverted(true);
	// set the peak and nominal outputs, 12V/1.0 means full
	elevatorMotor->ConfigNominalOutputForward(0, kTimeoutMs);
	elevatorMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
	elevatorMotor->ConfigPeakOutputForward(PEAK_UP_SPEED, kTimeoutMs);
	elevatorMotor->ConfigPeakOutputReverse(PEAK_DOWN_SPEED, kTimeoutMs);

	// set closed loop gains in slot0
	elevatorMotor->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
	elevatorMotor->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	elevatorMotor->Config_kI(kPIDLoopIdx, kI, kTimeoutMs);
	elevatorMotor->Config_kD(kPIDLoopIdx, kD, kTimeoutMs);

	//startingPosition = elevatorMotor->GetSelectedSensorPosition(0);
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Control Elevaator with Position Control
void Elevator::PositionUpdate() {
	/*double joystickValue = -Robot::oi->getControlJoy();
	double elePos = GetDistance();

	// Stop when it hits limit switch
	if (RobotMap::elevatorUpperLimitSwitch->Get() && joystickValue > 0.0) {
		joystickValue = 0;
	}

	elePos += joystickValue * 175;

	// Soft upper limit
	if (elePos > 31000) {
		elePos = 31000;
	}

	// Soft bottom limit
	if (elePos < 0) {
		elePos = 0;
	}

	elevatorMotor->Set(ControlMode::Position, elePos);*/
}

// Control Elevator with basic set speed
void Elevator::MoveElevator()  {
	double motorValue = -Robot::oi->getControlJoy();

//	if (RobotMap::elevatorUpperLimitSwitch->Get() && motorValue > 0.0) {
//		motorValue = 0.0;
//	}
	//else if (RobotMap::elevatorBottomLimitSwitch->Get() && motorValue < 0.0) {
//		motorValue = 0.0;
//	}

	if (fabs(motorValue) > 0.01) {
		elevatorMotor->Set(motorValue);
	}
}

double Elevator::GetDistance() {
	//return 0;
	return elevatorMotor->GetSelectedSensorPosition(0);
}

double Elevator::GetPIDError() {
	return elevatorMotor->GetClosedLoopError(kPIDLoopIdx);
}

void Elevator::PosDefault() {
	elevatorMotor->Set(ControlMode::Position, POSITION_DEFAULT);
}
void Elevator::PosVault() {
	elevatorMotor->Set(ControlMode::Position, POSITION_VAULT);
}
void Elevator::PosSwitch() {
	elevatorMotor->Set(ControlMode::Position, POSITION_SWITCH);
}
void Elevator::PosScaleLow() {
	elevatorMotor->Set(ControlMode::Position, POSITION_SCALE_LOW);
}
void Elevator::PosScaleHigh() {
	elevatorMotor->Set(ControlMode::Position, POSITION_SCALE_HIGH);
}
