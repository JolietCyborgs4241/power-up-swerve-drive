#ifndef ResetPigeonYaw_H
#define ResetPigeonYaw_H

#include "Commands/Command.h"
#include "WPILib.h"
class ResetPigeonYaw : public Command {
public:
	ResetPigeonYaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetPigeonYaw_H
