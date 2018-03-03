#ifndef DeployRamp_H
#define DeployRamp_H

#include <Commands/Command.h>
#include "Robot.h"

class DeployRamp : public frc::Command {
public:
	DeployRamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeployRamp_H
