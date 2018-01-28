#ifndef LowerBoxHandler_H
#define LowerBoxHandler_H

//#include "../BoxHandler.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class LowerBoxHandler : public Command {
public:
	LowerBoxHandler();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LowerBoxHandler_H
