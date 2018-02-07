#ifndef MagEncoder_H
#define MagEncoder_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"

class MagEncoder : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Encoder* enc;

public:
	MagEncoder();
	void InitDefaultCommand();
	void DriveDistance();
	bool AutoDriveTest();
};

#endif  // MagEncoder_H
