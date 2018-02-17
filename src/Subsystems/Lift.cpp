// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Lift.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/LiftWithJoystick.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
Lift::Lift() : PIDSubsystem("Lift", 1.0, 0.0, 0.0) {
	SetAbsoluteTolerance(0.2);
	GetPIDController()->SetContinuous(false);
	//frc::LiveWindow::GetInstance()->AddActuator("Lift", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetName("Lift", "PIDSubsystem Controller");
	GetPIDController()->SetOutputRange(-1.0, 1.0);
	SetInputRange(0,40);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	liftEncoder = RobotMap::liftLiftEncoder;
	liftMotor = RobotMap::liftLiftMotor;
	liftLowerLimit = RobotMap::liftLiftLowerLimit;
	liftUpperLimit = RobotMap::liftLiftUpperLimit;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	if (Robot::isTesting) {
		frc::SmartDashboard::PutBoolean("liftLowerLimit", false);
		frc::SmartDashboard::PutNumber("liftSpeed", -999);
		frc::SmartDashboard::PutNumber("liftEncoder", -999);
	}
}

double Lift::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
	return liftEncoder->PIDGet();

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void Lift::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
	liftMotor->PIDWrite(output);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

	SetDefaultCommand(new LiftWithJoystick());

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Lift::setLiftSpeed(double speed){
	liftMotor->Set(speed);
}
double Lift::getLiftSpeed(){
	if(Robot::isTesting){
		return frc::SmartDashboard::GetNumber("liftSpeed", -999);
	}
	else{
		return liftMotor->Get();
	}
}
void Lift::resetDistanceCounter(){
	liftEncoder->Reset();
}
double Lift::getDistanceCounter(){
	if(Robot::isTesting){
		return frc::SmartDashboard::GetNumber("liftEncoder", -999);
	}
	else{
		return liftEncoder->GetDistance();
	}
}
bool Lift::getUpperLimit(){
	if(Robot::isTesting){
		return (frc::SmartDashboard::GetNumber("liftEncoder", -999) > 41);
	}
	else{
		return (liftEncoder->GetDistance() > 41);
	}
}
bool Lift::getLowerLimit(){
	if(Robot::isTesting){
		return frc::SmartDashboard::GetBoolean("liftLowerLimit", false);
	}
	else{
		if(liftLowerLimit->Get()){
			resetDistanceCounter();
		}
		return liftLowerLimit->Get();
	}
}
