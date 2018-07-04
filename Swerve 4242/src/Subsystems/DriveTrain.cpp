#include "DriveTrain.h"
#include "Math.h"
#include "Robot.h"
#include "Robotmap.h"
#include "ctre/Phoenix.h"
#include <Subsystems/Pigeon.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
    frontLeftDrive = RobotMap::driveTrainFrontLeftDrive;
    frontRightDrive = RobotMap::driveTrainFrontRightDrive;
    rearLeftDrive = RobotMap::driveTrainRearLeftDrive;
    rearRightDrive = RobotMap::driveTrainRearRightDrive;
    frontLeftPos = RobotMap::driveTrainFrontLeftPos;
    frontLeftSteer = RobotMap::driveTrainFrontLeftSteer;
    frontLeft = RobotMap::driveTrainFrontLeft;
    frontRightPos = RobotMap::driveTrainFrontRightPos;
    frontRightSteer = RobotMap::driveTrainFrontRightSteer;
    frontRight = RobotMap::driveTrainFrontRight;
    rearLeftPos = RobotMap::driveTrainRearLeftPos;
    rearLeftSteer = RobotMap::driveTrainRearLeftSteer;
    rearLeft = RobotMap::driveTrainRearLeft;
    rearRightPos = RobotMap::driveTrainRearRightPos;
    rearRightSteer = RobotMap::driveTrainRearRightSteer;
    rearRight = RobotMap::driveTrainRearRight;

    FLInv = 1;
    FRInv = 1;
    RRInv = 1;
    RLInv = 1;
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::SetWheelbase(float w, float x, float y) {
    W = w;
    X = x;
    Y = y;
}
void DriveTrain::SetOffsets(double FLOff, double FROff, double RLOff, double RROff) {
    FLOffset = FLOff;
    FROffset = FROff;
    RLOffset = RLOff;
    RROffset = RROff;
}
void DriveTrain::ToggleFrontBack() {
    driveFront = !driveFront;
}

void DriveTrain::Crab(float y, float x, float twist, bool useGyro) {
    float FWD = y * driveAdjust;
    float STR = x * driveAdjust;

    if (useGyro) {
        double robotangle = Robot::pigeon->GetYaw() * M_PI / 180;
        FWD = +y * sin(robotangle) + x * cos(robotangle);
        STR = -y * cos(robotangle) + x * sin(robotangle);
    }

    radius = sqrt(pow(Y, 2) + pow(X, 2));

    AP = STR + twist * X / radius;
    BP = STR - twist * X / radius;
    CP = FWD + twist * Y / radius;
    DP = FWD - twist * Y / radius;

    float FLSetPoint = 0;
    float FRSetPoint = 0;
    float RLSetPoint = 0;
    float RRSetPoint = 0;

    if (DP != 0 || BP != 0)
        FLSetPoint = (2.5 - 2.5 / pi * atan2(BP, DP));
    if (BP != 0 || CP != 0)
        FRSetPoint = (2.5 - 2.5 / pi * atan2(BP, CP));
    if (AP != 0 || DP != 0)
        RLSetPoint = (2.5 - 2.5 / pi * atan2(AP, DP));
    if (AP != 0 || CP != 0)
        RRSetPoint = (2.5 - 2.5 / pi * atan2(AP, CP));

    SetSteerSetpoint(FLSetPoint, FRSetPoint, RLSetPoint, RRSetPoint);
    FL = sqrt(pow(BP, 2) + pow(DP, 2));
    FR = sqrt(pow(BP, 2) + pow(CP, 2));
    RL = sqrt(pow(AP, 2) + pow(DP, 2));
    RR = sqrt(pow(AP, 2) + pow(CP, 2));

    // Solve for fastest wheel speed
    double speedarray[] = {fabs(FL), fabs(FR), fabs(RL), fabs(RR)};

    int length = 4;
    double maxspeed = speedarray[0];
    for (int i = 1; i < length; i++) {
        if (speedarray[i] > maxspeed) {
            maxspeed = speedarray[i];
        }
    }

    // Set ratios based on maximum wheel speed
    if (maxspeed > 1 || maxspeed < -1) {
        FLRatio = FL / maxspeed;
        FRRatio = FR / maxspeed;
        RLRatio = RL / maxspeed;
        RRRatio = RR / maxspeed;
    } else {
        FLRatio = FL;
        FRRatio = FR;
        RLRatio = RL;
        RRRatio = RR;
    }

    // Set drive speeds
    SetDriveSpeed(FLRatio, FRRatio, RLRatio, RRRatio);
}

