#include "LowerBoxHandler.h"

LowerBoxHandler::LowerBoxHandler() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LowerBoxHandler::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LowerBoxHandler::Execute() {
	Robot::boxHandler->setPiston(false);
}

// Make this return true when this Command no longer needs to run execute()
bool LowerBoxHandler::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LowerBoxHandler::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerBoxHandler::Interrupted() {

}
