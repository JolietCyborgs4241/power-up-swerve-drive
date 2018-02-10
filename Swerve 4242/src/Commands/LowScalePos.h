#ifndef LowScalePos_H
#define LowScalePos_H

#include "Commands/Command.h"
#include "WPILib.h"

class LowScalePos : public Command {
public:
	LowScalePos();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowScalePos_H
