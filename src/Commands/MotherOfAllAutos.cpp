#include "MotherOfAllAutos.h"
#include "DriveStraightDistance.h"
#include "EjectBox.h"
#include "EjectBoxTimed.h"
#include "IntakeBox.h"
#include "LiftToHeight.h"
#include "TurnAnglePID.h"
#include "BezierCurve.h"
#include "GoToThing.h"
#include "VisionTest.h"
/*
 * Mother auto is best auto
 */
MotherOfAllAutos::MotherOfAllAutos(int offset) {
	AddSequential(new DriveStraightDistance(50,1));
	if(offset > 0)
	{
		AddSequential(new TurnAnglePID(-90, 0.5, true));
	}
	if(offset == 0)
	{
		//yo fam do nothing here it finna be good. but robot shouldnt be here tho. peace lit fam
	}
	if(offset < 0)
	{
		AddSequential(new TurnAnglePID(90, 0.5, true));
	}
	AddSequential(new DriveStraightDistance(abs(offset), 0.5));
	AddSequential(new TurnAnglePID(0, 0.5, true));
	switch(Robot::target){
		case 0:
			AddSequential(new DriveStraightDistance(100, 0.5));
			break;
		case 1:
			if(Robot::SwitchPosition[0]=='L')
			{
				multiplier = 1;
			}
			else
			{
				multiplier = -1;
			}
			AddSequential(new TurnAnglePID(multiplier * -90, 0.5, true));
			AddSequential(new BezierCurve(0, 0, multiplier * 170, 0, multiplier * 170, 100, multiplier * 130, 100, 40, false));
			AddSequential(new VisionTest("switch"));
			AddSequential(new LiftToHeight(17));
			AddSequential(new GoToThing(false));
			AddSequential(new EjectBoxTimed(1.5, 0.5));
			break;
		case 2:
			if(Robot::SwitchPosition[1]=='L')
			{
				multiplier = 1;
			}
			else
			{
				multiplier = -1;
			}
			AddSequential(new TurnAnglePID(multiplier * -90, 0.5, true));
			AddSequential(new LiftToHeight(40));
		    AddSequential(new BezierCurve(0, 0, multiplier * 170, 0, multiplier * 170, 270, multiplier * 130, 270, 60, false));
		    AddSequential(new EjectBoxTimed(1.5, 0.5));
			break;
		case 3:
			if(Robot::SwitchPosition[0]=='L')
			{
				multiplier = 1;
			}
			else
			{
				multiplier = -1;
			}
			AddSequential(new TurnAnglePID(multiplier * -90, 0.5, true));
			AddSequential(new BezierCurve(0, 0, multiplier * 170, 0, multiplier * 170, 100, multiplier * 130, 100, 40, false));
			AddSequential(new VisionTest("switch"));
			AddSequential(new LiftToHeight(17));
			AddSequential(new GoToThing(false));
			AddSequential(new EjectBoxTimed(1.5, 0.5));
			//lift and put cube (switch)
			AddSequential(new DriveStraightDistance(-50, 0.5));
			AddSequential(new TurnAnglePID(multiplier * -90, 0.5, true));
			AddSequential(new BezierCurve(0, 0, 0, 90, multiplier * -60, 90, multiplier * -60, 60, 20, false));
			AddSequential(new VisionTest("cube"));
			AddSequential(new GoToThing(false));
			//pick up cube here
			AddSequential(new DriveStraightDistance(-30, 0.5));
			break;
			if(Robot::SwitchPosition[1] == Robot::SwitchPosition[0])
			{
				AddSequential(new TurnAnglePID(multiplier * 90, 0.5, false));
				AddSequential(new LiftToHeight(40));
				AddSequential(new BezierCurve(0, 0, multiplier * -250, 0, multiplier * -250, 100, multiplier * -180, 100, 60, false));
			}
			else
			{
				AddSequential(new TurnAnglePID(multiplier * -90, 0.5, false));
				AddSequential(new LiftToHeight(40));
				AddSequential(new BezierCurve(0, 0, multiplier * 100, 0, multiplier * 100, 110, multiplier * 55, 110, 60, false));
			}
			AddSequential(new EjectBoxTimed(1.5, 0.5));
	}
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
