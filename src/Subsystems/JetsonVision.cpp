#include "JetsonVision.h"
#include "../RobotMap.h"

JetsonVision::JetsonVision() : Subsystem("JetsonVision") {
visionTable=(new NetworkTable::GetTable("vision"));
}

void JetsonVision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
