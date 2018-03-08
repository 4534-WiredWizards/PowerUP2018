#ifndef VisionTest_H
#define VisionTest_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class VisionTest : public frc::Command {
public:
	VisionTest(std::string thing);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // VisionTest_H
