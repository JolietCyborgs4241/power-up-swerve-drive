#ifndef GetGameData_H
#define GetGameData_H

#include "Commands/Command.h"
#include "WPILib.h"
class GetGameData : public Command {
public:
	GetGameData();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetGameData_H
