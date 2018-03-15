#ifndef ToggleElevatorPosControl_H
#define ToggleElevatorPosControl_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "Robot.h"

class ToggleElevatorPosControl : public Command {
public:
	ToggleElevatorPosControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleElevatorPosControl_H
