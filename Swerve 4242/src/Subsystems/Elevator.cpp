#include "Elevator.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "Robot.h"


using namespace frc;

Elevator::Elevator() : Subsystem("Elevator") {
	elevatorMotor = RobotMap::elevatorMotor;
	ElevatorPosNum = 1; //Robot::cycleElevator->ElevatorCycleNum;
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

	elevatorMotor->SetInverted(true);
	elevatorMotor->SetSensorPhase(true);
	/* set the peak and nominal outputs, 12V/1.0 means full */
	elevatorMotor->ConfigNominalOutputForward(0, kTimeoutMs);
	elevatorMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
	elevatorMotor->ConfigPeakOutputForward(peakSpeed, kTimeoutMs);
	elevatorMotor->ConfigPeakOutputReverse(-0.4, kTimeoutMs);

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
//	double leftYstick = Robot::oi->getPS4Joy();
//	double targetPositionRotations = leftYstick * 10.0 * 4096; /* 10 Rotations in either direction */
//	elevatorMotor->Set(ControlMode::Position, 0); /* 10 rotations in either direction */
}

void Elevator::MoveElevator()  {
	double motorValue = -Robot::oi->getControlJoy();

	if (RobotMap::elevatorUpperLimitSwitch->Get() && motorValue > 0.0) {
		motorValue = 0.0;
	}
	//else if (RobotMap::elevatorBottomLimitSwitch->Get() && motorValue < 0.0) {
//		motorValue = 0.0;
//	}

	if (fabs(motorValue) > 0.01) {
		elevatorMotor->Set(-motorValue);
	}
}

double Elevator::GetDistance() {
	return elevatorMotor->GetSelectedSensorPosition(0);
}

double Elevator::GetPIDError() {
	return elevatorMotor->GetClosedLoopError(kPIDLoopIdx);
}
void Elevator::DropClaw() {
	//return elevatorMotor->GetSelectedSensorPosition(10);
}
void Elevator::ElevatorPosDefault() {
	//return elevatorMotor->GetSelectedSensorPosition(0);
	elevatorMotor->Set(ControlMode::Position, 200);
}
void Elevator::ElevatorVault() {
	elevatorMotor->Set(ControlMode::Position, 3000);
}
void Elevator::ElevatorSwitch() {
	elevatorMotor->Set(ControlMode::Position, 8000);
	//return elevatorMotor->GetSelectedSensorPosition(20);
}
void Elevator::ElevatorScaleLow() {
	elevatorMotor->Set(ControlMode::Position, 14000);
	//return elevatorMotor->GetSelectedSensorPosition(80);
}
void Elevator::ElevatorScaleHigh() {
	elevatorMotor->Set(ControlMode::Position, 26000);
	//return elevatorMotor->GetSelectedSensorPosition(100);
}
int Elevator::ElevatorPosIncrement() {
	/* if (ElevatorPosNum == 1)
	{
		ElevatorPosNum = 2;
	}
	else if (ElevatorPosNum == 2)
	{
		ElevatorPosNum = 3;
	}
	else if (ElevatorPosNum == 3)
	{
		ElevatorPosNum = 4;
	}
	else if (ElevatorPosNum == 4)
	{
		ElevatorPosNum = 1;
	}
	else
	{
		ElevatorPosNum = 1;
	} */


	 Robot::elevatorPosNum++;
	if (Robot::elevatorPosNum > 4) {
		Robot::elevatorPosNum = 4;
	}
	return Robot::elevatorPosNum;
}
int Elevator::ElevatorPosDecrement() {

	Robot::elevatorPosNum--;
	if (Robot::elevatorPosNum < 0) {
		Robot::elevatorPosNum = 0;
	}
	return Robot::elevatorPosNum;


}
