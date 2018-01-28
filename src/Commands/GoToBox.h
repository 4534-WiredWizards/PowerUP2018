#ifndef GOTOBOX_H
#define GOTOBOX_H

#include "Commands/CommandGroup.h"

class GoToBox: public frc::CommandGroup {
public:
	GoToBox(int dist, int angle, bool rewind);
private:
	double m_dist;
	double m_angle;
	bool m_rewind;
	double opposite;
	double adjacent;
	const double PI = 3.14159;
	double actualBoxAngle = 0;
};

#endif  // GOTOBOX_H
