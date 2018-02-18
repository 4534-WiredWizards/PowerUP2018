#define MAX_INPUT_CHAR 32

#include "ArduinoSerial.h"
#include "../Robot.h"

//#include "SerialPort.h"

ArduinoSerial::ArduinoSerial() : Subsystem("ArduinoSerial") {
	serialPort.reset(new SerialPort(115200, SerialPort::kMXP));
	inputBuffer=(char*)calloc(MAX_INPUT_CHAR, sizeof(char));
}

void ArduinoSerial::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
std::string ArduinoSerial::Read(){
	serialPort->Read(inputBuffer, MAX_INPUT_CHAR);
	return inputBuffer;
}
void ArduinoSerial::Write(std::string input){
	serialPort->Write(input);
}
void ArduinoSerial::SetAnimation(std::string input){
	if(Robot::allianceColor == DriverStation::Alliance::kBlue) {
		serialPort->Write('B' + input);
	} else {
		serialPort->Write('R' + input);
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
