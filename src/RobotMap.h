// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<WPI_TalonSRX> driveTrainLeftMasterTalon;
	static std::shared_ptr<WPI_TalonSRX> driveTrainRightMasterTalon;
	static std::shared_ptr<frc::DifferentialDrive> driveTrainDriver;
	static std::shared_ptr<WPI_TalonSRX> driveTrainLeftFollowerTalon;
	static std::shared_ptr<WPI_TalonSRX> driveTrainRightFollowerTalon;
	static std::shared_ptr<WPI_VictorSPX> driveTrainLeftFollowerVictor;
	static std::shared_ptr<WPI_VictorSPX> driveTrainRightFollowerVictor;
	static std::shared_ptr<frc::ADXRS450_Gyro> driveTrainDriveGyro;
	static std::shared_ptr<frc::Compressor> driveTrainCompressor;
	static std::shared_ptr<frc::Solenoid> driveTrainLeftShifter;
//	static std::shared_ptr<frc::Solenoid> driveTrainRightShifter;
	static std::shared_ptr<frc::Solenoid> boxHandlerSolenoid;
	static std::shared_ptr<frc::Encoder> driveTrainLeftDriveEncoder;
	static std::shared_ptr<frc::Encoder> driveTrainRightDriveEncoder;
	static std::shared_ptr<frc::DigitalInput> boxHandlerBoxDetect;
	static std::shared_ptr<frc::SpeedController> boxHandlerLeftArmWheel;
	static std::shared_ptr<frc::SpeedController> boxHandlerRightArmWheel;
	static std::shared_ptr<frc::Encoder> liftLiftEncoder;
	static std::shared_ptr<frc::SpeedController> liftLiftMotor;
	static std::shared_ptr<frc::DigitalInput> liftLiftLowerLimit;
	static std::shared_ptr<frc::DigitalInput> liftLiftUpperLimit;
	static std::shared_ptr<frc::Solenoid> boxHandlerGrabber;
//	static std::shared_ptr<frc::Solenoid> endgameExtensionsLeftBJoing;
//	static std::shared_ptr<frc::Solenoid> endgameExtensionsRightBJoing;
	static std::shared_ptr<frc::SpeedController> climberMotor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif
