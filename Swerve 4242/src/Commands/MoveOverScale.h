#ifndef MoveOverScale_H
#define MoveOverScale_H

#include "Commands/Command.h"
#include "WPILib.h"

class MoveOverScale : public Command {
public:
	MoveOverScale();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveOverScale_H
