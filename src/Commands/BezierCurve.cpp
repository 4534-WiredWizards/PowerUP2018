#include "BezierCurve.h"
#include "cmath"

BezierCurve::BezierCurve(int P0x, int P0y, int P1x, int P1y, int P2x, int P2y, int P3x, int P3y): frc::Command() {
	Requires(Robot::driveTrain.get());
	m_P0x = P0x;
	m_P0y = P0y;
	m_P1x = P1x;
	m_P1y = P1y;
	m_P2x = P2x;
	m_P2y = P2y;
	m_P3x = P3x;
	m_P3y = P3y;
	t = 0;
	angle = 0;
	distance = 0;
}

// Called just before this Command runs the first time
void BezierCurve::Initialize() {
	t = 0;
	angle = 0;
	distance = 0;
}

// Called repeatedly when this Command is scheduled to run
void BezierCurve::Execute() {
	xList[0] = m_P0x + ((m_P1x - m_P0x) * (t / 100));
	yList[0] = m_P0y + ((m_P1y - m_P0y) * (t / 100));
	xList[1] = m_P1x + ((m_P2x - m_P1x) * (t / 100));
	yList[1] = m_P1y + ((m_P2y - m_P1y) * (t / 100));
	xList[2] = m_P2x + ((m_P3x - m_P2x) * (t / 100));
	yList[2] = m_P2y + ((m_P3y - m_P2y) * (t / 100));
	xList[3] = xList[0] + ((xList[1] - xList[0]) * (t / 100));
	yList[3] = yList[0] + ((yList[1] - yList[0]) * (t / 100));
	xList[4] = xList[1] + ((xList[2] - xList[1]) * (t / 100));
	yList[4] = yList[1] + ((yList[2] - yList[1]) * (t / 100));
	xList[5] = xList[3] + ((xList[4] - xList[3]) * (t / 100));
	yList[5] = yList[3] + ((yList[4] - yList[3]) * (t / 100));
	t++;
	angle = atan(yList[4] - yList[5]/ xList[4] - xList[5]) - (fmod(Robot::driveTrain->getGyroAngle(), 360) / 360 * 2 * PI);
	if(t > 0) distance = sqrt(pow(xList[6] - xList[5], 2) + pow(yList[6] - yList[5], 2));
	else distance = 0;
	while(Robot::driveTrain->getLeftDistanceCounter() + Robot::driveTrain->getRightDistanceCounter() / 2 < distance) {
		if(angle > 0) Robot::driveTrain->TankDrive(((angle) / 2 * PI) * (distance + 2 * PI * 11.75) / speed, ((angle) / 2 * PI) * (distance - 2 * PI * 11.75) / speed);
		if(angle < 0) Robot::driveTrain->TankDrive((abs((angle)) / 2 * PI) * (distance - 2 * PI * 11.75) / speed, (abs((angle)) / 2 * PI) * (distance + 2 * PI * 11.75) / speed);
		if(angle == 0) Robot::driveTrain->TankDrive(1, 1);
	}
	xList[6] = xList[5];
	yList[6] = yList[5];
}

// Make this return true when this Command no longer needs to run execute()
bool BezierCurve::IsFinished() {
	if(t == 101) return true;
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
