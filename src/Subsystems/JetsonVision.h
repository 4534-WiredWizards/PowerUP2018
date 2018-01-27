#ifndef JetsonVision_H
#define JetsonVision_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
class JetsonVision : public Subsystem {
private:

	std::string getTarget;
	std::shared_ptr<NetworkTable> visionTable;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	JetsonVision();
	void InitDefaultCommand();
	double GetAngleToTarget();
	void GetDistanceToTarget();

};

#endif  // JetsonVision_H
