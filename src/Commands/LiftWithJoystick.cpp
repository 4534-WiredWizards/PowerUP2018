// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "LiftWithJoystick.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

LiftWithJoystick::LiftWithJoystick(): frc::Command() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(Robot::chassis.get());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lift.get());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void LiftWithJoystick::Initialize() {
	Robot::lift->Disable(); //turn off PID control.
}

// Called repeatedly when this Command is scheduled to run
void LiftWithJoystick::Execute() {
	double Anthony=(-1 *Robot::oi->getJoystick2()->GetRawAxis(5));
	if (!Robot::isTesting){
		if (.1 > Anthony && Anthony > -.1){
			Anthony = 0; //deadzone it.
		}
	} else {

	}
	if (Robot::lift->getUpperLimit() && Anthony > 0){
		Anthony = 0;
	}
	if (Robot::lift->getLowerLimit() && Anthony < 0){
		Anthony = 0;
	}
//	if(Robot::lift->getDistanceCounter() < Robot::lift->liftMin+6 && Anthony < 0) {
//		Anthony *= (Robot::lift->getDistanceCounter()/6);
//	}
//	if (Robot::lift->getDistanceCounter() > Robot::lift->liftMax-6 && Anthony > 0){
//		Anthony *= ((Robot::lift->liftMax-Robot::lift->getDistanceCounter())/6);
//	}

	Robot::lift->setLiftSpeed(Anthony);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftWithJoystick::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftWithJoystick::Interrupted() {

}
