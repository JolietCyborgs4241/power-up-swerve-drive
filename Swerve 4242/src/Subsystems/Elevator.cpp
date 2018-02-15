#include "Elevator.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "Robot.h"
using namespace frc;

Elevator::Elevator() : Subsystem("Elevator") {
	elevatorMotor = RobotMap::elevatorMotor;

	// Using Position Closed Loop Control from:
	// https://github.com/CrossTheRoadElec/Phoenix-Examples-Languages/blob/master/C%2B%2B/PositionClosedLoop/src/Robot.cpp

	/* lets grab the 360 degree position of the MagEncoder's absolute position */
	int absolutePosition = elevatorMotor->GetSelectedSensorPosition(0) & 0xFFF; /* mask out the bottom12 bits, we don't care about the wrap arounds */
	/* use the low level API to set the quad encoder signal */

	elevatorMotor->SetSelectedSensorPosition(
			absolutePosition,
			kPIDLoopIdx,
			kTimeoutMs);

	/* choose the sensor and sensor direction */
	elevatorMotor->ConfigSelectedFeedbackSensor(
			FeedbackDevice::CTRE_MagEncoder_Relative,
			kPIDLoopIdx,
			kTimeoutMs);

	elevatorMotor->SetStatusFramePeriod(
			StatusFrame::Status_1_General_,
			5,
			kTimeoutMs); /* Talon will send new frame every 5ms */

	elevatorMotor->SetSensorPhase(true);
	/* set the peak and nominal outputs, 12V/1.0 means full */
	elevatorMotor->ConfigNominalOutputForward(0, kTimeoutMs);
	elevatorMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
	elevatorMotor->ConfigPeakOutputForward(peakSpeed, kTimeoutMs);
	elevatorMotor->ConfigPeakOutputReverse(peakSpeed, kTimeoutMs);

	/* set closed loop gains in slot0 */
	elevatorMotor->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
	elevatorMotor->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
	elevatorMotor->Config_kI(kPIDLoopIdx, kI, kTimeoutMs);
	elevatorMotor->Config_kD(kPIDLoopIdx, kD, kTimeoutMs);
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Elevator::PositionUpdate() {
	double leftYstick = Robot::oi->getPS4Joy();
	double targetPositionRotations = leftYstick * 10.0 * 4096; /* 10 Rotations in either direction */
	elevatorMotor->Set(ControlMode::Position, 0); /* 10 rotations in either direction */
}

double Elevator::GetDistance() {
	return elevatorMotor->GetSelectedSensorPosition(0);
}

double Elevator::GetPIDError() {
	return elevatorMotor->GetClosedLoopError(kPIDLoopIdx);
}
