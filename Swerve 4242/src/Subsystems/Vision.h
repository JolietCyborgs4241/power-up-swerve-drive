#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Vision : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	SerialPort* jeVois;


public:
	Vision();
	void InitDefaultCommand();
	void InitializeVision();
	std::string* ReadData();
};

#endif  // Vision_H
