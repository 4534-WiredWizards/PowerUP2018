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
double JetsonVision::GetAngleToTarget(std::string target){
	if(target == "cube")
	{
		return visionTable->GetNumber("cubeAngle",-12345);
	}
	else
	{
		return visionTable->GetNumber("switchAngle",-12345);
	}
}
double JetsonVision::GetDistanceToTarget(std::string target){
	if(target == "cube")
	{
		return visionTable->GetNumber("cubeDistance",-12345);
	}
	else
	{
		return visionTable->GetNumber("switchDistance",-12345);
	}
}
std::string JetsonVision::GetTarget(){
	return visionTable->GetString("target","alacazam");
}
void JetsonVision::SetTarget(std::string target){
	visionTable->PutString("target",target);
	if(target == "cube")
	{
		visionTable->PutNumber("switchAngle",-12345);
		visionTable->PutNumber("switchDistance",-12345);
	}
	else
	{
		visionTable->PutNumber("cubeAngle",-12345);
		visionTable->PutNumber("cubeDistance",-12345);
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
