#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class BezierCurve: public frc::Command {
public:
	BezierCurve(double P0x, double P0y, double P1x, double P1y, double P2x, double P2y, double P3x, double P3y, int precision, bool relative);
	BezierCurve(double P0x, double P0y, double P1x, double P1y, double P2x, double P2y, double P3x, double P3y, int precision, bool relative, double ratio);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double xList[10];
	double yList[10];
	int t;
	double m_P0x;
	double m_P0y;
	double m_P1x;
	double m_P1y;
	double m_P2x;
	double m_P2y;
	double m_P3x;
	double m_P3y;
	double angle;
	double distance;
	const double PI = 3.14159;
	const int speed = 10;
	int m_precision;
	bool m_relative;
	double m_ratio = 1;
};

#endif  // BezierCurve_H
