#ifndef Pause_H
#define Pause_H

#include "Commands/Command.h"
#include "WPILib.h"
class Pause : public Command {
public:
	Pause();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Pause_H
