#include "FeederWheels.h"
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>
#include "ctre/Phoenix.h"
FeederWheels::FeederWheels() : Subsystem("FeederWheels") {
FeederWheel1 = new WPI_TalonSRX (8);
FeederWheel2 = new WPI_TalonSRX (7);
}

void FeederWheels::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
