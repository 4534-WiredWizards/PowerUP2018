// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"
#include "SmartDashboard/SmartDashboard.h"


#include "DriveTrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveWithJoystick.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftMasterTalon = RobotMap::driveTrainLeftMasterTalon;
    rightMasterTalon = RobotMap::driveTrainRightMasterTalon;
    driver = RobotMap::driveTrainDriver;
    leftFollowerTalon = RobotMap::driveTrainLeftFollowerTalon;
    rightFollowerTalon = RobotMap::driveTrainRightFollowerTalon;
    leftFollowerVictor = RobotMap::driveTrainLeftFollowerVictor;
    rightFollowerVictor = RobotMap::driveTrainRightFollowerVictor;
    driveGyro = RobotMap::driveTrainDriveGyro;
    compressor = RobotMap::driveTrainCompressor;
    leftShifter = RobotMap::driveTrainLeftShifter;
    rightShifter = RobotMap::driveTrainRightShifter;
    leftPTO = RobotMap::driveTrainLeftPTO;
    rightPTO = RobotMap::driveTrainRightPTO;
    leftDriveEncoder = RobotMap::driveTrainLeftDriveEncoder;
    rightDriveEncoder = RobotMap::driveTrainRightDriveEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftFollowerTalon->Follow(*leftMasterTalon);
    leftFollowerVictor->Follow(*leftMasterTalon);
    rightFollowerTalon->Follow(*rightMasterTalon);
    rightFollowerVictor->Follow(*rightMasterTalon);
    leftMasterTalon->ConfigOpenloopRamp(.5,0);
    rightMasterTalon->ConfigOpenloopRamp(.5,0);
    leftMasterTalon->ConfigPeakCurrentLimit(30,0);
    rightMasterTalon->ConfigPeakCurrentLimit(30,0);
    leftMasterTalon->ConfigPeakCurrentDuration(100,0);
    rightMasterTalon->ConfigPeakCurrentDuration(100,0);
    leftMasterTalon->ConfigContinuousCurrentLimit(27,0);
    rightMasterTalon->ConfigContinuousCurrentLimit(27,0);
    leftMasterTalon->EnableCurrentLimit(true);
    rightMasterTalon->EnableCurrentLimit(true);
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveWithJoystick());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void DriveTrain::TankDrive(double leftRate, double rightRate){

	driver->TankDrive(leftRate, rightRate);

}
void DriveTrain::ArcadeDrive(double speed, double rotate){

	driver->ArcadeDrive(speed, rotate);

}
void DriveTrain::resetDistanceCounter(){

	leftDriveEncoder->Reset();
	rightDriveEncoder->Reset();

}
double DriveTrain::getLeftDistanceCounter(){
	if (!Robot::isTesting){
	return leftDriveEncoder->GetDistance();
	}
	else{
		return frc::SmartDashboard::GetNumber("leftDriverEncoder",-99); //marker
	}
}
double DriveTrain::getRightDistanceCounter(){
	if (!Robot::isTesting){
	return rightDriveEncoder->GetDistance();
	}
	else{
		return frc::SmartDashboard::GetNumber("rightDriverEncoder",-99); //marker
	}
}
double DriveTrain::getGyroAngle(){
	if (!Robot::isTesting){
	return driveGyro->GetAngle();
	}
	else{
	return frc:SmartDashboard::GetNumber("driveGyro",-99); //marker
	}
}
void DriveTrain::resetGyroAngle(){
	driveGyro->Reset();
}
void DriveTrain::setShift(bool state){

	leftShifter->Set(state);
	rightShifter->Set(state);

}
bool DriveTrain::getShift(){
	if (!Robot::isTesting){
	return leftShifter->Get();
	return rightShifter->Get();
	}
	else{
		frc::SmartDashboard::GetNumber("leftShifter",-99);
		frc::SmartDashboard::GetNumber("rightShifter",-99);
	}
}
void DriveTrain::setPTO(bool state){
	leftPTO->Set(state);
	rightPTO->Set(state);
}
bool DriveTrain::getPTO(){
	if (!Robot::isTesting){
	return leftPTO->Get();
	return rightPTO->Get();
	}
	else{
		frc::SmartDashboard::GetNumber("leftPTO",Get);
		frc::SmartDashboard::GetNumber("rightPTO",Get);
	}
}
void DriveTrain::Periodic() {
    // Put code here to be run every loop

}
void DriveTrain::StartCompressor(){

	compressor->Start();

}
void DriveTrain::StopCompressor(){

		compressor->Stop();

	}

// Put methods for controlling this subsystem
// here. Call these from Commands.

