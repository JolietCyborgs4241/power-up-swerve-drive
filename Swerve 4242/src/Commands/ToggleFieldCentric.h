#ifndef ToggleFieldCentric_H
#define ToggleFieldCentric_H


#include "Commands/Command.h"
#include "WPILib.h"

class ToggleFieldCentric : public Command {
public:
	ToggleFieldCentric();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleFieldCentric_H
