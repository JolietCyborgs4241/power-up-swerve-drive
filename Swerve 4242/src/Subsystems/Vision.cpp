#include "Vision.h"
#include "../RobotMap.h"
#include "SerialPort.h"

using namespace frc;

Vision::Vision() : Subsystem("ExampleSubsystem") {
	jeVois = new SerialPort(115200, frc::SerialPort::kUSB);
}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Vision::InitializeVision() {
	jeVois->EnableTermination('\n');
}

std::string* Vision::ReadData(){
	char buffer[200];
	int numRead = jeVois->Read(&buffer[0], 200);
	buffer[numRead] = 0;
	return new std::string(buffer);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
