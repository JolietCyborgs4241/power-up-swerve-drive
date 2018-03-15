#ifndef DeployRamp_H
#define DeployRamp_H

#include <Commands/Command.h>
#include "Robot.h"

class DeployRamp : public frc::Command {
private:
	float startTime;
	bool done;
	const int TIME_TO_RELEASE = 1;
public:
	DeployRamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeployRamp_H
