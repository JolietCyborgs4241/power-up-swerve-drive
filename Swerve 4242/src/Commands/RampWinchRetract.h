#ifndef RampWinchRetract_H
#define RampWinchRetract_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "Robot.h"

class RampWinchRetract : public Command {
public:
	RampWinchRetract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RampWinchRetract_H
