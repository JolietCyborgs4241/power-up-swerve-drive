#ifndef AutoDriveForward_H
#define AutoDriveForward_H

#include "Auto/Auto.h"
#include "WPILib.h"

class AutoDriveForward: public Command
{
public:
	AutoDriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
