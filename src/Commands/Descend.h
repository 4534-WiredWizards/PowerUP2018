#ifndef DESCEND_H
#define DESCEND_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Descend : public Command {
public:
	Descend(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_speed;
};

#endif  // Descend_H
