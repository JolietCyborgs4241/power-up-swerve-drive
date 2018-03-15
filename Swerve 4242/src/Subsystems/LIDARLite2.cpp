
#include "LIDARLite2.h"

LIDARLite2::LIDARLite2(int i2c_address) {
  i2c = new I2C(frc::I2C::kMXP, i2c_address);
}

int LIDARLite2::getDistance() {
	i2c->Write(0x00, 0x04);
	int count = 999;
	bool found = false;
	while(count-- > 0) {
		uint8_t busy = 1;
		i2c->Read(0x01, 1, &busy);
		if (busy << 7 == 0) {
			found = true;
			break;
		}
		Wait(0.001);
	}

	if (found) {
		uint8_t distanceArray[2];
		i2c->Read(0x8f, 2, distanceArray);
		// Shift high byte and add to low byte
		uint16_t distance = (distanceArray[0] << 8) + distanceArray[1];

		return distance;
	} else {
		return -2;
	}
}
