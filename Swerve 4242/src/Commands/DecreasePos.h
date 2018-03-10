#ifndef DecreasePos_H
#define DecreasePos_H

#include "Commands/Command.h"

class DecreasePos : public frc::Command {
public:
	DecreasePos();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DecreasePos_H
