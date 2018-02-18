// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<BoxHandler> Robot::boxHandler;
std::shared_ptr<Lift> Robot::lift;
std::shared_ptr<EndgameExtensions> Robot::endgameExtensions;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<JetsonVision> Robot::jetsonVision;
std::shared_ptr<ArduinoSerial> Robot::arduinoSerial;
DriverStation::Alliance Robot::allianceColor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<frc::Timer> Robot::TimeTurner;
std::string Robot::SwitchPosition;
int Robot::target;
bool Robot::isTesting = false;
std::string Robot::location;


void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    boxHandler.reset(new BoxHandler());
    lift.reset(new Lift());
    endgameExtensions.reset(new EndgameExtensions());
    TimeTurner.reset(new frc::Timer());
    climber.reset(new Climber());
    jetsonVision.reset(new JetsonVision());
    arduinoSerial.reset(new ArduinoSerial());
    allianceColor = DriverStation::GetInstance().GetAlliance();
    SwitchPosition = "???";
    target = -1;
    location = "...";
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//chooser.AddObject("SampleAutonomousCommand", new SampleAutonomousCommand());
	//chooser.AddObject("LeftAuto", new LeftAuto());
	//chooser.AddObject("CenterAuto", new CenterAuto());
	//chooser.AddObject("RightAuto", new RightAuto());

	//chooser.AddDefault("SampleAutonomousCommand", new SampleAutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	//frc::SmartDashboard::PutData("Auto Modes", &chooser);
	targetChooser.AddDefault("DriveStraight", 0);
	targetChooser.AddObject("Switch", 1);
	targetChooser.AddObject("Scale", 2);
	targetChooser.AddObject("SwitchScale", 3);
	locationChooser.AddObject("Left", "Left");
	locationChooser.AddDefault("Center", "Center");
	locationChooser.AddObject("Right", "Right");
	frc::SmartDashboard::PutData("Auto Target", &targetChooser);
	frc::SmartDashboard::PutData("Auto Start Location", &locationChooser);
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	TimeTurner->Stop();
	frc::SmartDashboard::PutNumber("Auto Delay",0);
	arduinoSerial->Write("5");
	allianceColor = DriverStation::GetInstance().GetAlliance();
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	allianceColor = DriverStation::GetInstance().GetAlliance();
}

void Robot::AutonomousInit() {
	location = locationChooser.GetSelected();
	target = targetChooser.GetSelected();
	SwitchPosition=frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(location == "Center"){
		autonomousCommand = new CenterAuto();
	} else {
		autonomousCommand = new SideAuto();
	}
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
	TimeTurner->Reset(); TimeTurner->Start();
	Robot::arduinoSerial->SetAnimation("a");

}


void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
	TimeTurner->Reset(); TimeTurner->Start();
	Robot::arduinoSerial->SetAnimation("t");
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();

}

START_ROBOT_CLASS(Robot);

