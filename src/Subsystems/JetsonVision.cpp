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
double JetsonVision::GetAngleToTarget(){
	return visionTable->GetNumber("angle",-12345);
}
double JetsonVision::GetDistanceToTarget(){
	return visionTable->GetNumber("distance",-12345);
}
std::string JetsonVision::GetTarget(){
	return visionTable->GetString("target","alacazam");
}
void JetsonVision::SetTarget(std::string target){
	visionTable->PutString("target",target);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
