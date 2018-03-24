#include "IntakeGrab.h"

IntakeGrab::IntakeGrab() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxHandler.get());
}

// Called just before this Command runs the first time
void IntakeGrab::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeGrab::Execute() {
	Robot::boxHandler->setPiston(true);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeGrab::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void IntakeGrab::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeGrab::Interrupted() {

}
