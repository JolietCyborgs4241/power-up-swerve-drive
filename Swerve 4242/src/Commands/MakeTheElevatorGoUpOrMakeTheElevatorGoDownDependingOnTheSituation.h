#ifndef MakeTheElevatorGoUpOrMakeTheElevatorGoDownDependingOnTheSituation_H
#define MakeTheElevatorGoUpOrMakeTheElevatorGoDownDependingOnTheSituation_H

#include "Commands/Command.h"
#include "WPILib.h"

class MakeTheElevatorGoUpOrMakeTheElevatorGoDownDependingOnTheSituation : public Command {
public:
	MakeTheElevatorGoUpOrMakeTheElevatorGoDownDependingOnTheSituation();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MakeTheElevatorGoUpOrMakeTheElevatorGoDownDependingOnTheSituation_H
