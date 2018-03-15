
#include "LIDARLite3.h"

LIDARLite3::LIDARLite3() {
	counter = new Counter(new DigitalInput(5));
	counter->SetMaxPeriod(1.0);
	counter->SetSemiPeriodMode(true);
	counter->Reset();
}

double LIDARLite3::Distance() {
	double cm;
	if (counter->Get() < 1) {
		return 0;
	}
	cm = (counter->GetPeriod() * 1000000.0 / 10.0) - 18;
}
