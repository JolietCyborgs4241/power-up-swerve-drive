#ifndef LidarLite_H
#define LidarLite_H

#include <Commands/Subsystem.h>

#define LIDARLITE_ADDR_DEFAULT 0x62

#include "WPILib.h"
#include <Arduino.h>

class LidarLite : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	LidarLite();
	void InitDefaultCommand();
	void begin(int = 0, bool = false, char = LIDARLITE_ADDR_DEFAULT);
	void configure(int = 0, char = LIDARLITE_ADDR_DEFAULT);
	void reset(char = LIDARLITE_ADDR_DEFAULT);
	int distance(bool = true, char = LIDARLITE_ADDR_DEFAULT);
	void write(char, char, char = LIDARLITE_ADDR_DEFAULT);
	void read(char, int, byte*, bool, char);
	void correlationRecordToSerial(char = '\n', int = 256, char = LIDARLITE_ADDR_DEFAULT);
};

#endif  // LidarLite_H