void DriveTrain::SwerveArcade(float y, float x, float twist, bool useGyro) {
    float FWD = y * driveAdjust;
    float STR = x * driveAdjust;

    if (useGyro) {
        double robotangle = Robot::pigeon->GetYaw() * M_PI / 180;
        FWD = +y * sin(robotangle) + x * cos(robotangle);
        STR = -y * cos(robotangle) + x * sin(robotangle);
    }

    AP = STR;
    BP = STR;
    CP = FWD;
    DP = FWD;

    float FLSetPoint = 0;
    float FRSetPoint = 0;
    float RLSetPoint = 0;
    float RRSetPoint = 0;

    if (DP != 0 || BP != 0) {
        FLSetPoint = (2.5 - 2.5 / pi * atan2(BP, DP));
    }

    if (BP != 0 || CP != 0) {
        FRSetPoint = (2.5 - 2.5 / pi * atan2(BP, CP));
    }

    if (AP != 0 || DP != 0) {
        RLSetPoint = (2.5 - 2.5 / pi * atan2(AP, DP));
    }

    if (AP != 0 || CP != 0) {
        RRSetPoint = (2.5 - 2.5 / pi * atan2(AP, CP));
    }

    SetSteerSetpoint(FLSetPoint, FRSetPoint, RLSetPoint, RRSetPoint);
    FL = sqrt(pow(BP, 2) + pow(DP, 2));
    FR = sqrt(pow(BP, 2) + pow(CP, 2));
    RL = sqrt(pow(AP, 2) + pow(DP, 2));
    RR = sqrt(pow(AP, 2) + pow(CP, 2));

    // add in twist like arcade drive
    FL -= twist * 0.5;
    RL -= twist * 0.5;

    FR += twist * 0.5;
    RR += twist * 0.5;

    // Solve for fastest wheel speed
    double speedarray[] = {fabs(FL), fabs(FR), fabs(RL), fabs(RR)};

    int length = 4;
    double maxspeed = speedarray[0];
    for (int i = 1; i < length; i++) {
        if (speedarray[i] > maxspeed) {
            maxspeed = speedarray[i];
        }
    }

    // Set ratios based on maximum wheel speed
    if (maxspeed > 1 || maxspeed < -1) {
        FLRatio = FL / maxspeed;
        FRRatio = FR / maxspeed;
        RLRatio = RL / maxspeed;
        RRRatio = RR / maxspeed;
    } else {
        FLRatio = FL;
        FRRatio = FR;
        RLRatio = RL;
        RRRatio = RR;
    }

    // Set drive speeds
    SetDriveSpeed(FLRatio, FRRatio, RLRatio, RRRatio);
}

double DriveTrain::CorrectSteerSetpoint(double setpoint) {
    // Used to correct steering setpoints to within the 0 to 5 V scale
    if (setpoint < 0) {
        return setpoint + 5;
    } else if (setpoint > 5) {
        return setpoint - 5;
    } else if (setpoint == 5) {
        return 0;
    } else {
        return setpoint;
    }
}

void DriveTrain::SetSteerSetpoint(float FLSetPoint, float FRSetPoint, float RLSetPoint, float RRSetPoint) {
    frontLeft->SetSetpoint(CorrectSteerSetpoint(FLSetPoint + FLOffset));
    frontRight->SetSetpoint(CorrectSteerSetpoint(FRSetPoint + FROffset));
    rearLeft->SetSetpoint(CorrectSteerSetpoint(RLSetPoint + RLOffset));
    rearRight->SetSetpoint(CorrectSteerSetpoint(RRSetPoint + RROffset));

    if (fabs(FLSetPoint - frontLeftPos->GetAverageVoltage()) < 1.25 ||
        fabs(FLSetPoint - frontLeftPos->GetAverageVoltage()) > 3.75) {
        frontLeft->SetSetpoint(CorrectSteerSetpoint(FLSetPoint));
        FLInv = 1;
    } else {
        frontLeft->SetSetpoint(CorrectSteerSetpoint(FLSetPoint - 2.5));
        FLInv = -1;
    }

    if (fabs(FRSetPoint - frontRightPos->GetAverageVoltage()) < 1.25 ||
        fabs(FRSetPoint - frontRightPos->GetAverageVoltage()) > 3.75) {
        frontRight->SetSetpoint(CorrectSteerSetpoint(FRSetPoint));
        FRInv = 1;
    } else {
        frontRight->SetSetpoint(CorrectSteerSetpoint(FRSetPoint - 2.5));
        FRInv = -1;
    }

    if (fabs(RLSetPoint - rearLeftPos->GetAverageVoltage()) < 1.25 ||
        fabs(RLSetPoint - rearLeftPos->GetAverageVoltage()) > 3.75) {
        rearLeft->SetSetpoint(CorrectSteerSetpoint(RLSetPoint));
        RLInv = 1;
    } else {

        rearLeft->SetSetpoint(CorrectSteerSetpoint(RLSetPoint - 2.5));
        RLInv = -1;
    }

    if (fabs(RRSetPoint - rearRightPos->GetAverageVoltage()) < 1.25 ||
        fabs(RRSetPoint - rearRightPos->GetAverageVoltage()) > 3.75) {
        rearRight->SetSetpoint(CorrectSteerSetpoint(RRSetPoint));
        RRInv = 1;
    } else {
        rearRight->SetSetpoint(CorrectSteerSetpoint(RRSetPoint - 2.5));
        RRInv = -1;
    }
}

