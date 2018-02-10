#ifndef AutoDriveReverse_H
#define AutoDriveReverse_H

#include "Auto/Auto.h"
#include "WPILib.h"

class AutoDriveReverse: public Command
{
public:
	AutoDriveReverse();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
