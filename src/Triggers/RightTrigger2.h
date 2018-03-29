/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef RIGHTTRIGGER2_H
#define  RIGHTTRIGGER2_H

#include <Buttons/InternalButton.h>
#include "WPILib.h"
//#include "../Robot.h"
//#include "../OI.h"

namespace usr{
class RightTrigger2 : public frc::InternalButton {
public:
	RightTrigger2(std::shared_ptr<frc::Joystick> joystick);
	std::shared_ptr<frc::Joystick> m_joystick;
	bool Get() override;
};
}
#endif
