#ifndef IntakeGrab_H
#define IntakeGrab_H

//#include "../BoxHandler.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class IntakeGrab : public Command {
public:
	IntakeGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RaiseBoxHandler_H