void DriveTrain::SetDriveSpeed(float FLSpeed, float FRSpeed, float RLSpeed, float RRSpeed) {
    // applies inversion variables defined in SetSteerSetPoint function
    frontLeftDrive->Set(ControlMode::PercentOutput, FLSpeed * FLInv);
    frontRightDrive->Set(ControlMode::PercentOutput, FRSpeed * FRInv);
    rearLeftDrive->Set(ControlMode::PercentOutput, RLSpeed * RLInv);
    rearRightDrive->Set(ControlMode::PercentOutput, RRSpeed * RRInv);
}

void DriveTrain::Lock() {
    // locks wheels to prevent robot movement
    SetSteerSetpoint(2.0, 0.75, 3.25, 4.5);
    SetDriveSpeed(0, 0, 0, 0);
}

void DriveTrain::DriveForward(double speed, double twist) {
    SetSteerSetpoint(2.5, 2.5, 2.5, 2.5);

    double leftSpeed = speed - twist;
    double rightSpeed = speed + twist;

    double maxSpeed = fmax(fabs(leftSpeed), fabs(rightSpeed));

    if (maxSpeed > 1) {
        leftSpeed /= maxSpeed;
        rightSpeed /= maxSpeed;
    }

    SetDriveSpeed(leftSpeed, rightSpeed, leftSpeed, rightSpeed);
}

void DriveTrain::DriveReverse(double speed, double twist) {
    DriveForward(-speed, twist);
}

void DriveTrain::DriveLeft(double speed, double twist) {
    // 3.75 is pointing left
    SetSteerSetpoint(3.75, 3.75, 3.75, 3.75);

    double leftSpeed = speed - twist;
    double rightSpeed = speed + twist;

    // Get the max speed and adjust if it's too large
    double maxSpeed = fmax(fabs(leftSpeed), fabs(rightSpeed));

    if (maxSpeed > 1) {
        leftSpeed /= maxSpeed;
        rightSpeed /= maxSpeed;
    }

    // The "right" side are the front two wheels
    SetDriveSpeed(rightSpeed, rightSpeed, leftSpeed, leftSpeed);
}

void DriveTrain::DriveRight(double speed, double twist) {
    DriveLeft(-speed, twist);
}

void DriveTrain::DriveAngle(double speed, double angle) {
    double steer = ((angle + 90) / 360) * 5.0;
    SetSteerSetpoint(steer, steer, steer, steer);
    SetDriveSpeed(speed, speed, speed, speed);
}

void DriveTrain::Stop() {
    SetDriveSpeed(0, 0, 0, 0);
}

void DriveTrain::TogglePrecisionDrive() {
    if (!precisionDrive) {
        // turn it on
        driveAdjust = PRECISION_ADJUST;
    } else {
        // turn it off
        driveAdjust = 1.0;
    }

    precisionDrive = !precisionDrive;
}

void DriveTrain::DisablePIDs() {
    RobotMap::driveTrainFrontLeft->Disable();
    RobotMap::driveTrainFrontRight->Disable();
    RobotMap::driveTrainRearLeft->Disable();
    RobotMap::driveTrainRearRight->Disable();
}

void DriveTrain::EnablePIDs() {
    RobotMap::driveTrainFrontLeft->Enable();
    RobotMap::driveTrainFrontRight->Enable();
    RobotMap::driveTrainRearLeft->Enable();
    RobotMap::driveTrainRearRight->Enable();
}
