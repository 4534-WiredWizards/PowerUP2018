#include "VisionTest.h"

VisionTest::VisionTest(std::string thing) {
	Robot::jetsonVision->SetTarget(thing);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void VisionTest::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void VisionTest::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool VisionTest::IsFinished() {
	if(Robot::jetsonVision->GetDistanceToTarget(Robot::jetsonVision->GetTarget()) == -12345 || Robot::jetsonVision->GetAngleToTarget(Robot::jetsonVision->GetTarget()) == -12345){
		return false;
	}else{
		return true;
	}

}

// Called once after isFinished returns true
void VisionTest::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionTest::Interrupted() {

}
