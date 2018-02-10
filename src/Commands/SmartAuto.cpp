/*
 * SmartAuto.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: messi
 */
#include "SmartAuto.h"
#include "DriveStraightDistance.h"
#include "EjectBox.h"
#include "LiftToHeight.h"
#include "TurnAngle.h"
SmartAuto::SmartAuto() {
	AddSequential(new DriveStraightDistance(40,1));

	if(Robot::location=="Left"){
		//the robot is on the left
		if(Robot::SwitchPosition[0]=='L'){
			//the robot is on the left and switch is on the left
			//code to go from left to left switch then to scale
		}else{
			//the robot is on the left and switch is on the right
			//code to go from left to switch here
		}
	}else if (Robot::location=="Right"){
		//the robot is on the right
		if(Robot::SwitchPosition[0]=='R'){
			//the robot is on the right and scale is on the right
			//code to go from right to scale then switch
		}else{
			//the robot is on the right and scale is on the left
			//code to go from right directly to scale
		}
	}else{
		//the robot is in the middle
		//code to go from middle to switch then scale goes here
	}
}
