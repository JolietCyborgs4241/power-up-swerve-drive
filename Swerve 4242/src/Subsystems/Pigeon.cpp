#include "Subsystems/Pigeon.h"
#include "RobotMap.h"

#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"

#include "Commands/UpdatePigeon.h"

Pigeon::Pigeon() : Subsystem("Pigeon") {
    // REAL BOT TALON
    pigeon = new PigeonIMU(RobotMap::driveTrainRearRightDrive);

    // PRACTICE BOT TALON
    // pigeon = new PigeonIMU(RobotMap::driveTrainRearLeftSteer);
}

void Pigeon::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new UpdatePigeon());
}

void Pigeon::CalibratePigeon() {
    pigeon->EnterCalibrationMode(ctre::phoenix::sensors::PigeonIMU::Accelerometer, 0);
}

void Pigeon::Update() {
    double data[3] = {};
    pigeon->GetYawPitchRoll(data);

    yaw = data[0];
    pitch = data[1];
    roll = data[2];
}

double Pigeon::GetYaw() {
    double angle = fmod(yaw + 90, 360);
    if (angle < 0) {
        angle += 360;
    }
    return angle;
}

bool Pigeon::WasCollision() {
    int16_t data[3] = {};
    pigeon->GetBiasedAccelerometer(data);

    // Convert from Q2.14 to floats
    double current_accel_X = data[0] * pow(2, -14);
    double current_accel_Y = data[1] * pow(2, -14);

    double jerk_X = current_accel_X - previous_accel_X;
    double jerk_Y = current_accel_Y - previous_accel_Y;

    // save the current accel values for the next update
    previous_accel_X = current_accel_X;
    previous_accel_Y = current_accel_Y;

    return fabs(jerk_X) > COLLISION_THRESHOLD_DELTA_G || fabs(jerk_Y) > COLLISION_THRESHOLD_DELTA_G;
}

bool Pigeon::AmTilted() {
    return fabs(pitch - originalPitch) > TILTED_THRESHOLD_DEGREES ||
           fabs(roll - originalRoll) > TILTED_THRESHOLD_DEGREES;
}

void Pigeon::ResetYaw(double angle) {
    pigeon->SetYaw((angle - 90) * 64.0, 0);
}

void Pigeon::SaveTilt() {
    originalPitch = pitch;
    originalRoll = roll;
}