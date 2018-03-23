
#include "LIDARLite.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

LIDARLite::LIDARLite(int source) {
	counter = new Counter(new DigitalInput(source));
	counter->SetMaxPeriod(1.0);
	counter->SetSemiPeriodMode(true);
	counter->Reset();
}

double LIDARLite::Distance() {
	if (counter->Get() < 1) {
		return 0;
	}

	double distance = (counter->GetPeriod() * 1000000.0 / 10.0) - 18;

	return distance;
}
