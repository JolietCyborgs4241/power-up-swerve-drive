#ifndef ElevatorToSwitch_H
#define ElevatorToSwitch_H

#include "Commands/Command.h"
#include "WPILib.h"

class ElevatorToSwitch : public Command {
public:
	ElevatorToSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElevatorToSwitch_H
