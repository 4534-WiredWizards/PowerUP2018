#include "BezierCurve.h"
#include "cmath"
#include "SmartDashboard/SmartDashboard.h"
BezierCurve::BezierCurve(double P0x, double P0y, double P1x, double P1y, double P2x, double P2y, double P3x, double P3y, int precision, bool relative, double ratio): frc::Command() {
	m_ratio = ratio;
	BezierCurve(P0x, P0y, P1x, P1y, P2x, P2y, P3x, P3y, precision, relative);
}
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
	pringle = 0;
}

// Called just before this Command runs the first time
void BezierCurve::Initialize() {
	t = 1;
	angle = 0;
	distance = 0;
	xList[6] = m_P0x;
	xList[6] = m_P0y;
	Robot::driveTrain->resetDistanceCounter();
}

// Called repeatedly when this Command is scheduled to run
void BezierCurve::Execute() {
	//cycles++;
	//if(cycles % 10 == 0 || t == 1) {
	if(Robot::driveTrain->getLeftDistanceCounter() + Robot::driveTrain->getRightDistanceCounter() / 2 >= distance || t == 1) {
	Robot::driveTrain->resetDistanceCounter();
	xList[0] = m_P0x + ((m_P1x - m_P0x) * ((double)t / m_precision));
	yList[0] = m_P0y + ((m_P1y - m_P0y) * ((double)t / m_precision));
	xList[1] = m_P1x + ((m_P2x - m_P1x) * ((double)t / m_precision));
	yList[1] = m_P1y + ((m_P2y - m_P1y) * ((double)t / m_precision));
	xList[2] = m_P2x + ((m_P3x - m_P2x) * ((double)t / m_precision));
	yList[2] = m_P2y + ((m_P3y - m_P2y) * ((double)t / m_precision));
	xList[3] = xList[0] + ((xList[1] - xList[0]) * ((double)t / m_precision));
	yList[3] = yList[0] + ((yList[1] - yList[0]) * ((double)t / m_precision));
	xList[4] = xList[1] + ((xList[2] - xList[1]) * ((double)t / m_precision));
	yList[4] = yList[1] + ((yList[2] - yList[1]) * ((double)t / m_precision));
	xList[5] = xList[3] + ((xList[4] - xList[3]) * ((double)t / m_precision));
	yList[5] = yList[3] + ((yList[4] - yList[3]) * ((double)t / m_precision));
	t++;
	if(m_relative == false)
	{
	fangle = atan(yList[3] - yList[4]/ xList[3] - xList[4]) - (fmod(Robot::driveTrain->getGyroAngle(), 360) / 360 * (2 * PI));
	}
	else
	{
	fangle = atan2(yList[5] - yList[6], xList[5] - xList[6]);
	angle = fangle - pringle;
	pringle = fangle;
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
	if(t > 1) distance = sqrt(pow(xList[6] - xList[5], 2) + pow(yList[6] - yList[5], 2));
	else distance = 0;
	xList[6] = xList[5];
	yList[6] = yList[5];
	frc::SmartDashboard::PutNumber("B_Distance", distance);
	frc::SmartDashboard::PutNumber("BANGle", angle);
	frc::SmartDashboard::PutNumber("fangle", fangle);
	frc::SmartDashboard::PutNumber("pringle", pringle);
	}
	if(!(distance == 0)) {
		b = (PI - angle) / 2;
		r = sin(b) / (sin(angle) / distance);
		frc::SmartDashboard::PutNumber("bug boy", ((r - 11.75) / (r + 11.75) * m_ratio));
		frc::SmartDashboard::PutNumber("biggie r", r);
		if(angle > 0) Robot::driveTrain->TankDrive(m_ratio, ((r - 11.75) / (r + 11.75)) * m_ratio);
		if(angle < 0) Robot::driveTrain->TankDrive((r + 11.75) / (r - 11.75) * m_ratio, m_ratio);
		if(angle == 0) Robot::driveTrain->TankDrive(m_ratio, m_ratio);
		//if(angle > 0) Robot::driveTrain->TankDrive(m_ratio, ((angle) / (2 * PI)) * (distance - (2 * PI) * 11.75) / ((angle) / (2 * PI)) * (distance + (2 * PI) * 11.75) * m_ratio);
		//if(angle < 0) Robot::driveTrain->TankDrive((abs((angle)) / (2 * PI)) * (distance - (2 * PI) * 11.75) / (abs((angle)) / (2 * PI)) * (distance + (2 * PI) * 11.75) * m_ratio, m_ratio);
		//if(angle == 0) Robot::driveTrain->TankDrive(m_ratio, m_ratio);
	}
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
