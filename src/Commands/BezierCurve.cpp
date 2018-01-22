#include "BezierCurve.h"

BezierCurve::BezierCurve(int P0x, int P0y, int P1x, int P1y, int P2x, int P2y, int P3x, int P3y): frc::Command() {
	m_P0x = P0x;
	m_P0y = P0y;
	m_P1x = P1x;
	m_P1y = P1y;
	m_P2x = P2x;
	m_P2y = P2y;
	m_P3x = P3x;
	m_P3y = P3y;
	t = 0;
}

// Called just before this Command runs the first time
void BezierCurve::Initialize() {
	t = 0;
	xList[0] = m_P0x + ((m_P1x - m_P0x) * (t / 100));
	yList[0] = m_P0y + ((m_P1y - m_P0y) * (t / 100));
	xList[1] = m_P1x + ((m_P2x - m_P1x) * (t / 100));
	yList[1] = m_P1y + ((m_P2y - m_P1y) * (t / 100));
	xList[2] = m_P2x + ((m_P3x - m_P2x) * (t / 100));
	yList[2] = m_P2y + ((m_P3y - m_P2y) * (t / 100));
	xList[3] = xList[1] + ((m_P1x - m_P0x) * (t / 100));
	yList[3] = m_P0y + ((m_P1y - m_P0y) * (t / 100));
	xList[4] = m_P0x + ((m_P1x - m_P0x) * (t / 100));
	yList[4] = m_P0y + ((m_P1y - m_P0y) * (t / 100));
	xList[5] = m_P0x + ((m_P1x - m_P0x) * (t / 100));
	yList[5] = m_P0y + ((m_P1y - m_P0y) * (t / 100));

}

// Called repeatedly when this Command is scheduled to run
void BezierCurve::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool BezierCurve::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BezierCurve::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BezierCurve::Interrupted() {

}
