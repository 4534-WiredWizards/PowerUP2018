#ifndef MotherOfAllAutos_H
#define MotherOfAllAutos_H

#include <Commands/CommandGroup.h>

class MotherOfAllAutos : public frc::CommandGroup {
public:
	MotherOfAllAutos(int offset);
private:
	int multiplier = 0;
};


#endif  // MotherOfAllAutos_H
