#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <math.h>

// Code copied and modified from FRC 16's Macy's 2014 DriveTrain
// https://github.com/FRCTeam16/Macys2014/blob/master/Macys2014/Subsystems/DriveTrain.cpp

class DriveTrain : public Subsystem {
  private:
    static constexpr double pi = 3.14159;
    void SetSteerSetpoint(float FLSet, float FRSet, float RLSet, float RRSet);
    void SetDriveSpeed(float FLSpeed, float FRSpeed, float RLSpeed, float RRSpeed);

    // DriveDirection
    bool driveFront = true;

    // Precision Control
    double PRECISION_ADJUST = 0.35;

    // Steering Variables
    double radian = 0.0; // input steering angle in radians
    double A = 0.0;      // A is the ratio of X to turn harder
    double W = 0.0; // W is the distance form the mid-point of one back wheel to the mid-point of the other back wheel
    double X = 0.0; // X is the distance form the mid-point of the back wheels to the mid-point of the front wheels
    double Y = 0.0; // Y is the distance from the mid-point of one front wheel to the mid-point of the other font wheel

    double FL = 0.0; // FL, distance from Front Left Wheel to the center of rotation
    double FR = 0.0; // FR, distance from Front Right Wheel to the center of rotation
    double RL = 0.0; // RL, distance from Rear Left Wheel to the center of rotation
    double RR = 0.0; // RR, distance from Rear Right Wheel to the center of rotation

    double FRRatio = 0.0; // Ratio of Speed of Front Right wheel
    double FLRatio = 0.0; // Ratio of Speed of Front Left wheel
    double RRRatio = 0.0; // Ratio of Speed of Rear Right wheel
    double RLRatio = 0.0; // Ratio of Speed of Rear Left wheel

    double FLOffset = 0.0;
    double FROffset = 0.0;
    double RLOffset = 0.0;
    double RROffset = 0.0;

    // Crab Variables
    double AP = 0.0;
    double BP = 0.0;
    double CP = 0.0;
    double DP = 0.0;
    double radius = 0.0; // distance from center to each wheel

    int FLInv = 0;
    int FRInv = 0;
    int RLInv = 0;
    int RRInv = 0;

    double CorrectSteerSetpoint(double setpoint);

  public:
    WPI_TalonSRX* frontLeftDrive;
    WPI_TalonSRX* frontRightDrive;
    WPI_TalonSRX* rearLeftDrive;
    WPI_TalonSRX* rearRightDrive;
    AnalogInput* frontLeftPos;
    WPI_TalonSRX* frontLeftSteer;
    PIDController* frontLeft;
    AnalogInput* frontRightPos;
    WPI_TalonSRX* frontRightSteer;
    PIDController* frontRight;
    AnalogInput* rearLeftPos;
    WPI_TalonSRX* rearLeftSteer;
    PIDController* rearLeft;
    AnalogInput* rearRightPos;
    WPI_TalonSRX* rearRightSteer;
    PIDController* rearRight;

    DriveTrain();
    void InitDefaultCommand();
    void TwistRight();
    void TwistLeft();
    void SetWheelbase(float w, float x, float y);
    void SetOffsets(double FLOff, double FROff, double RLOff, double RROff);
    void Crab(float y, float x, float twist, bool useGyro);
    void SwerveArcade(float y, float x, float twist, bool useGyro);
    void Lock();
    void Test();
    void ToggleFrontBack();
    void DriveForward(double speed, double twist);
    void DriveReverse(double speed, double twist);
    void DriveLeft(double speed, double twist);
    void DriveRight(double speed, double twist);
    void DriveAngle(double speed, double angle);
    void Stop();
    void TogglePrecisionDrive();
    void DisablePIDs();
    void EnablePIDs();

    double driveAdjust = 1.0;
    bool precisionDrive = false;
};