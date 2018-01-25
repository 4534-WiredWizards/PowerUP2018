#include "SideAuto.h"
#include "DriveStraightDistance.cpp"
#include "EjectBox.cpp"
#include "LiftToHeight.cpp"
#include "TurnAngle.cpp"

SideAuto::SideAuto() {
	//Robot::SwitchPosition;
switch(Robot::target){
 case 0:
	//drive forward past line
	 AddSequential(new DriveStraightDistance(40,1));
	break;
 case 1:
	 //AddSequential(new DriveStraightDistance(30,0.5));
	 //AddSequential(new TurnAngle(90, 1));

	 if(Robot::location=="Left"){

			 if(Robot::SwitchPosition[1]=='L') {
				 AddSequential(new DriveStraightDistance(168,1));
				 AddSequential(new  LiftToHeight(10));
				 AddSequential(new TurnAngle(90, 1));
				 AddSequential(new DriveStraightDistance(26.06,1));
				 AddSequential(new  EjectBox(1));

			 }
			 else{
				 AddSequential(new DriveStraightDistance(70,1));
				 AddSequential(new  LiftToHeight(10));
				 AddSequential(new TurnAngle(90, 1));
				 AddSequential(new DriveStraightDistance(239.94,1));
				 AddSequential(new TurnAngle(0, 1));
				 AddSequential(new DriveStraightDistance(84,1));
				 AddSequential(new EjectBox(1));
			 }
	 }
else{
			 if(Robot::SwitchPosition[1]=='R') {
				 AddSequential(new DriveStraightDistance(168,1));
				 AddSequential(new  LiftToHeight(10));
				 AddSequential(new  TurnAngle(-90, 1));
				 AddSequential(new  DriveStraightDistance(26.06,1));
				 AddSequential(new EjectBox(1));
			 }
			 else{
				 AddSequential(new DriveStraightDistance(70,1));
				 AddSequential(new LiftToHeight(10));
				 AddSequential(new TurnAngle(-90, 1));
				 AddSequential(new DriveStraightDistance(239.94,1));
				 AddSequential(new TurnAngle(0, 1));
				 AddSequential(new DriveStraightDistance(84,1));
				 AddSequential(new EjectBox(1));
			 }
		}
			 break;

	 //switch('Robot::SwitchPosition[0]' + 'Robot::SwitchPosition[1]'){
	 	// case("LL"):
	 		//go to left on switch

	 		//break;
	 	 //case("LR"):
		 	 //go to left switch then right scale
		    //break;
	 	 //case("RL"):
		 	 //go to right switch then left scale
		   // break;
	 	 //case("RR"):
		 	 //go to right switch then right scale
		   // break;
	 //}
	 //break;
	 case 2:
		 if (Robot::target==2){
					 if (Robot::SwitchPosition[1]=='R'){
						AddSequential(new DriveStraightDistance(261.47,1));
						AddSequential(new LiftToHeight(40));
						AddSequential(new TurnAngle(-90, 1));
						AddSequential(new DriveStraightDistance(71.5,1));
						AddSequential(new TurnAngle(0, 1));
						AddSequential(new DriveStraightDistance(6,1));
						AddSequential(new EjectBox(1));
					 }
					 else{
						 AddSequential(new DriveStraightDistance(230,1));
						 AddSequential(new LiftToHeight(40));
						 AddSequential(new TurnAngle(90, 1));
						 AddSequential(new DriveStraightDistance(192.5,1));
						 AddSequential(new TurnAngle(0, 1));
						AddSequential(new DriveStraightDistance(37.65,1));
						AddSequential(new EjectBox(1));
					 }
				 }
				 else{
					 if (Robot::target==2){
								 if (Robot::SwitchPosition[1]=='L'){
									 AddSequential(new DriveStraightDistance(261.47,1));
									 AddSequential(new LiftToHeight(40));
									 AddSequential(new TurnAngle(90, 1));
									 AddSequential(new DriveStraightDistance(71.5,1));
									 AddSequential(new TurnAngle(0, 1));
									 AddSequential(new DriveStraightDistance(6,1));
									 AddSequential(new EjectBox(1));
								 }
								 else{
									 AddSequential(new DriveStraightDistance(230,1));
									 AddSequential(new LiftToHeight(40));
									 AddSequential(new TurnAngle(90, 1));
									 AddSequential(new DriveStraightDistance(192.5,1));
									 AddSequential(new TurnAngle(0, 1));
									 AddSequential(new DriveStraightDistance(37.65,1));
									 AddSequential(new EjectBox(1));
								 }
							 }
				 }

		 break;
 default:
	 //send message that something is wrong!
	 break;
}






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
}
