#include "IntakeDrop.h"

IntakeDrop::IntakeDrop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void IntakeDrop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeDrop::Execute() {
	Robot::boxHandler->closeGrabber(true);

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeDrop::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void IntakeDrop::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeDrop::Interrupted() {

}
