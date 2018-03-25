#include "../Robot.h"
#include "cmath"
#include "DriveStraightDistancePID.h"
#include "DriveStraightDistance.h"
#include "TurnAnglePID.h"
#include "TurnAngle.h"
#include "BezierCurve.h"
#include "GoToThing.h"
#include "IntakeBoxAuto.h"
#include "LiftToHeight.h"

GoToThing::GoToThing(bool rewind) {
	Requires(Robot::driveTrain.get());
	m_rewind = rewind;
	opposite = 0;
	adjacent = 0;
	m_dist = Robot::jetsonVision->GetDistanceToTarget(Robot::jetsonVision->GetTarget());
	m_angle = Robot::jetsonVision->GetAngleToTarget(Robot::jetsonVision->GetTarget());
	opposite = m_dist * sin((m_angle));
	adjacent = m_dist * sin(PI / 2 - (m_angle));
	AddParallel (new IntakeBoxAuto(.7));
	AddParallel (new LiftToHeight(1.6));
	AddSequential (new BezierCurve(0, 0, 0, adjacent / 2, opposite, adjacent / 2, opposite, adjacent, m_dist, true));
	if(m_rewind == true)
	{
		AddSequential (new DriveStraightDistance(-adjacent, 0.75));
		if(m_angle > 0)
		{
			AddSequential (new TurnAnglePID(-90, 0.75, false));
		}
		else
		{
			AddSequential (new TurnAnglePID(90, 0.75, false));
		}
		AddSequential (new DriveStraightDistance(-opposite, 0.75));

	}
	/*AddSequential (new DriveStraightDistance(adjacent / 2, 0.75));
	if(m_angle > 0) AddSequential (new TurnAngle(90, 0.75));
	else AddSequential (new TurnAngle(-90, 0.75));
	AddSequential (new DriveStraightDistance(opposite, 0.75));
	if(m_angle > 0) AddSequential (new TurnAngle(-90, 0.75));
	else AddSequential (new TurnAngle(90, 0.75));
	AddSequential (new DriveStraightDistance(adjacent / 2, 0.75));*/
}
