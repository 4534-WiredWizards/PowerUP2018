// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.







#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/CenterAuto.h"
#include "Commands/DeployBJoings.h"
#include "Commands/DriveStraightDistance.h"
#include "Commands/DriveStraightTimed.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/EjectBox.h"
#include "Commands/EjectBoxTimed.h"
#include "Commands/EngageHighGear.h"
#include "Commands/IntakeBox.h"
#include "Commands/LiftToHeight.h"
#include "Commands/LiftWithJoystick.h"
#include "Commands/ResetGyro.h"
#include "Commands/RetractBJoings.h"
#include "Commands/StartCompressor.h"
#include "Commands/StopCompressor.h"
#include "Commands/TurnAngle.h"
#include "Commands/TurnTimed.h"
#include "Commands/DriveStraightTimed.h"
#include "Commands/BezierCurve.h"
#include "Commands/DriveStraightDistance.h"
#include "Commands/Ascend.h"
#include "Commands/Descend.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Commands/RaiseBoxHandler.h"
#include "Commands/LowerBoxHandler.h"
#include "Commands/BoxHandlerTrigger.h"
#include "Commands/SmartAuto.h"
#include "Commands/DriveStraightDistancePID.h"
#include "Commands/TurnAnglePID.h"
#include "Commands/ToggleBoxPiston.h"
#include "Commands/GoToThing.h"
#include "Commands/BoxGrab.h"

OI::OI() {
	// Process operator interface input here.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	joystick.reset(new frc::Joystick(0));

	    startButton.reset(new frc::JoystickButton(joystick.get(), 8));
	    startButton->WhileHeld(new ResetGyro());
//		selectButton.reset(new frc::JoystickButton(joystick.get(), 7));
//		selectButton->WhenPressed(new BezierCurve(0,0,0,60,80,70,80,140,100,false));
	//    rightBumper.reset(new frc::JoystickButton(joystick.get(), 6));
	//    rightBumper->WhileHeld(new IntakeBox(0.7));
	//    leftBumper.reset(new frc::JoystickButton(joystick.get(), 5));
	//    leftBumper->WhileHeld(new EjectBox(1.0));
	yButton.reset(new frc::JoystickButton(joystick.get(), 4));
	yButton->WhileHeld(new Ascend(1));
	xButton.reset(new frc::JoystickButton(joystick.get(), 3));
	//xButton->WhileHeld(new BoxGrab());
	xButton->WhileHeld(new LowerBoxHandler());
	bButton.reset(new frc::JoystickButton(joystick.get(), 2));
	//bButton->WhileHeld(new BoxGrab());
	xButton->WhileHeld(new RaiseBoxHandler());
	aButton.reset(new frc::JoystickButton(joystick.get(), 1));
	aButton->WhileHeld(new IntakeBox(.7));
	leftJoystick.reset(new frc::JoystickButton(joystick.get(), 9));
	//    leftJoystick->WhenPressed(new EngageHighGear());
	// SmartDashboard Buttons

	joystick2.reset(new frc::Joystick(1));
	//    startButton2.reset(new frc::JoystickButton( joystick2.get(), 8));
	//    startButton2->WhileHeld(new Ascend(1.0));
	//	selectButton2.reset(new frc::JoystickButton( joystick2.get(), 7));
	//	selectButton2->WhileHeld(new DeployBJoings());
	rightBumper2.reset(new frc::JoystickButton( joystick2.get(), 6));
	rightBumper2->WhileHeld(new EjectBox(1));
	leftBumper2.reset(new frc::JoystickButton( joystick2.get(), 5));
	leftBumper2->WhileHeld(new IntakeBox(.7));
	yButton2.reset(new frc::JoystickButton( joystick2.get(), 4));
	//yButton2->WhenPressed(new RaiseBoxHandler());
	//yButton2->WhenReleased(new LiftToHeight(36));
	xButton2.reset(new frc::JoystickButton( joystick2.get(), 3));
	//xButton2->WhenPressed(new LiftToHeight(17));
	bButton2.reset(new frc::JoystickButton(joystick2.get(), 2));
	bButton2->WhenPressed(new ToggleBoxPiston());
	aButton2.reset(new frc::JoystickButton( joystick2.get(), 1));
	//aButton2->WhenPressed(new LiftToHeight(1));
	//	leftJoystick2.reset(new frc::JoystickButton( joystick2.get(), 9));

	//frc::SmartDashboard::PutData("DriveStraightTimed", new DriveStraightTimed(2,0.5));
//	frc::SmartDashboard::PutData("RetractBJoings", new RetractBJoings());
	//frc::SmartDashboard::PutData("DeployBJoings", new DeployBJoings());
	frc::SmartDashboard::PutData("ResetGyro", new ResetGyro());
	//  frc::SmartDashboard::PutData("StopCompressor", new StopCompressor());
	//  frc::SmartDashboard::PutData("StartCompressor", new StartCompressor());
	//frc::SmartDashboard::PutData("TurnTimed", new TurnTimed(5,0.5));
	//frc::SmartDashboard::PutData("EjectBox", new EjectBox(1.0));
	//frc::SmartDashboard::PutData("BezierCurve", new BezierCurve(0, 0, 100, 0, 100, 100, 200, 100, 50));
	//frc::SmartDashboard::PutData("DriveStraightDistance", new DriveStraightDistance(20,4));
	//frc::SmartDashboard::PutData("LiftToHeight", new LiftToHeight(37));
	//frc::SmartDashboard::PutData("IntakeBox", new IntakeBox(900));
	frc::SmartDashboard::PutData("RaiseBoxHandler", new RaiseBoxHandler());
	frc::SmartDashboard::PutData("LowerBoxHandler", new LowerBoxHandler());
	//frc::SmartDashboard::PutData("BoxHandlerTrigger", new BoxHandlerTrigger());
	frc::SmartDashboard::PutData("DriveStraightDistancePID", new DriveStraightDistancePID(90,0.5));
	frc::SmartDashboard::PutData("TurnAnglePID", new TurnAnglePID(90.0,0.5));
	frc::SmartDashboard::PutData("Descend", new Descend(1.0));
	frc::SmartDashboard::PutData("EjectBoxTimed", new EjectBoxTimed(1,.5));


	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getJoystick() {
	return joystick;
}
std::shared_ptr<frc::Joystick> OI::getJoystick2() {
	return joystick2;
}


// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
