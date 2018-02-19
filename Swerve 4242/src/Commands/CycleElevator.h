#ifndef CycleElevator_H
#define CycleElevator_H

#include "Commands/Command.h"
#include "WPILib.h"
class CycleElevator : public Command {
public:
	CycleElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
//	double ElevatorCycleNumber();
	int ElevatorCycleNum;
};

#endif  // CycleElevator_H
