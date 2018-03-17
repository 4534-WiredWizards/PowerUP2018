// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<WPI_TalonSRX> leftMasterTalon;
	std::shared_ptr<WPI_TalonSRX> rightMasterTalon;
	std::shared_ptr<frc::DifferentialDrive> driver;
	std::shared_ptr<WPI_TalonSRX> leftFollowerTalon;
	std::shared_ptr<WPI_TalonSRX> rightFollowerTalon;
	std::shared_ptr<WPI_VictorSPX> leftFollowerVictor;
	std::shared_ptr<WPI_VictorSPX> rightFollowerVictor;
	std::shared_ptr<frc::ADXRS450_Gyro> driveGyro;
	std::shared_ptr<frc::Compressor> compressor;
	std::shared_ptr<frc::Solenoid> leftShifter;
	//std::shared_ptr<frc::Solenoid> rightShifter;
	std::shared_ptr<frc::Encoder> leftDriveEncoder;
	std::shared_ptr<frc::Encoder> rightDriveEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	DriveTrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	void TankDrive(double leftRate, double rightRate);
	void ArcadeDrive(double speed, double rotate);
	void resetDistanceCounter();
	double getLeftDistanceCounter();
	double getRightDistanceCounter();
	double getGyroAngle();
	void resetGyroAngle();
	void setShift(bool state);
	bool getShift();
	void StartCompressor();
	void StopCompressor();
	double getLeftRate();
	double getRightRate();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
