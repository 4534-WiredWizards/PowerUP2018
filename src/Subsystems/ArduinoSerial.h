#ifndef ArduinoSerial_H
#define ArduinoSerial_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class ArduinoSerial : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<frc::SerialPort> serialPort;
	char* inputBuffer;
public:
	ArduinoSerial();
	void InitDefaultCommand();
	std::string Read();
	void Write(std::string input);
	void SetAnimation(std::string input);

};

#endif  // ArduinoSerial_H
