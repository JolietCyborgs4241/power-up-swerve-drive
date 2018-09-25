#include "Elevator.h"
#include "../RobotMap.h"
<<<<<<< HEAD
#include "ctre/Phoenix.h"
using namespace frc;

=======
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
#include "Robot.h"
#include "ctre/Phoenix.h"

Elevator::Elevator() : Subsystem("Elevator") {
<<<<<<< HEAD
	elevatorMotor = RobotMap::elevatorMotor;
	ElevatorPosNum = 1; //Robot::cycleElevator->ElevatorCycleNum;
	// Using Position Closed Loop Control from:
	// https://github.com/CrossTheRoadElec/Phoenix-Examples-Languages/blob/master/C%2B%2B/PositionClosedLoop/src/Robot.cpp

//	/* lets grab the 360 degree position of the MagEncoder's absolute position */
//	int absolutePosition = elevatorMotor->GetSelectedSensorPosition(0) & 0xFFF; /* mask out the bottom12 bits, we don't care about the wrap arounds */
//	/* use the low level API to set the quad encoder signal */
//
//	elevatorMotor->SetSelectedSensorPosition(
//			absolutePosition,
//			kPIDLoopIdx,
//			kTimeoutMs);
//
//	/* choose the sensor and sensor direction */
//	elevatorMotor->ConfigSelectedFeedbackSensor(
//			FeedbackDevice::CTRE_MagEncoder_Relative,
//			kPIDLoopIdx,
//			kTimeoutMs);
//
//	elevatorMotor->SetStatusFramePeriod(
//			StatusFrame::Status_1_General_,
//			5,
//			kTimeoutMs); /* Talon will send new frame every 5ms */
//
//	elevatorMotor->SetSensorPhase(true);
//	/* set the peak and nominal outputs, 12V/1.0 means full */
//	elevatorMotor->ConfigNominalOutputForward(0, kTimeoutMs);
//	elevatorMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
//	elevatorMotor->ConfigPeakOutputForward(peakSpeed, kTimeoutMs);
//	elevatorMotor->ConfigPeakOutputReverse(peakSpeed, kTimeoutMs);
//
//	/* set closed loop gains in slot0 */
//	elevatorMotor->Config_kF(kPIDLoopIdx, kF, kTimeoutMs);
//	elevatorMotor->Config_kP(kPIDLoopIdx, kP, kTimeoutMs);
//	elevatorMotor->Config_kI(kPIDLoopIdx, kI, kTimeoutMs);
//	elevatorMotor->Config_kD(kPIDLoopIdx, kD, kTimeoutMs);
=======
    elevatorMotor = RobotMap::elevatorMotor;

    // Using Position Closed Loop Control from:
    // https://github.com/CrossTheRoadElec/Phoenix-Examples-Languages/blob/master/C%2B%2B/PositionClosedLoop/src/Robot.cpp

    // lets grab the 360 degree position of the MagEncoder's absolute position

    int absolutePosition = elevatorMotor->GetSelectedSensorPosition(0) &
                           0xFFF; // mask out the bottom12 bits, we don't care about the wrap arounds
    // use the low level API to set the quad encoder signal

    elevatorMotor->SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx, kTimeoutMs);

    // choose the sensor and sensor direction
    elevatorMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);

    elevatorMotor->SetStatusFramePeriod(StatusFrame::Status_1_General_, 5,
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
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
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

<<<<<<< HEAD
void Elevator::MoveElevator()  {
	double motorValue = -Robot::oi->getPS4Joy();

	if (RobotMap::elevatorUpperLimitSwitch->Get() && motorValue < 0.0) {
		motorValue = 0.0;
	} else if (RobotMap::elevatorBottomLimitSwitch->Get() && motorValue > 0.0) {
		motorValue = 0.0;
	}

	elevatorMotor->Set(-motorValue);
=======
// Control Elevator with basic set speed
void Elevator::MoveElevator() {
    double motorValue = -Robot::oi->getControlJoy();

    if (Robot::useUpperLimitSwitch && RobotMap::elevatorUpperLimitSwitch->Get() && motorValue > 0.0) {
        motorValue = 0.0;
    }

    // No bottom limit switch...
    // if (RobotMap::elevatorBottomLimitSwitch->Get() && motorValue < 0.0) {
    // motorValue = 0.0;
    //}

    elevatorMotor->Set(motorValue);
}

void Elevator::SetStartingPosition() {
    startingPosition = elevatorMotor->GetSelectedSensorPosition(0);
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

double Elevator::GetDistance() {
    return elevatorMotor->GetSelectedSensorPosition(0) - startingPosition;
}

double Elevator::GetPIDError() {
<<<<<<< HEAD
	return elevatorMotor->GetClosedLoopError(kPIDLoopIdx);
}
double Elevator::DropClaw() {
	return elevatorMotor->GetSelectedSensorPosition(10);
}
double Elevator::ElevatorPosDefault() {
	return elevatorMotor->GetSelectedSensorPosition(0);
}
double Elevator::ElevatorPos1() { //Vault Position
	return elevatorMotor->GetSelectedSensorPosition(10);
}
double Elevator::ElevatorPos2() { //Switch Position
	return elevatorMotor->GetSelectedSensorPosition(20);
}
double Elevator::ElevatorPos3() { //Scale Lower
	return elevatorMotor->GetSelectedSensorPosition(80);
}
double Elevator::ElevatorPos4() { //Scale Upper/Neutral
	return elevatorMotor->GetSelectedSensorPosition(100);
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


	 ElevatorPosNum = ElevatorPosNum++;
	if (ElevatorPosNum > 4) {
		ElevatorPosNum = 1;
	}
	return ElevatorPosNum;
}
int Elevator::ElevatorPosDecrement() {

	ElevatorPosNum = ElevatorPosNum--;
	if (ElevatorPosNum < 1) {
		ElevatorPosNum = 4;
	}
	return ElevatorPosNum;


=======
    return elevatorMotor->GetClosedLoopError(kPIDLoopIdx);
}

void Elevator::PosDefault() {
    elevatorMotor->Set(ControlMode::Position, POSITION_DEFAULT + startingPosition);
}
void Elevator::PosVault() {
    elevatorMotor->Set(ControlMode::Position, POSITION_VAULT + startingPosition);
}
void Elevator::PosSwitch() {
    elevatorMotor->Set(ControlMode::Position, POSITION_SWITCH + startingPosition);
}
void Elevator::PosScaleLow() {
    elevatorMotor->Set(ControlMode::Position, POSITION_SCALE_LOW + startingPosition);
}
void Elevator::PosScaleHigh() {
    elevatorMotor->Set(ControlMode::Position, POSITION_SCALE_HIGH + startingPosition);
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}
