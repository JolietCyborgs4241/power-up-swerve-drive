#ifndef ToggleTwistPID_H
#define ToggleTwistPID_H

#include "Commands/Command.h"
#include "WPILib.h"

class ToggleTwistPID : public Command {
public:
	ToggleTwistPID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleTwistPID_H
