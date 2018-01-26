// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "TurnAnglePID.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TurnAnglePID::TurnAnglePID(double angle, double rate): frc::PIDCommand(1.0, 0.0, 0.0) {
    m_angle = angle;
    m_rate = rate;
    GetPIDController()->SetInputRange(0.0, 360.0);
    GetPIDController()->SetOutputRange(-m_rate, m_rate);
    GetPIDController()->SetAbsoluteTolerance(1.0);
    GetPIDController()->SetSetpoint(m_angle);
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void TurnAnglePID::Initialize() {
	//if(m_angle > 0) Robot::driveTrain->ArcadeDrive(0 , m_rate);
	//else Robot::driveTrain->ArcadeDrive(0 , -1 * m_rate);
}

// Called repeatedly when this Command is scheduled to run
void TurnAnglePID::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TurnAnglePID::IsFinished() {
	return GetPIDController()->OnTarget();
}

// Called once after isFinished returns true
void TurnAnglePID::End() {
	//Robot::driveTrain->ArcadeDrive(0 , 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnAnglePID::Interrupted() {
	//Robot::driveTrain->ArcadeDrive(0 , 0);
}
double TurnAnglePID::returnPIDInput() {
	return (fmod(Robot::driveTrain->getGyroAngle(), 360));
}
void TurnAnglePID::usePIDOutput(double output) {
	Robot::driveTrain->ArcadeDrive(0 , output);
}
