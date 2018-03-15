#ifndef ElevatorToScale_H
#define ElevatorToScale_H

#include "Commands/Command.h"
#include "WPILib.h"

class ElevatorToScale : public Command {
public:
	ElevatorToScale();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElevatorToScale_H
