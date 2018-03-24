#ifndef ToggleIntakeSolenoid_H
#define ToggleIntakeSolenoid_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class ToggleIntakeSolenoid : public Command {
public:
	ToggleIntakeSolenoid();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleIntakeSolenoid_H
