// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// You're going to die someday.






#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/CenterAuto.h"
#include "Commands/DeployBJoings.h"
#include "Commands/DeployLeftWing.h"
#include "Commands/DeployRightWing.h"
#include "Commands/DisengagePTO.h"
#include "Commands/DriveStraightDistance.h"
#include "Commands/DriveStraightTimed.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/EjectBox.h"
#include "Commands/EngageHighGear.h"
#include "Commands/EngagePTO.h"
#include "Commands/IntakeBox.h"
#include "Commands/LeftAuto.h"
#include "Commands/LiftToHeight.h"
#include "Commands/LiftWithJoystick.h"
#include "Commands/ResetGyro.h"
#include "Commands/RetractBJoings.h"
#include "Commands/RightAuto.h"
#include "Commands/SampleAutonomousCommand.h"
#include "Commands/StartCompressor.h"
#include "Commands/StopCompressor.h"
#include "Commands/TurnAngle.h"
#include "Commands/TurnTimed.h"
#include "Commands/DriveStraightTimed.h"
#include "Commands/BezierCurve.h"
#include "Commands/DriveStraightDistance.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Commands/RaiseBoxHandler.h"
#include "Commands/LowerBoxHandler.h"
#include "Commands/BoxHandlerTrigger.h"
#include "commands/SmartAuto.h"


OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    joystick.reset(new frc::Joystick(0));
    
    startButton.reset(new frc::JoystickButton(joystick.get(), 8));
    //startButton->WhileHeld(new EngagePTO());
    selectButton.reset(new frc::JoystickButton(joystick.get(), 7));
    selectButton->WhileHeld(new DeployBJoings());
    rightBumper.reset(new frc::JoystickButton(joystick.get(), 6));
    rightBumper->WhileHeld(new DeployRightWing());
    leftBumper.reset(new frc::JoystickButton(joystick.get(), 5));
    leftBumper->WhileHeld(new DeployLeftWing());
    yButton.reset(new frc::JoystickButton(joystick.get(), 4));
    yButton->WhenPressed(new LiftToHeight(40));
    xButton.reset(new frc::JoystickButton(joystick.get(), 3));
    xButton->WhenPressed(new LiftToHeight(0));
    bButton.reset(new frc::JoystickButton(joystick.get(), 2));
    bButton->WhileHeld(new EjectBox(0.5));
    aButton.reset(new frc::JoystickButton(joystick.get(), 1));
    aButton->WhileHeld(new IntakeBox(0.5));
    leftJoystick.reset(new frc::JoystickButton(joystick.get(), 9));
    //leftJoystick->WhenPressed(new EngageHighGear());

   joystick1.reset(new frc::Joystick(1));
   PTOButton.reset(new frc::JoystickButton(joystick1.get(), 4));
   PTOButton->WhileHeld(new EngagePTO());
   RightWingButton.reset(new frc::JoystickButton(joystick1.get(), 3));
   RightWingButton->WhileHeld(new DeployRightWing());
   LeftWingButton.reset(new frc::JoystickButton(joystick1.get(), 2));
   LeftWingButton->WhileHeld(new DeployLeftWing());
   BJoingButton.reset(new frc::JoystickButton(joystick1.get(), 1));
   BJoingButton->WhileHeld(new DeployBJoings());

    // SmartDashboard Buttons

    //frc::SmartDashboard::PutData("DriveStraightTimed", new DriveStraightTimed(2,0.5));
    frc::SmartDashboard::PutData("RetractBJoings", new RetractBJoings());
    //frc::SmartDashboard::PutData("DeployBJoings", new DeployBJoings());
    //frc::SmartDashboard::PutData("ResetGyro", new ResetGyro());
  //  frc::SmartDashboard::PutData("StopCompressor", new StopCompressor());
  //  frc::SmartDashboard::PutData("StartCompressor", new StartCompressor());
    //frc::SmartDashboard::PutData("DisengagePTO", new DisengagePTO());
    //frc::SmartDashboard::PutData("EngagePTO", new EngagePTO());
  //  frc::SmartDashboard::PutData("DeployLeftWing", new DeployLeftWing());
  //  frc::SmartDashboard::PutData("DeployRightWing", new DeployRightWing());
    //frc::SmartDashboard::PutData("TurnTimed", new TurnTimed(5,0.5));
    frc::SmartDashboard::PutData("EjectBox", new EjectBox(10));
    //frc::SmartDashboard::PutData("BezierCurve", new BezierCurve(0, 0, 100, 0, 100, 100, 200, 100, 50));
    //frc::SmartDashboard::PutData("DriveStraightDistance", new DriveStraightDistance(20,4));
    //frc::SmartDashboard::PutData("TurnAngle", new TurnAngle(90,5));
    frc::SmartDashboard::PutData("IntakeBox", new IntakeBox(900));
    frc::SmartDashboard::PutData("RaiseBoxHandler", new RaiseBoxHandler());
    frc::SmartDashboard::PutData("BoxHandlerTrigger", new BoxHandlerTrigger());




    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getJoystick() {
   return joystick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
