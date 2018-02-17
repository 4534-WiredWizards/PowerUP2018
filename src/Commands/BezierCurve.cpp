#include "BezierCurve.h"
#include "cmath"

BezierCurve::BezierCurve(double P0x, double P0y, double P1x, double P1y, double P2x, double P2y, double P3x, double P3y, int precision, bool relative): frc::Command() {
	Requires(Robot::driveTrain.get());
	m_P0x = P0y;
	m_P0y = P0x;
	m_P1x = P1y;
	m_P1y = P1x;
	m_P2x = P2y;
	m_P2y = P2x;
	m_P3x = P3y;
	m_P3y = P3x;
	m_precision = precision;
	t = 0;
	angle = 0;
	distance = 0;
	m_relative = relative;
}

// Called just before this Command runs the first time
void BezierCurve::Initialize() {
	t = 0;
	angle = 0;
	distance = 0;
}

// Called repeatedly when this Command is scheduled to run
void BezierCurve::Execute() {
	xList[0] = m_P0x + ((m_P1x - m_P0x) * (t / m_precision));
	yList[0] = m_P0y + ((m_P1y - m_P0y) * (t / m_precision));
	xList[1] = m_P1x + ((m_P2x - m_P1x) * (t / m_precision));
	yList[1] = m_P1y + ((m_P2y - m_P1y) * (t / m_precision));
	xList[2] = m_P2x + ((m_P3x - m_P2x) * (t / m_precision));
	yList[2] = m_P2y + ((m_P3y - m_P2y) * (t / m_precision));
	xList[3] = xList[0] + ((xList[1] - xList[0]) * (t / m_precision));
	yList[3] = yList[0] + ((yList[1] - yList[0]) * (t / m_precision));
	xList[4] = xList[1] + ((xList[2] - xList[1]) * (t / m_precision));
	yList[4] = yList[1] + ((yList[2] - yList[1]) * (t / m_precision));
	xList[5] = xList[3] + ((xList[4] - xList[3]) * (t / m_precision));
	yList[5] = yList[3] + ((yList[4] - yList[3]) * (t / m_precision));
	t++;
	if(m_relative == false)
	{
	angle = atan(yList[4] - yList[5]/ xList[4] - xList[5]) - (fmod(Robot::driveTrain->getGyroAngle(), 360) / 360 * 2 * PI);
	}
	else
	{
	angle = atan(yList[4] - yList[5]/ xList[4] - xList[5]);
	}
	if(angle > PI / 2) {
		while(angle > PI / 4) {
			angle = angle - PI;
		}
	}
	if(angle < PI / -2) {
		while(angle < PI / -4) {
			angle = angle + PI;
		}
	}
	if(t > 0) distance = sqrt(pow(xList[6] - xList[5], 2) + pow(yList[6] - yList[5], 2));
	else distance = 0;
	if(!(distance == 0)) {
		// if(angle > 0) Robot::driveTrain->TankDrive(((angle) / 2 * PI) * (distance + 2 * PI * 11.75) / speed, ((angle) / 2 * PI) * (distance - 2 * PI * 11.75) / speed);
		// if(angle < 0) Robot::driveTrain->TankDrive((abs((angle)) / 2 * PI) * (distance - 2 * PI * 11.75) / speed, (abs((angle)) / 2 * PI) * (distance + 2 * PI * 11.75) / speed);
		// if(angle == 0) Robot::driveTrain->TankDrive(1, 1);
		if(angle > 0) Robot::driveTrain->TankDrive(1, ((angle) / 2 * PI) * (distance - 2 * PI * 11.75) / ((angle) / 2 * PI) * (distance + 2 * PI * 11.75));
		if(angle < 0) Robot::driveTrain->TankDrive((abs((angle)) / 2 * PI) * (distance - 2 * PI * 11.75) / (abs((angle)) / 2 * PI) * (distance + 2 * PI * 11.75), 1);
		if(angle == 0) Robot::driveTrain->TankDrive(1, 1);
	}
	while(Robot::driveTrain->getLeftDistanceCounter() + Robot::driveTrain->getRightDistanceCounter() / 2 < distance) { }
	xList[6] = xList[5];
	yList[6] = yList[5];
}

// Make this return true when this Command no longer needs to run execute()
bool BezierCurve::IsFinished() {
	if(t == m_precision + 1) return true;
	else return false;
}

// Called once after isFinished returns true
void BezierCurve::End() {
	Robot::driveTrain->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BezierCurve::Interrupted() {
	Robot::driveTrain->TankDrive(0, 0);
}
