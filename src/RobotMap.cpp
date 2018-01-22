// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
#include "WPILib.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainLeftMasterTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainRightMasterTalon;
std::shared_ptr<frc::DifferentialDrive> RobotMap::driveTrainDriver;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainLeftFollowerTalon;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainRightFollowerTalon;
std::shared_ptr<WPI_VictorSPX> RobotMap::driveTrainLeftFollowerVictor;
std::shared_ptr<WPI_VictorSPX> RobotMap::driveTrainRightFollowerVictor;
std::shared_ptr<frc::AnalogGyro> RobotMap::driveTrainDriveGyro;
std::shared_ptr<frc::Compressor> RobotMap::driveTrainCompressor;
std::shared_ptr<frc::Solenoid> RobotMap::driveTrainLeftShifter;
std::shared_ptr<frc::Solenoid> RobotMap::driveTrainRightShifter;
std::shared_ptr<frc::Solenoid> RobotMap::driveTrainLeftPTO;
std::shared_ptr<frc::Solenoid> RobotMap::driveTrainRightPTO;
std::shared_ptr<frc::Encoder> RobotMap::driveTrainLeftDriveEncoder;
std::shared_ptr<frc::Encoder> RobotMap::driveTrainRightDriveEncoder;
std::shared_ptr<frc::DigitalInput> RobotMap::boxHandlerBoxDetect;
std::shared_ptr<frc::SpeedController> RobotMap::boxHandlerLeftArmWheel;
std::shared_ptr<frc::SpeedController> RobotMap::boxHandlerRightArmWheel;
std::shared_ptr<frc::Encoder> RobotMap::liftLiftEncoder;
std::shared_ptr<frc::SpeedController> RobotMap::liftLiftMotor;
std::shared_ptr<frc::DigitalInput> RobotMap::liftLiftLowerLimit;
std::shared_ptr<frc::DigitalInput> RobotMap::liftLiftUpperLimit;
std::shared_ptr<frc::Solenoid> RobotMap::endgameExtensionsLeftBJoing;
std::shared_ptr<frc::Solenoid> RobotMap::endgameExtensionsRightBJoing;
std::shared_ptr<frc::Servo> RobotMap::endgameExtensionsLeftGullWing;
std::shared_ptr<frc::Servo> RobotMap::endgameExtensionsRightGullWing;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    //frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    driveTrainLeftMasterTalon.reset(new WPI_TalonSRX(3));
    
    
    driveTrainRightMasterTalon.reset(new WPI_TalonSRX(4));
    
    
    driveTrainDriver.reset(new frc::DifferentialDrive(*driveTrainLeftMasterTalon, *driveTrainRightMasterTalon));
    //lw->AddActuator("DriveTrain", "Driver", driveTrainDriver);
    driveTrainDriver->SetName("DriveTrain", "Driver");
    driveTrainDriver->SetSafetyEnabled(true);
        driveTrainDriver->SetExpiration(0.1);
        driveTrainDriver->SetMaxOutput(1.0);

    driveTrainLeftFollowerTalon.reset(new WPI_TalonSRX(5));
    
    
    driveTrainRightFollowerTalon.reset(new WPI_TalonSRX(6));
    
    
    driveTrainLeftFollowerVictor.reset(new WPI_VictorSPX(7));
    
    
    driveTrainRightFollowerVictor.reset(new WPI_VictorSPX(8));
    
    
    driveTrainDriveGyro.reset(new frc::AnalogGyro(0));
    //lw->AddSensor("DriveTrain", "DriveGyro", driveTrainDriveGyro);
    driveTrainDriveGyro->SetName("DriveTrain", "DriveGyro");
    driveTrainDriveGyro->SetSensitivity(0.007);
    driveTrainCompressor.reset(new frc::Compressor(1));
    //lw->AddActuator("DriveTrain", "Compressor", driveTrainCompressor);
    driveTrainCompressor->SetName("DriveTrain", "Compressor");
    
    driveTrainLeftShifter.reset(new frc::Solenoid(1, 0));
    //lw->AddActuator("DriveTrain", "LeftShifter", driveTrainLeftShifter);
    driveTrainLeftShifter->SetName("DriveTrain", "LeftShifter");
    
    driveTrainRightShifter.reset(new frc::Solenoid(1, 1));
    //lw->AddActuator("DriveTrain", "RightShifter", driveTrainRightShifter);
    driveTrainRightShifter->SetName("DriveTrain", "RightShifter");
    
    driveTrainLeftPTO.reset(new frc::Solenoid(1, 2));
    //lw->AddActuator("DriveTrain", "LeftPTO", driveTrainLeftPTO);
    driveTrainLeftPTO->SetName("DriveTrain", "LeftPTO");
    
    driveTrainRightPTO.reset(new frc::Solenoid(1, 3));
    //lw->AddActuator("DriveTrain", "RightPTO", driveTrainRightPTO);
    driveTrainRightPTO->SetName("DriveTrain", "RightPTO");
    
    driveTrainLeftDriveEncoder.reset(new frc::Encoder(0, 1, false, frc::Encoder::k4X));
    //lw->AddSensor("DriveTrain", "LeftDriveEncoder", driveTrainLeftDriveEncoder);
    driveTrainLeftDriveEncoder->SetName("DriveTrain", "LeftDriveEncoder");
    driveTrainLeftDriveEncoder->SetDistancePerPulse(1.0);
    driveTrainLeftDriveEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
    driveTrainRightDriveEncoder.reset(new frc::Encoder(2, 3, false, frc::Encoder::k4X));
    //lw->AddSensor("DriveTrain", "RightDriveEncoder", driveTrainRightDriveEncoder);
    driveTrainRightDriveEncoder->SetName("DriveTrain", "RightDriveEncoder");
    driveTrainRightDriveEncoder->SetDistancePerPulse(1.0);
    driveTrainRightDriveEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
    boxHandlerBoxDetect.reset(new frc::DigitalInput(6));
    //lw->AddSensor("BoxHandler", "BoxDetect", boxHandlerBoxDetect);
    boxHandlerBoxDetect->SetName("BoxHandler", "BoxDetect");
    
    boxHandlerLeftArmWheel.reset(new frc::Spark(1));
    //lw->AddActuator("BoxHandler", "LeftArmWheel", std::static_pointer_cast<frc::Spark>(boxHandlerLeftArmWheel));
    std::static_pointer_cast<frc::Spark>(boxHandlerLeftArmWheel)->SetName("BoxHandler", "LeftArmWheel");
    
    boxHandlerRightArmWheel.reset(new frc::Spark(2));
    //lw->AddActuator("BoxHandler", "RightArmWheel", std::static_pointer_cast<frc::Spark>(boxHandlerRightArmWheel));
    std::static_pointer_cast<frc::Spark>(boxHandlerRightArmWheel)->SetName("BoxHandler", "RightArmWheel");
    
    liftLiftEncoder.reset(new frc::Encoder(4, 5, false, frc::Encoder::k4X));
    //lw->AddSensor("Lift", "LiftEncoder", liftLiftEncoder);
    liftLiftEncoder->SetName("Lift", "LiftEncoder");
    liftLiftEncoder->SetDistancePerPulse(1.0);
    liftLiftEncoder->SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    liftLiftMotor.reset(new frc::Spark(0));
    //lw->AddActuator("Lift", "LiftMotor", std::static_pointer_cast<frc::Spark>(liftLiftMotor));
    std::static_pointer_cast<frc::Spark>(liftLiftMotor)->SetName("Lift", "LiftMotor");
    
    liftLiftLowerLimit.reset(new frc::DigitalInput(7));
    //lw->AddSensor("Lift", "LiftLowerLimit", liftLiftLowerLimit);
    liftLiftLowerLimit->SetName("Lift", "LiftLowerLimit");
    
    liftLiftUpperLimit.reset(new frc::DigitalInput(8));
    //lw->AddSensor("Lift", "LiftUpperLimit", liftLiftUpperLimit);
    liftLiftUpperLimit->SetName("Lift", "LiftUpperLimit");
    
    endgameExtensionsLeftBJoing.reset(new frc::Solenoid(1, 4));
    //lw->AddActuator("EndgameExtensions", "LeftBJoing", endgameExtensionsLeftBJoing);
    endgameExtensionsLeftBJoing->SetName("EndgameExtensions", "LeftBJoing");
    
    endgameExtensionsRightBJoing.reset(new frc::Solenoid(1, 5));
    //lw->AddActuator("EndgameExtensions", "RightBJoing", endgameExtensionsRightBJoing);
    endgameExtensionsRightBJoing->SetName("EndgameExtensions", "RightBJoing");
    
    endgameExtensionsLeftGullWing.reset(new frc::Servo(3));
    //lw->AddActuator("EndgameExtensions", "LeftGullWing", endgameExtensionsLeftGullWing);
    endgameExtensionsLeftGullWing->SetName("EndgameExtensions", "LeftGullWing");
    
    endgameExtensionsRightGullWing.reset(new frc::Servo(4));
    //lw->AddActuator("EndgameExtensions", "RightGullWing", endgameExtensionsRightGullWing);
    endgameExtensionsRightGullWing->SetName("EndgameExtensions", "RightGullWing");


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
