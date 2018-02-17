// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "EndgameExtensions.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

EndgameExtensions::EndgameExtensions() : frc::Subsystem("EndgameExtensions"){
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftBJoing = RobotMap::endgameExtensionsLeftBJoing;
    rightBJoing = RobotMap::endgameExtensionsRightBJoing;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void EndgameExtensions::InitDefaultCommand(){

    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void EndgameExtensions::SetLeftBJoing(bool on){
	frc::SmartDashboard::PutBoolean("LeftBJoingValue",on);
	leftBJoing->Set(on);
}

void EndgameExtensions::SetRightBJoing(bool on){
	frc::SmartDashboard::PutBoolean("RightBJoingValue",on);
	rightBJoing->Set(on);
}

void EndgameExtensions::Periodic(){
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

