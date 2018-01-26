#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class BezierCurve: public frc::Command {
public:
	BezierCurve(int P0x, int P0y, int P1x, int P1y, int P2x, int P2y, int P3x, int P3y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double xList[];
	double yList[];
	int t;
	int m_P0x;
	int m_P0y;
	int m_P1x;
	int m_P1y;
	int m_P2x;
	int m_P2y;
	int m_P3x;
	int m_P3y;
	double angle;
	double distance;
	const double PI = 3.14159;
	const int speed = 10;
};

#endif  // BezierCurve_H
