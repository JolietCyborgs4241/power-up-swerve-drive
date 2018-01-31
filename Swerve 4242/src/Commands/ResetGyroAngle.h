#ifndef ResetGyroAngle_H
#define ResetGyroAngle_H

#include "Commands/Command.h"
#include "WPILib.h"
class ResetGyroAngle : public Command {
public:
	ResetGyroAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetGyroAngle_H
