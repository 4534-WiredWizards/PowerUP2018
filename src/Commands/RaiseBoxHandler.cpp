#include "RaiseBoxHandler.h"

RaiseBoxHandler::RaiseBoxHandler() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxHandler.get());
}

// Called just before this Command runs the first time
void RaiseBoxHandler::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RaiseBoxHandler::Execute() {
	Robot::boxHandler->setPiston(true);
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseBoxHandler::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RaiseBoxHandler::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseBoxHandler::Interrupted() {

}
