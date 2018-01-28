#ifndef RaiseBoxHandler_H
#define RaiseBoxHandler_H

//#include "../BoxHandler.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class RaiseBoxHandler : public Command {
public:
	RaiseBoxHandler();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RaiseBoxHandler_H
