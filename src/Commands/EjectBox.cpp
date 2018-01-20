// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "EjectBox.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

EjectBox::EjectBox(double rate): frc::Command() {
    m_rate = rate;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::boxHandler.get());
	timer = new Timer();
	isPressed = true;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void EjectBox::Initialize() {
	Robot::boxHandler->setLeftSpeed(-1 * m_rate);
	Robot::boxHandler->setRightSpeed(-1 * m_rate);
}

// Called repeatedly when this Command is scheduled to run
void EjectBox::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool EjectBox::IsFinished() {
	if(isPressed && !Robot::boxHandler->getLimitSwitch()) {
		timer.Reset();
		isPressed = false;
	}
	if(timer.Get() < (1 / m_rate)) {
		return false;
	}
	else return true;
}

// Called once after isFinished returns true
void EjectBox::End() {
	Robot::boxHandler->setLeftSpeed(0);
	Robot::boxHandler->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectBox::Interrupted() {

}
