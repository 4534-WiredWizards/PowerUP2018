#ifndef Ascend_H
#define Ascend_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Ascend : public CommandBase {
public:
	Ascend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Ascend_H
