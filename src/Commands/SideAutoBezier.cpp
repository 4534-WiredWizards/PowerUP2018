#include "SideAutoBezier.h"
#include "DriveStraightDistance.h"
#include "EjectBox.h"
#include "LiftToHeight.h"
#include "TurnAngle.h"
#include "BezierCurve.h"

SideAutoBezier::SideAutoBezier() {
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
			//Robot starts on left and goes to left side of the switch
			if(Robot::SwitchPosition[1]=='L') {
				//AddSequential(new DriveStraightDistance(168,1));
				//AddSequential(new  LiftToHeight(10));
				//AddSequential(new TurnAngle(90, 1));
				//AddSequential(new DriveStraightDistance(26.06,1));
				//AddSequential(new  EjectBox(1));
				AddSequential (new BezierCurve(0,0,-20,70,-20,255,60,0));
				AddSequential(new  LiftToHeight(10));
				AddSequential(new  EjectBox(1));
				//Robot on left to right side of switch
			}
			else{
				//AddSequential(new DriveStraightDistance(70,1));
				//AddSequential(new  LiftToHeight(10));
				//AddSequential(new TurnAngle(90, 1));
				//AddSequential(new DriveStraightDistance(239.94,1));
				//AddSequential(new TurnAngle(0, 1));
				//AddSequential(new DriveStraightDistance(84,1));
				//AddSequential(new EjectBox(1));
				AddSequential(new BezierCurve(0,0,0,60,140,70,150,60));
				AddSequential(new BezierCurve(0,0,43,98,43,168,10,168));
				AddSequential(new LiftToHeight(10));
				AddSequential(new EjectBox(1));
			}
		}  //robot on right to right side of switch
		else{
			if(Robot::SwitchPosition[1]=='R') {
				//AddSequential(new DriveStraightDistance(168,1));
				//AddSequential(new  LiftToHeight(10));
				//AddSequential(new  TurnAngle(-90, 1));
				//AddSequential(new  DriveStraightDistance(26.06,1));
				//AddSequential(new EjectBox(1));
				AddSequential(new BezierCurve(0,0,20,70,20,255,-60,0));
				AddSequential(new LiftToHeight(10));
				AddSequential(new EjectBox(1));
			}
			//robot on right to left side of switch
			else{
				//AddSequential(new DriveStraightDistance(70,1));
				//AddSequential(new LiftToHeight(10));
				//AddSequential(new TurnAngle(-90, 1));
				//AddSequential(new DriveStraightDistance(239.94,1));
				//AddSequential(new TurnAngle(0, 1));
				//AddSequential(new DriveStraightDistance(84,1));
				//AddSequential(new EjectBox(1));
				AddSequential(new BezierCurve(0,0,0,60,-140,70,-150,60));
				AddSequential(new BezierCurve(0,0,-43,98,-43,168,-10,168));
				AddSequential(new LiftToHeight(10));
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
			//robot on right to right side of scale
			if (Robot::SwitchPosition[1]=='R'){
				//AddSequential(new DriveStraightDistance(261.47,1));
				//AddSequential(new LiftToHeight(40));
				//AddSequential(new TurnAngle(-90, 1));
				//AddSequential(new DriveStraightDistance(71.5,1));
				//AddSequential(new TurnAngle(0, 1));
				//AddSequential(new DriveStraightDistance(6,1));
				//AddSequential(new EjectBox(1));
				AddSequential(new BezierCurve(0,0,40,120,40,260,20,324));
				AddSequential(new LiftToHeight(40));
				AddSequential(new EjectBox(1));
			}
			//robot on right to left side of scale
			else{
				//AddSequential(new DriveStraightDistance(230,1));
				//AddSequential(new LiftToHeight(40));
				//AddSequential(new TurnAngle(90, 1));
				//AddSequential(new DriveStraightDistance(192.5,1));
				//AddSequential(new TurnAngle(0, 1));
				//AddSequential(new DriveStraightDistance(37.65,1));
				//AddSequential(new EjectBox(1));
				AddSequential(new BezierCurve(0,0,40,120,40,230,-14,230));
				AddSequential(new DriveStraightDistance(130,1));
				AddSequential(new BezierCurve(0,0,-60,40,-60,94,21,94));
				AddSequential(new LiftToHeight(40));
				AddSequential(new EjectBox(1));
			}
		}
		else{
			if (Robot::target==2){
				//robot on left to left side of scale
				if (Robot::SwitchPosition[1]=='L'){
					//AddSequential(new DriveStraightDistance(261.47,1));
					//AddSequential(new LiftToHeight(40));
					//AddSequential(new TurnAngle(90, 1));
					//AddSequential(new DriveStraightDistance(71.5,1));
					//AddSequential(new TurnAngle(0, 1));
					//AddSequential(new DriveStraightDistance(6,1));
					//AddSequential(new EjectBox(1));
					AddSequential(new BezierCurve(0,0,-45,120,-45,260,-20,324));
					AddSequential(new LiftToHeight(40));
					AddSequential(new EjectBox(1));
				}
				//robot on left to right side of scale
				else{
					//AddSequential(new DriveStraightDistance(230,1));
					//AddSequential(new LiftToHeight(40));
					//AddSequential(new TurnAngle(90, 1));
					//AddSequential(new DriveStraightDistance(192.5,1));
					//AddSequential(new TurnAngle(0, 1));
					//AddSequential(new DriveStraightDistance(37.65,1));
					//AddSequential(new EjectBox(1));
					AddSequential(new BezierCurve(0,0,-40,120,-40,230,14,230));
					AddSequential(new DriveStraightDistance(130,1));
					AddSequential(new BezierCurve(0,0,60,40,60,94,-21,94));
					AddSequential(new LiftToHeight(40));
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
