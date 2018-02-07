// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveWithJoystick.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveWithJoystick::DriveWithJoystick(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	double ArnoldSpeed = Robot::oi->getJoystick()->GetY();
	if (.1 > ArnoldSpeed && ArnoldSpeed > -.1){
		ArnoldSpeed = 0;
	}
	double ArnoldRotation = Robot::oi->getJoystick()->GetX();
	if (.1 > ArnoldRotation && ArnoldRotation > -.1){
		ArnoldRotation = 0;
	}
	Robot::driveTrain->ArcadeDrive(-ArnoldSpeed,ArnoldRotation);
	if(fabs(Robot::driveTrain->getLeftRate()) > 20
		&&
		fabs(Robot::driveTrain->getRightRate()) > 20)
	{
		Robot::driveTrain->setShift(Robot::oi->leftJoystick->Get());
	}
	else{
		Robot::driveTrain->setShift(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	Robot::driveTrain->TankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
	Robot::driveTrain->TankDrive(0,0);
}
