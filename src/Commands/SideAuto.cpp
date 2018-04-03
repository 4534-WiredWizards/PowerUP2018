#include "SideAuto.h"
#include "DriveStraightDistancePID.h"
#include "EjectBoxTimed.h"
#include "LiftToHeightAuto.h"
#include "LiftToHeightAuto.h"
#include "RaiseBoxHandler.h"
#include "LowerBoxHandler.h"
#include "TurnAnglePID.h"
#include "DriveStraightTimed.h"
#include "ResetGyro.h"
#include "IntakeDrop.h"
#include "IntakeGrab.h"


SideAuto::SideAuto() {
	AddSequential (new DriveStraightTimed(frc::SmartDashboard::GetNumber("Auto Delay",0),0));
	AddSequential (new ResetGyro());
	//Robot::SwitchPosition;
	switch(Robot::target){
	case 0:
		//drive forward past line
		//		AddSequential(new DriveStraightDistancePID(120,1.0));

		AddSequential(new DriveStraightTimed(1.0, 0.9));

		if((Robot::SwitchPosition[0] == 'L' && Robot::location=="Left") || (Robot::SwitchPosition[0] == 'R' && Robot::location=="Right")){
			AddParallel(new DriveStraightTimed(2.0, 0.6));
			AddSequential( new LiftToHeightAuto(20));
			AddSequential(new LowerBoxHandler());
			AddSequential(new DriveStraightTimed(0.2, 0));
			AddSequential (new EjectBoxTimed(0.2,0.4));
			AddSequential (new IntakeDrop());
			AddSequential(new DriveStraightTimed(0.5, 0));
		} else {
			AddSequential(new DriveStraightTimed(2.0, 0.5));
			AddParallel( new LiftToHeightAuto(20));
			AddSequential(new DriveStraightTimed(3.0, -0.5));
		}
		AddSequential(new DriveStraightTimed(0.5, -0.5));
		AddSequential(new LiftToHeightAuto(0));
		AddSequential(new IntakeGrab());
		break;
	case 1:
		//targeting switch
		//AddSequential(new DriveStraightDistancePID(30,01.0));
		//AddSequential(new TurnAnglePID(90, 1));

		if(Robot::location=="Left"){
			//the robot is on the left
			if(Robot::SwitchPosition[0]=='L') {
				//robot is on the left and going to the left switch
				AddSequential(new DriveStraightDistancePID(168,1.0));
				AddParallel(new  LiftToHeightAuto(17));
				AddSequential(new TurnAnglePID(90, 1.0));
				AddSequential(new DriveStraightDistancePID(26,1.0));
				AddSequential (new LowerBoxHandler(), 0.1);
				AddSequential(new  EjectBoxTimed(1.5, 0.4));
				AddSequential (new RaiseBoxHandler());
			}
			else{
				//robot on left going to the right switch
				AddSequential(new DriveStraightDistancePID(30,1.0));
				AddParallel(new  LiftToHeightAuto(17));
				AddSequential(new TurnAnglePID(90, 1.0));
				AddSequential(new DriveStraightDistancePID(240,1.0));
				AddSequential(new TurnAnglePID(0, 1.0));
				AddSequential(new DriveStraightDistancePID(124,1.0));
				AddSequential (new LowerBoxHandler(), 0.1);
				AddSequential(new EjectBoxTimed(1.5, 0.4));
				AddSequential (new RaiseBoxHandler());
			}
		}
		else{
			//robot is on the right
			if(Robot::SwitchPosition[0]=='R') {
				//robot on right going to right switch
				AddSequential(new DriveStraightDistancePID(168,1.0));
				AddParallel(new  LiftToHeightAuto(17));
				AddSequential(new  TurnAnglePID(270, 1.0));
				AddSequential(new  DriveStraightDistancePID(26,1.0));
				AddSequential (new LowerBoxHandler(), 0.1);
				AddSequential(new EjectBoxTimed(1.5, 0.4));
				AddSequential (new RaiseBoxHandler());
			}
			else{
				//robot is on right going to left switch
				AddSequential(new DriveStraightDistancePID(30,1.0));
				AddParallel(new LiftToHeightAuto(17));
				AddSequential(new TurnAnglePID(270, 1.0));
				AddSequential(new DriveStraightDistancePID(239.94,1.0));
				AddSequential(new TurnAnglePID(0, 1.0));
				AddSequential(new DriveStraightDistancePID(124,1.0));
				AddSequential (new LowerBoxHandler(), 0.1);
				AddSequential(new EjectBoxTimed(1.5, 0.4));
				AddSequential (new RaiseBoxHandler());
			}
		}
		AddSequential(new DriveStraightTimed(0.5, -0.5));
		AddSequential(new LiftToHeightAuto(0));
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
				AddSequential(new DriveStraightDistancePID(270,1.0));
//				AddParallel(new LiftToHeightAuto(40));
//				AddSequential(new TurnAnglePID(270, 1.0));
//				AddSequential(new DriveStraightDistancePID(71,1.0));
//				AddSequential(new TurnAnglePID(0, 1.0));
//				AddSequential (new TurnAnglePID(270.0,1.0), 1.0);

//				AddSequential(new DriveStraightDistancePID(6,1.0));
//				AddSequential(new EjectBoxTimed(1.5, 1.0));
			}
			else{
				//robot is on the right going to the left scale
				AddSequential(new DriveStraightDistancePID(250,1.0));
//				AddParallel(new LiftToHeightAuto(40));
				AddSequential(new TurnAnglePID(270, 2.0));
				AddSequential(new DriveStraightDistancePID(192,1.0));
				AddSequential(new TurnAnglePID(0, 2.0));
//				AddSequential(new DriveStraightDistancePID(38,1.0));
//				AddSequential(new EjectBoxTimed(1.5, 1.0));
			}
		}
		else{
			//robot is on the left
			if (Robot::SwitchPosition[1]=='L'){
				//robot is left going to the left scale
				AddSequential(new DriveStraightDistancePID(260,1.0));
//				AddParallel(new LiftToHeightAuto(40));
				AddSequential(new TurnAnglePID(90, 1.0));
				AddSequential(new DriveStraightDistancePID(71,1.0));
				AddSequential(new TurnAnglePID(0, 1.0));
				AddSequential(new DriveStraightDistancePID(6,1.0));
//				AddSequential(new EjectBoxTimed(1.5, 1.0));
			}
			else{
				//robot is left going to the right scale
				AddSequential(new DriveStraightDistancePID(230,1.0));
//				AddParallel(new LiftToHeightAuto(40));
				AddSequential(new TurnAnglePID(90, 1.0));
				AddSequential(new DriveStraightDistancePID(192.5,1.0));
				AddSequential(new TurnAnglePID(0, 1.0));
				AddSequential(new DriveStraightDistancePID(37.65,1.0));
//				AddSequential(new EjectBoxTimed(1.5, 0.5));
			}
		}
