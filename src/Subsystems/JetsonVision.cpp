#include "JetsonVision.h"
#include "../RobotMap.h"

JetsonVision::JetsonVision() : Subsystem("JetsonVision") {
	//const llvm::Twine apples = llvm::Twine("vision");
	//nt::NetworkTableInstance instance = nt::NetworkTable::GetInstance();
	//visionTable = NetworkTable::GetSubTable(llvm::Twine("vision"));
	visionTable = NetworkTable::GetTable("vision");
}

void JetsonVision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
