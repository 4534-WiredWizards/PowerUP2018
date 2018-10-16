#include "ToggleBoxPiston.h"
bool state = false;
ToggleBoxPiston::ToggleBoxPiston() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxHandler.get());
}

// Called just before this Command runs the first time
void ToggleBoxPiston::Initialize() {
	state = Robot::boxHandler->getPiston();
}

// Called repeatedly when this Command is scheduled to run
void ToggleBoxPiston::Execute() {
	Robot::boxHandler->setPiston(!state);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleBoxPiston::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleBoxPiston::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleBoxPiston::Interrupted() {

}
