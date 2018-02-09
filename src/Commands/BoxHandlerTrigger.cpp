#include "BoxHandlerTrigger.h"

BoxHandlerTrigger::BoxHandlerTrigger() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void BoxHandlerTrigger::Initialize() {
	//frc::SmartDashboard::PutBoolean("IsRunning", true);  // For Debug...

}

// Called repeatedly when this Command is scheduled to run
void BoxHandlerTrigger::Execute() {
	double Andrew = Robot::oi->getJoystick()->GetRawAxis(2)-Robot::oi->getJoystick()->GetRawAxis(3);
	if (Robot::boxHandler->getLimitSwitch() && Andrew < 0){
		Andrew = 0;
	}
	Robot::boxHandler->setLeftSpeed(Andrew);
	Robot::boxHandler->setRightSpeed(Andrew);
}

// Make this return true when this Command no longer needs to run execute()
bool BoxHandlerTrigger::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BoxHandlerTrigger::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BoxHandlerTrigger::Interrupted() {

}
