#ifndef IncreasePos_H
#define IncreasePos_H

#include "Commands/Command.h"
#include "WPILib.h"

class IncreasePos : public Command {
public:
	IncreasePos();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IncreasePos_H
