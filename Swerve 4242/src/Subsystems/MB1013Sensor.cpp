#include "MB1013Sensor.h"
#include "../RobotMap.h"
#include "WPILib.h"

using namespace frc;

MB1013Sensor::MB1013Sensor() : Subsystem("MB1013Sensor") {
    aInput = new AnalogInput(4);
}

void MB1013Sensor::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

double MB1013Sensor::DistanceCM() {
    // Every (5/5120) V is 1 mm
    // Divide by 10 for mm to cm
    double distance = (aInput->GetVoltage() / (5 / 5120.0)) / 10.0;

    // Ignore ranges above 450 cm
    if (distance > MAX_DISTANCE) {
        return MAX_DISTANCE;
    }

    return distance;
}

double MB1013Sensor::SmoothedDistanceCM() {
    // if unpopulated distance then return the sensor reading
    if (last_distance = -1) {
        last_distance = DistanceCM();
        return last_distance;
    }

    // low pass filter thing I think
    double distance = DistanceCM() * SMOOTH_WEIGHT + (1 - SMOOTH_WEIGHT) * last_distance;
    last_distance = distance;

    return distance;
}

double MB1013Sensor::SmoothedDistanceFeet() {
    // Returns CM / 2.54 / 12 (So multipies by 1/2.54/12)
    return SmoothedDistanceCM() * 0.032808399;
}
