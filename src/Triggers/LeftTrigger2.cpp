/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LeftTrigger2.h"

usr::LeftTrigger2::LeftTrigger2(std::shared_ptr<frc::Joystick> joystick) {
	m_joystick = joystick;
}

bool usr::LeftTrigger2::Get() {
	return m_joystick->GetRawAxis(2) > 0.5;
}

