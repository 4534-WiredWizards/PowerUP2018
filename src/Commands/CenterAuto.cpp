// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "../Robot.h"
#include "CenterAuto.h"
#include "DriveStraightDistancePID.h"
#include "EjectBox.h"
#include "TurnAnglePID.h"
#include "TurnAngle.h"

#include "LiftToHeight.h"
#include "BoxHandlerTrigger.h"
#include "DriveStraightTimed.h"
#include "ResetGyro.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

CenterAuto::CenterAuto() {
	AddSequential (new DriveStraightTimed(frc::SmartDashboard::GetNumber("Auto Delay",0),0));
	AddSequential (new ResetGyro());

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

	switch (Robot::target){
	case 0:
		AddSequential(new DriveStraightDistancePID(120,.5));
		break;
	case 1:
		if(Robot::SwitchPosition[0]=='L'){
			AddSequential (new DriveStraightDistancePID(48,.5));
			AddSequential (new TurnAnglePID(-90.0,.5));
			AddSequential (new DriveStraightDistancePID(66,.5));
			AddSequential (new TurnAnglePID(0,.5));
			AddSequential (new DriveStraightDistancePID(84,.5));
			AddParallel (new LiftToHeight(17));
			AddSequential (new EjectBox(1));
		} 	else {
			AddSequential (new DriveStraightDistancePID(48,.5));
			AddSequential (new TurnAnglePID(90,0.5));
			AddSequential (new DriveStraightDistancePID(66,.5));
			AddSequential (new TurnAnglePID(0,.5));
			AddSequential (new DriveStraightDistancePID(84,.5));
			AddParallel (new LiftToHeight(17));
			AddSequential (new EjectBox(1));
		}
		break;
	case 2:
		if(Robot::SwitchPosition[1]=='L'){
			AddSequential (new DriveStraightDistancePID(96,.5));
			AddSequential (new TurnAngle(-90,.5));
			AddSequential (new DriveStraightDistancePID(120,.5));
			AddSequential (new TurnAngle(0,.5));
			AddSequential (new DriveStraightDistancePID(228,.5));
			AddSequential (new TurnAngle(90,.5));
			AddParallel (new LiftToHeight(40));
			AddSequential (new EjectBox(1));
		}	else {
			AddSequential (new DriveStraightDistancePID(96,.5));
			AddSequential (new TurnAngle(90,.5));
			AddSequential (new DriveStraightDistancePID(120,.5));
			AddSequential (new TurnAngle(0,.5));
			AddSequential (new DriveStraightDistancePID(228,.5));
			AddSequential (new TurnAngle(-90,.5));
			AddParallel (new LiftToHeight(40));
			AddSequential (new EjectBox(1));

		}
		break;
	case 3:
		if(Robot::SwitchPosition[0]=='L'){
			AddSequential (new DriveStraightDistancePID(84,1.0));
			AddSequential (new TurnAngle(-90,1.0));
			AddSequential (new DriveStraightDistancePID(66,1.0));
			AddSequential (new TurnAngle(0,1.0));
			AddSequential (new DriveStraightDistancePID(48,1.0));
			AddParallel (new LiftToHeight(10));
			AddSequential (new EjectBox(1));

			if (Robot::SwitchPosition[1]=='L'){
				AddSequential (new TurnAngle(-90,1.0));
				AddSequential (new DriveStraightDistancePID(21,1.0));
				AddSequential (new TurnAngle(0,1.0));
				AddSequential (new DriveStraightDistancePID(21,1.0));
				//I have no idea where to even begin with the picking up boxes command.
				AddSequential (new DriveStraightDistancePID(42,1.0));
				AddSequential (new TurnAngle(90,1.0));
				AddSequential (new EjectBox(1));


			} else{
				if(Robot::SwitchPosition[0]=='R'){
					AddSequential (new TurnAngle(-90,1.0));
					AddSequential (new DriveStraightDistancePID(20,1.0));
					AddSequential (new TurnAngle(0,1.0));
					AddSequential (new DriveStraightDistancePID(40,1.0));
					//insert box grabbing code
					AddSequential (new TurnAngle(90,1.0));
					AddSequential (new DriveStraightDistancePID(40,1.0));
					AddParallel (new LiftToHeight(10));
					AddSequential (new EjectBox(1));
				}
			}
		} 	else {
			AddSequential (new DriveStraightDistancePID(84,1.0));
			AddSequential (new TurnAngle(90,1.0));
			AddSequential (new DriveStraightDistancePID(66,1.0));
			AddSequential (new TurnAngle(0,1.0));
			AddSequential (new DriveStraightDistancePID(48,1.0));
			AddParallel (new LiftToHeight(10));
			AddSequential (new EjectBox(1));
			if(Robot::SwitchPosition[1]=='R'){
				AddSequential (new TurnAngle(90,1.0));;
				AddSequential (new DriveStraightDistancePID(24,1.0));
				AddSequential (new TurnAngle(0,1.0));
				AddSequential (new DriveStraightDistancePID(40,1.0));
				AddSequential (new TurnAngle(-90,1.0));
				AddParallel (new LiftToHeight(40));
				AddSequential (new EjectBox(1));
			} else {
				AddSequential (new TurnAngle(0,1.0));
				AddSequential (new DriveStraightDistancePID(40,1.0));
				AddSequential (new TurnAngle(90,1.0));
				//insert box grabbing code
				AddSequential (new DriveStraightDistancePID(60,1.0));
				AddSequential (new TurnAngle(180,1.0));
				AddSequential (new DriveStraightDistancePID(40,1.0));
				AddParallel (new LiftToHeight(40));
				AddSequential (new EjectBox(1));

			}


		}
		break;
	default:
		AddSequential (new DriveStraightDistancePID(120,1));
		break;

	}
}



// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

