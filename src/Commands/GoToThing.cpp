#include "../Robot.h"
#include "cmath"
#include "DriveStraightDistancePID.h"
#include "DriveStraightDistance.h"
#include "TurnAnglePID.h"
#include "TurnAngle.h"
#include "BezierCurve.h"
#include "GoToThing.h"
#include "IntakeBox.h"


GoToThing::GoToThing(std::string thing, bool rewind) {
	Requires(Robot::driveTrain.get());
	Robot::jetsonVision->SetTarget(thing);
	while(Robot::jetsonVision->GetDistanceToTarget(Robot::jetsonVision->GetTarget()) == -12345 || Robot::jetsonVision->GetAngleToTarget(Robot::jetsonVision->GetTarget()) == -12345)
	{
		m_dist = Robot::jetsonVision->GetDistanceToTarget(Robot::jetsonVision->GetTarget());
		m_angle = Robot::jetsonVision->GetAngleToTarget(Robot::jetsonVision->GetTarget());
	}
	m_rewind = rewind;
	opposite = 0;
	adjacent = 0;
	opposite = m_dist * sin((m_angle));
	adjacent = m_dist * sin(PI / 2 - (m_angle));
	AddParallel (new IntakeBox(5));
	AddSequential (new BezierCurve(0, 0, 0, adjacent / 2, opposite, adjacent / 2, opposite, adjacent, m_dist, true));
	if(m_rewind == true)
	{
		AddSequential (new DriveStraightDistance(-adjacent, 0.75));
		if(m_angle > 0)
		{
			AddSequential (new TurnAngle(-90, 0.75));
		}
		else
		{
			AddSequential (new TurnAngle(90, 0.75));
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
