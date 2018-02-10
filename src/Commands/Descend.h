#ifndef DESCEND_H
#define DESCEND_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Descend : public Command {
public:
	Descend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Descend_H
