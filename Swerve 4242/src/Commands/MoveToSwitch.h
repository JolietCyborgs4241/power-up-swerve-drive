#ifndef MoveToSwitch_H
#define MoveToSwitch_H

#include "Commands/Command.h"
#include "WPILib.h"

class MoveToSwitch : public Command {
public:
	MoveToSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveToSwitch_H
