#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
class Climber : public Subsystem {
private:
	std::shared_ptr<frc::SpeedController> climberMotor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Climber();
	void SetMotor(double rate);
	void InitDefaultCommand();
};

#endif  // Climber_H
