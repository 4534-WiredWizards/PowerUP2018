/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RightTrigger2.h"
usr::RightTrigger2::RightTrigger2(std::shared_ptr<frc::Joystick> joystick) {
	m_joystick = joystick;

}

bool usr::RightTrigger2::Get() {
	return m_joystick->GetRawAxis(3) > 0.5;
//	return false;
}

