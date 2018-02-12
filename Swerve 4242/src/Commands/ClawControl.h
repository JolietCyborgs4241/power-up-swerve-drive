#ifndef ClawControl_H
#define ClawControl_H

#include "Commands/Command.h"
#include "WPILib.h"
class ClawControl : public Command {
public:
	ClawControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawControl_H
