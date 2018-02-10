#ifndef ElelvatorControl_H
#define ElelvatorControl_H

#include "Commands/Command.h"
#include "WPILib.h"

class ElelvatorControl : public Command {
public:
	ElelvatorControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElelvatorControl_H
