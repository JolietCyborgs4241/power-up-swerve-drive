#ifndef AutoDriveForward_H
#define AutoDriveForward_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "Subsystems/PositionPID.h"
#include "Subsystems/PigeonPID.h"

class PositionDrive: public Command {
public:
	PositionDrive(double pos, double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

    double timeout;
    PositionPID* posPID;
    PigeonPID* pigeonPID;
};

#endif
