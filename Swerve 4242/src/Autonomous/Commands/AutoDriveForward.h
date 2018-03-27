#ifndef AutoDriveForward_H
#define AutoDriveForward_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveForward: public Command {
public:
	AutoDriveForward(double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

    double timeout;
};

#endif
