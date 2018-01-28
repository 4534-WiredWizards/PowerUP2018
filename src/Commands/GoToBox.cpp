#include "../Robot.h"
#include "GoToBox.h"
#include "cmath"
#include "DriveStraightDistancePID.h"
#include "DriveStraightDistance.h"
#include "TurnAnglePID.h"
#include "TurnAngle.h"


GoToBox::GoToBox(int dist, int angle, bool rewind) {
	Requires(Robot::driveTrain.get());
	m_dist = dist;
	m_angle = angle / (360) * 2 * PI;
	m_rewind = rewind;
	opposite = 0;
	adjacent = 0;
	opposite = m_dist * sin(abs(m_angle));
	adjacent = m_dist * sin(PI / 2 - abs(m_angle));
	AddSequential (new DriveStraightDistance(adjacent / 2, 0.75));
	if(m_angle > 0) AddSequential (new TurnAngle(90, 0.75));
	else AddSequential (new TurnAngle(-90, 0.75));
	AddSequential (new DriveStraightDistance(opposite, 0.75));
	if(m_angle > 0) AddSequential (new TurnAngle(-90, 0.75));
	else AddSequential (new TurnAngle(90, 0.75));
	AddSequential (new DriveStraightDistance(adjacent / 2, 0.75));
}
