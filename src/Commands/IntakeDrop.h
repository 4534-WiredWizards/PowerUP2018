#ifndef IntakeDrop_H
#define IntakeDrop_H

//#include "../BoxHandler.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class IntakeDrop : public Command {
public:
	IntakeDrop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeDrop_H
