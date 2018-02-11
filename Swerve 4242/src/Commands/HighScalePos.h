#ifndef HighScalePos_H
#define HighScalePos_H

#include "Commands/Command.h"
#include "WPILib.h"

class HighScalePos : public Command {
public:
	HighScalePos();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HighScalePos_H
