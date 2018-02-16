#include "Ascend.h"
#include "../Subsystems/Climber.h"

Ascend::Ascend() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Ascend::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Ascend::Execute() {
	Robot::climber->SetMotor(1);
	Robot::lift->setLiftSpeed(-.1);
}

// Make this return true when this Command no longer needs to run execute()
bool Ascend::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Ascend::End() {
	Robot::climber->SetMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Ascend::Interrupted() {
	Robot::climber->SetMotor(0);
}
