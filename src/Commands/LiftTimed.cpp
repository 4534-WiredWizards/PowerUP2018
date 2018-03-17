/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LiftTimed.h"

LiftTimed::LiftTimed(double timeout, double rate) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_timeout = timeout;
	m_rate = rate;
	SetTimeout(m_timeout);
}

// Called just before this Command runs the first time
void LiftTimed::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftTimed::Execute() {
	Robot::lift->setLiftSpeed(m_rate);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftTimed::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void LiftTimed::End() {
	Robot::lift->setLiftSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftTimed::Interrupted() {

}
