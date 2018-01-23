// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "RightAuto.h"
#include "DriveStraightTimed.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RightAuto::RightAuto() {
Robot::SwitchPosition
switch(Robot::target){
 case"DriveStraight":
	//drive forward past line
	break;
 case"switch":
	 switch('Robot::SwitchPosition[0]' + 'Robot::SwitchPosition[1]'){
	 	 case("LL"):
	 		//go to left on switch then left on scale
	 		break;
	 	 case("LR"):
		 	 //go to left switch then right scale
		    break;
	 	 case("RL"):
		 	 //go to right switch then left scale
		    break;
	 	 case("RR"):
		 	 //go to right switch then right scale
		    break;
	 }
	 break;
 default:
	 //send message that something is wrong!
	 break;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
                AddSequential(new DriveStraightTimed(0, 0));
              // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }
