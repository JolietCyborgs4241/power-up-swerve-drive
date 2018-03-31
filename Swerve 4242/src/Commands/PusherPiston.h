#ifndef PusherPiston_H
#define PusherPiston_H

#include "Commands/Command.h"
#include "WPILib.h"

class PusherPiston : public Command {
public:
	PusherPiston();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PusherPiston_H
