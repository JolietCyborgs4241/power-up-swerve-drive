#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class TogglePrecisionDrive : public Command {
public:
	TogglePrecisionDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
