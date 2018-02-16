#ifndef GoToThing_H
#define GoToThing_H

#include "Commands/CommandGroup.h"

class GoToThing: public frc::CommandGroup {
public:
	GoToThing(std::string thing, bool rewind);
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
