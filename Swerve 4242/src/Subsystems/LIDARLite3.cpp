
#include "LIDARLite3.h"

LIDARLite3::LIDARLite3(int source) {
	counter = new Counter(new DigitalInput(source));
	counter->SetMaxPeriod(1.0);
	counter->SetSemiPeriodMode(true);
	counter->Reset();
}

double LIDARLite3::Distance() {
	if (counter->Get() < 1) {
		return 0;
	}
	double cm = (counter->GetPeriod() * 1000000.0 / 10.0) - 18;
	return cm;
}
