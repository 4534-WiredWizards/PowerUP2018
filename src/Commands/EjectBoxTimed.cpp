// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "EjectBoxTimed.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

EjectBoxTimed::EjectBoxTimed(double timeout, double rate): frc::Command() {
    m_rate = rate;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::boxHandler.get());
	isPressed = true;
	SetTimeout(timeout);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void EjectBoxTimed::Initialize() {
	isPressed = true;
	Robot::arduinoSerial->SetAnimation("j");
}

// Called repeatedly when this Command is scheduled to run
void EjectBoxTimed::Execute() {
	Robot::boxHandler->setLeftSpeed(-1 * m_rate);
	Robot::boxHandler->setRightSpeed(-1 * m_rate);
}

// Make this return true when this Command no longer needs to run execute()
bool EjectBoxTimed::IsFinished() {
	return IsTimedOut();

}

// Called once after isFinished returns true
void EjectBoxTimed::End() {
	Robot::boxHandler->setLeftSpeed(0);
	Robot::boxHandler->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectBoxTimed::Interrupted() {
	Robot::boxHandler->setLeftSpeed(0);
	Robot::boxHandler->setRightSpeed(0);
}
