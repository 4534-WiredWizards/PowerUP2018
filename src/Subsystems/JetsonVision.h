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
	double negative4534PostRewind = 0;
	JetsonVision();
	void InitDefaultCommand();
	double GetAngleToTarget(std::string target);
	double GetDistanceToTarget(std::string target);
	std::string GetTarget();
	void SetTarget(std::string target);
};

#endif  // JetsonVision_H