//		AddSequential (new RaiseBoxHandler());
//		AddSequential(new DriveStraightTimed(0.5, -0.5));
//		AddSequential(new LiftToHeightAuto(0));
		break;
	case 3:
		//switch scale
		if(Robot::SwitchPosition[0]=='L'){
			//the switch is on the left
			if(Robot::location=="Left") {
				//the switch is on the left and we are on the left
				AddSequential(new DriveStraightDistancePID(168,1.0));
				AddParallel(new  LiftToHeightAuto(24));
				AddSequential(new TurnAnglePID(90, 1.0));
				AddSequential(new DriveStraightDistancePID(26.06,1.0));
				AddSequential(new  EjectBoxTimed(1.5, 1.0));
				AddSequential(new DriveStraightDistancePID(-26.06,1.0));
				AddSequential(new TurnAnglePID(0,1.0));
				AddParallel(new LiftToHeightAuto(0));
			}
			else{
				//the switch is on the left and we are on the right
				AddSequential(new DriveStraightDistancePID(70,1.0));
				AddParallel(new LiftToHeightAuto(24));
				AddSequential(new TurnAnglePID(270, 1.0));
				AddSequential(new DriveStraightDistancePID(240,1.0));
				AddSequential(new TurnAnglePID(0, 1.0));
				AddSequential(new DriveStraightDistancePID(84,1.0));
				AddSequential(new EjectBoxTimed(1.5, 1.0));
				AddSequential(new DriveStraightDistancePID(-84,1.0));
				AddSequential(new TurnAnglePID(270,1));
				AddSequential(new DriveStraightDistancePID(24,1.0));
				AddSequential(new TurnAnglePID(0,1));
				AddSequential(new DriveStraightDistancePID(89,1.0));
				AddParallel(new LiftToHeightAuto(0));
			}
			//goes form the left switch to the scale
			if(Robot::SwitchPosition[1]=='L'){
				//going from the left switch to the left scale
				AddSequential(new DriveStraightDistancePID(82,1.0));
				AddSequential(new TurnAnglePID(90,1.0));
				AddSequential(new DriveStraightDistancePID(71,1.0));
				//insert box grabbing code here
				AddSequential(new TurnAnglePID(0,1.0));
				AddSequential(new DriveStraightDistancePID(50,1.0));
				AddSequential(new EjectBoxTimed(1.5, 1.0));
			}
			else{
				//going from the left switch to the right scale
				AddSequential(new DriveStraightDistancePID(82,1.0));
				AddSequential(new TurnAnglePID(90,1.0));
				AddSequential(new DriveStraightDistancePID(71,1.0));
				//insert box grabbing code here
				AddSequential(new DriveStraightDistancePID(121,1.0));
				AddSequential(new TurnAnglePID(0,1.0));
				AddSequential(new DriveStraightDistancePID(50,1.0));
				AddSequential(new EjectBoxTimed(1.5, 1.0));
			}
		}
		else{
			//The switch is on the right
			if(Robot::location=="Right") {
				//the switch is on the right and the robot is on the right
				AddSequential(new DriveStraightDistancePID(168,1.0));
				AddParallel(new  LiftToHeightAuto(24));
				AddSequential(new TurnAnglePID(270, 1.0));
				AddSequential(new DriveStraightDistancePID(26.06,1.0));
				AddSequential(new  EjectBoxTimed(1.5, 1.0));
				AddSequential(new DriveStraightDistancePID(-26.06,1.0));
				AddSequential(new TurnAnglePID(0,1.0));
				AddParallel(new LiftToHeightAuto(0));
			}
			else{
				//the switch is on the right and the robot is on the left
				AddSequential(new DriveStraightDistancePID(70,1.0));
				AddParallel(new LiftToHeightAuto(24));
				AddSequential(new TurnAnglePID(90, 1.0));
				AddSequential(new DriveStraightDistancePID(240,1.0));
				AddSequential(new TurnAnglePID(0, 1.0));
				AddSequential(new DriveStraightDistancePID(84,1.0));
				AddSequential(new EjectBoxTimed(1.5, 1.0));
				AddSequential(new DriveStraightDistancePID(-84,1.0));
				AddSequential(new TurnAnglePID(90,1.0));
				AddSequential(new DriveStraightDistancePID(24,1.0));
				AddSequential(new TurnAnglePID(0,1.0));
				AddSequential(new DriveStraightDistancePID(89,1.0));
				AddParallel(new LiftToHeightAuto(0));
			}
			//goes from switch right to scale
			if(Robot::SwitchPosition[1]=='L'){
				//going from the right switch to the left scale
				AddSequential(new DriveStraightDistancePID(82,1.0));
				AddSequential(new TurnAnglePID(270,1.0));
				AddSequential(new DriveStraightDistancePID(71,1.0));
				//insert box grabbing code here
				AddSequential(new DriveStraightDistancePID(121,1.0));
				AddSequential(new TurnAnglePID(0,1.0));
				AddSequential(new DriveStraightDistancePID(50,1.0));
				AddSequential(new EjectBoxTimed(1.5, 1.0));
			}
			else{
				//going from the right switch to the right scale
				AddSequential(new DriveStraightDistancePID(82,1.0));
				AddSequential(new TurnAnglePID(270,1.0));
				AddSequential(new DriveStraightDistancePID(71,1.0));
				//insert box grabbing code here
				AddSequential(new TurnAnglePID(0,1.0));
				AddSequential(new DriveStraightDistancePID(50,1.0));
				AddSequential(new EjectBoxTimed(1.5, 1.0));
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
