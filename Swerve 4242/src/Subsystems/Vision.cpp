#include "Vision.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "SerialPort.h"
#include <iostream>
using namespace frc;

Vision::Vision() : Subsystem("Vision") {
	SerialPort* visionPort = new SerialPort(11520, SerialPort::Port::kUSB, 8, SerialPort::Parity::kParity_None, SerialPort::StopBits::kStopBits_One);
	char buffer[8000];
	using namespace std;
	cout << visionPort->Read(buffer, 8000) <<endl ;
	using namespace frc;

}


