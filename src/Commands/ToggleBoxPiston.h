#ifndef ToggleBoxPiston_H
#define ToggleBoxPiston_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class ToggleBoxPiston : public Command {
public:
	ToggleBoxPiston();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleBoxPiston_H
