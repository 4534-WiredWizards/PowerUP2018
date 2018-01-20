// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "TurnTimed.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TurnTimed::TurnTimed(double timeout, double rate): frc::Command() {
    m_timeout = timeout;
    m_rate = rate;
    SetTimeout(m_timeout);
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void TurnTimed::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TurnTimed::Execute() {
Robot::driveTrain->TankDrive(m_rate,-m_rate);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnTimed::IsFinished() {
    return IsTimedOut();
}

// Called once after isFinished returns true
void TurnTimed::End() {
Robot::driveTrain->TankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnTimed::Interrupted() {

}
