#include "ToggleIntakeSolenoid.h"
bool grabberState = false;
ToggleIntakeSolenoid::ToggleIntakeSolenoid() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxHandler.get());
}

// Called just before this Command runs the first time
void ToggleIntakeSolenoid::Initialize() {
	grabberState = Robot::boxHandler->getGrabber();
}

// Called repeatedly when this Command is scheduled to run
void ToggleIntakeSolenoid::Execute() {
	Robot::boxHandler->closeGrabber(!grabberState);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleIntakeSolenoid::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleIntakeSolenoid::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleIntakeSolenoid::Interrupted() {

}
