#include "SideAuto.h"
#include "DriveStraightDistancePID.h"
#include "EjectBox.h"
#include "LiftToHeight.h"
#include "TurnAngle.h"
#include "DriveStraightTimed.h"
SideAuto::SideAuto() {
	AddSequential (new DriveStraightTimed(frc::SmartDashboard::GetNumber("Auto Delay",0),0));
	//Robot::SwitchPosition;
	switch(Robot::target){
	case 0:
		//drive forward past line
		AddSequential(new DriveStraightDistancePID(40,.5));
		break;
	case 1:
		//targetingswitch
		//AddSequential(new DriveStraightDistancePID(30,0.5));
		//AddSequential(new TurnAngle(90, 1));

		if(Robot::location=="Left"){
			//the robot is on the left
			if(Robot::SwitchPosition[0]=='L') {
				//robot is on the left and going to the left switch
				AddSequential(new DriveStraightDistancePID(168,.5));
				AddSequential(new  LiftToHeight(10));
				AddSequential(new TurnAngle(90, .5));
				AddSequential(new DriveStraightDistancePID(26,.5));
				AddSequential(new  EjectBox(1));
			}
			else{
				//robot on left going to the right switch
				AddSequential(new DriveStraightDistancePID(70,.5));
				AddSequential(new  LiftToHeight(10));
				AddSequential(new TurnAngle(90, .5));
				AddSequential(new DriveStraightDistancePID(240,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(84,.5));
				AddSequential(new EjectBox(1));
			}
		}
		else{
			//robot is on the right
			if(Robot::SwitchPosition[0]=='R') {
				//robot on right going to right switch
				AddSequential(new DriveStraightDistancePID(168,.5));
				AddSequential(new  LiftToHeight(10));
				AddSequential(new  TurnAngle(-90, .5));
				AddSequential(new  DriveStraightDistancePID(26,.5));
				AddSequential(new EjectBox(1));
			}
			else{
				//robot is on right going to left switch
				AddSequential(new DriveStraightDistancePID(70,.5));
				AddSequential(new LiftToHeight(10));
				AddSequential(new TurnAngle(-90, .5));
				AddSequential(new DriveStraightDistancePID(239.94,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(84,.5));
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
		//targeting the scale
		if (Robot::location=="Right"){
			//the robot is on the right
			if (Robot::SwitchPosition[1]=='R'){
				//robot right going to the right scale
				AddSequential(new DriveStraightDistancePID(260,.5));
				AddSequential(new LiftToHeight(40));
				AddSequential(new TurnAngle(-90, .5));
				AddSequential(new DriveStraightDistancePID(71,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(6,.5));
				AddSequential(new EjectBox(1));
			}
			else{
				//robot is on the right going to the left scale
				AddSequential(new DriveStraightDistancePID(230,.5));
				AddSequential(new LiftToHeight(40));
				AddSequential(new TurnAngle(-90, .5));
				AddSequential(new DriveStraightDistancePID(192,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(38,.5));
				AddSequential(new EjectBox(1));
			}
		}
		else{
			//robot is on the left
			if (Robot::SwitchPosition[1]=='L'){
				//robot is left going to the left scale
				AddSequential(new DriveStraightDistancePID(260,.5));
				AddSequential(new LiftToHeight(40));
				AddSequential(new TurnAngle(90, .5));
				AddSequential(new DriveStraightDistancePID(71,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(6,.5));
				AddSequential(new EjectBox(1));
			}
			else{
				//robot is left going to the right scale
				AddSequential(new DriveStraightDistancePID(230,.5));
				AddSequential(new LiftToHeight(40));
				AddSequential(new TurnAngle(90, .5));
				AddSequential(new DriveStraightDistancePID(192.5,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(37.65,.5));
				AddSequential(new EjectBox(1));
			}
		}

		break;
	case 3:
		//switch scale
		if(Robot::SwitchPosition[0]=='L'){
			//the switch is on the left
			if(Robot::location=="Left") {
				//the switch is on the left and we are on the left
				AddSequential(new DriveStraightDistancePID(168,.5));
				AddSequential(new  LiftToHeight(10));
				AddSequential(new TurnAngle(90, .5));
				AddSequential(new DriveStraightDistancePID(26.06,.5));
				AddSequential(new  EjectBox(1));
				AddSequential(new DriveStraightDistancePID(-26.06,.5));
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new LiftToHeight(0));
			}
			else{
				//the switch is on the left and we are on the right
				AddSequential(new DriveStraightDistancePID(70,.5));
				AddSequential(new LiftToHeight(10));
				AddSequential(new TurnAngle(-90, .5));
				AddSequential(new DriveStraightDistancePID(240,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(84,.5));
				AddSequential(new EjectBox(1));
				AddSequential(new DriveStraightDistancePID(-84,.5));
				AddSequential(new TurnAngle(-90,1));
				AddSequential(new DriveStraightDistancePID(24,.5));
				AddSequential(new TurnAngle(0,1));
				AddSequential(new DriveStraightDistancePID(89,.5));
				AddSequential(new LiftToHeight(0));
			}
			//goes form the left switch to the scale
			if(Robot::SwitchPosition[1]=='L'){
				//going from the left switch to the left scale
				AddSequential(new DriveStraightDistancePID(82,.5));
				AddSequential(new TurnAngle(90,.5));
				AddSequential(new DriveStraightDistancePID(71,.5));
				//insert box grabbing code here
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new DriveStraightDistancePID(50,.5));
				AddSequential(new EjectBox(1));
			}
			else{
				//going from the left switch to the right scale
				AddSequential(new DriveStraightDistancePID(82,.5));
				AddSequential(new TurnAngle(90,.5));
				AddSequential(new DriveStraightDistancePID(71,.5));
				//insert box grabbing code here
				AddSequential(new DriveStraightDistancePID(121,.5));
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new DriveStraightDistancePID(50,.5));
				AddSequential(new EjectBox(1));
			}
		}
		else{
			//The switch is on the right
			if(Robot::location=="Right") {
				//the switch is on the right and the robot is on the right
				AddSequential(new DriveStraightDistancePID(168,.5));
				AddSequential(new  LiftToHeight(10));
				AddSequential(new TurnAngle(-90, .5));
				AddSequential(new DriveStraightDistancePID(26.06,.5));
				AddSequential(new  EjectBox(1));
				AddSequential(new DriveStraightDistancePID(-26.06,.5));
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new LiftToHeight(0));
			}
			else{
				//the switch is on the right and the robot is on the left
				AddSequential(new DriveStraightDistancePID(70,.5));
				AddSequential(new LiftToHeight(10));
				AddSequential(new TurnAngle(90, .5));
				AddSequential(new DriveStraightDistancePID(240,.5));
				AddSequential(new TurnAngle(0, .5));
				AddSequential(new DriveStraightDistancePID(84,.5));
				AddSequential(new EjectBox(1));
				AddSequential(new DriveStraightDistancePID(-84,.5));
				AddSequential(new TurnAngle(90,.5));
				AddSequential(new DriveStraightDistancePID(24,.5));
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new DriveStraightDistancePID(89,.5));
				AddSequential(new LiftToHeight(0));
			}
			//goes from switch right to scale
			if(Robot::SwitchPosition[1]=='L'){
				//going from the right switch to the left scale
				AddSequential(new DriveStraightDistancePID(82,.5));
				AddSequential(new TurnAngle(-90,.5));
				AddSequential(new DriveStraightDistancePID(71,.5));
				//insert box grabbing code here
				AddSequential(new DriveStraightDistancePID(121,.5));
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new DriveStraightDistancePID(50,.5));
				AddSequential(new EjectBox(1));
			}
			else{
				//going from the right switch to the right scale
				AddSequential(new DriveStraightDistancePID(82,.5));
				AddSequential(new TurnAngle(-90,.5));
				AddSequential(new DriveStraightDistancePID(71,.5));
				//insert box grabbing code here
				AddSequential(new TurnAngle(0,.5));
				AddSequential(new DriveStraightDistancePID(50,.5));
				AddSequential(new EjectBox(1));
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
