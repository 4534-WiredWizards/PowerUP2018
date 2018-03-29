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
	pringle = atan2(P1y - P0y, P1x - P0x);
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
	//Waits until the distance is met OR the fuction begins at time = 1
	if(Robot::driveTrain->getLeftDistanceCounter() + Robot::driveTrain->getRightDistanceCounter() / 2 >= distance || t == 1) {
	Robot::driveTrain->resetDistanceCounter();
	//Calculates time / precision of the lines. See https://upload.wikimedia.org/wikipedia/commons/d/db/B%C3%A9zier_3_big.gif
	xList[0] = m_P0x + ((m_P1x - m_P0x) * ((double)t / m_precision)); //Grey line P0=P1 point x
	yList[0] = m_P0y + ((m_P1y - m_P0y) * ((double)t / m_precision)); //Grey line P0=P1 point y
	xList[1] = m_P1x + ((m_P2x - m_P1x) * ((double)t / m_precision)); //Grey line P1=P2 point x
	yList[1] = m_P1y + ((m_P2y - m_P1y) * ((double)t / m_precision)); //Grey line P1=P2 point y
	xList[2] = m_P2x + ((m_P3x - m_P2x) * ((double)t / m_precision)); //Grey line P2=P3 point x
	yList[2] = m_P2y + ((m_P3y - m_P2y) * ((double)t / m_precision)); //Grey line P2=P3 point y
	xList[3] = xList[0] + ((xList[1] - xList[0]) * ((double)t / m_precision)); //Green line point 1 x
	yList[3] = yList[0] + ((yList[1] - yList[0]) * ((double)t / m_precision)); //Green line point 1 y
	xList[4] = xList[1] + ((xList[2] - xList[1]) * ((double)t / m_precision)); //Green line point 2 x
	yList[4] = yList[1] + ((yList[2] - yList[1]) * ((double)t / m_precision)); //Green line point 2 y
	xList[5] = xList[3] + ((xList[4] - xList[3]) * ((double)t / m_precision)); //Blue line point x
	yList[5] = yList[3] + ((yList[4] - yList[3]) * ((double)t / m_precision)); //Blue line point y
	//Increments time
	t++;
	//Uses gyro to caculate angle difference (present angle to needed one)
	if(m_relative == false)
	{
		if(Robot::driveTrain->getGyroAngle() < 0)
		{
			angle = atan2(yList[5] - yList[6], xList[5] - xList[6]); - (fmod(Robot::driveTrain->getGyroAngle(), -360) / 360 * (2 * PI));
		}
		else
		{
			angle = atan2(yList[5] - yList[6], xList[5] - xList[6]); - (fmod(Robot::driveTrain->getGyroAngle(), 360) / 360 * (2 * PI));
		}
	}
	//Uses current calculated angle to caculate angle difference (present angle to needed one), will assume first grey line represents robots current angle.
	else
	{
		fangle = atan2(yList[5] - yList[6], xList[5] - xList[6]);
		angle = fangle - pringle;
		pringle = fangle;
	}
	//Makes sure the angle isnt over 90, indicating a "cusp" error. If it is, lowers angle until it is below 90.
	//For cusp see https://proxy.duckduckgo.com/iu/?u=http%3A%2F%2Fwww.sosmath.com%2Fcalculus%2Fdiff%2Fder09%2FImage02.gif&f=1
	//note how you could rotate the two "wings" to remove the cusp and make a seamless curve like
	//https://proxy.duckduckgo.com/iur/?f=1&image_host=http%3A%2F%2Fwww.vitutor.com%2Fgeometry%2Fconics%2Fimages%2F106.gif&u=https://www.vitutor.com/geometry/conics/images/106.gif
	if(angle > PI / 2) {
		while(angle > PI / 2) {
			angle = angle - PI;
		}
	}
	//Makes sure the angle isnt under -90, indicating a "cusp" error. If it is, lowers angle until it is above -90.
	if(angle < PI / -2) {
		while(angle < PI / -2) {
			angle = angle + PI;
		}
	}
	//Calculates distance needed to travel, based on current pos(list[6]) and target (List[5])
	distance = sqrt(pow(xList[6] - xList[5], 2) + pow(yList[6] - yList[5], 2));
	//Shifts the "current" target point to the previous one slot.
	xList[6] = xList[5];
	yList[6] = yList[5];
	//Testing values in dashboard for troubleshooting
	frc::SmartDashboard::PutNumber("B_Distance", distance);
	frc::SmartDashboard::PutNumber("B_Angle", angle);
	frc::SmartDashboard::PutNumber("B_Fake_Angle", fangle);
	frc::SmartDashboard::PutNumber("B_Previous_Angle", pringle);
	}
	if(!(distance == 0)) {
		//Calculates an arc on a circle that will go the distance while turning the angle
		b = (PI - angle) / 2;
		r = sin(b) / (sin(angle) / distance);
		//Testing values in dashboard for troubleshooting
		frc::SmartDashboard::PutNumber("B_TankValue", ((r - 11.75) / (r + 11.75) * m_ratio));
		frc::SmartDashboard::PutNumber("B_Radius", r);
		//Starts traveiling along the arc at speed (ratio). Goes until the distance is met.
		if(angle > 0) Robot::driveTrain->TankDrive(m_ratio, ((r - 11.75) / (r + 11.75)) * m_ratio);
		if(angle < 0) Robot::driveTrain->TankDrive((r + 11.75) / (r - 11.75) * m_ratio, m_ratio);
		if(angle == 0) Robot::driveTrain->TankDrive(m_ratio, m_ratio);
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
