#ifndef MoveElelvator_H
#define MoveElelvator_H

#include "Commands/Command.h"
#include "WPILib.h"

class MoveElelvator : public Command {
public:
	MoveElelvator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveElelvator_H
