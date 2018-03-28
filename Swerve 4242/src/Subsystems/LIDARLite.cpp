
#include "LIDARLite.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

LIDARLite::LIDARLite(int source) : Subsystem("LIDARLite") {
    counter = new Counter(new DigitalInput(source));
    counter->SetMaxPeriod(1.0);
    counter->SetSemiPeriodMode(true);
    counter->Reset();
}

void LIDARLite::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double LIDARLite::DistanceCM() {
    if (counter->Get() < 1) {
        return 0;
    }

    double distance = (counter->GetPeriod() * 1000000.0 / 10.0) + calibration_offset;
    if (distance < 0) {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        return MAX_DISTANCE;
    }

    return distance;
}

double LIDARLite::SmoothedDistanceCM() {
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
