#ifndef BoxHandlerTrigger_H
#define BoxHandlerTrigger_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class BoxHandlerTrigger : public Command {
public:
	BoxHandlerTrigger();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BoxHandlerTrigger_H
