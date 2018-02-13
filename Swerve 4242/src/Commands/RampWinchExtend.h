#ifndef RampWinchExtend_H
#define RampWinchExtend_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "Robot.h"

class RampWinchExtend : public Command {
public:
	RampWinchExtend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RampWinchExtend_H
