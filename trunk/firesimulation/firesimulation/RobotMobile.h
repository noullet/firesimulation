#pragma once
#include "robot.h"
#include "mobile.h"

ref class RobotMobile :
public Robot, public Mobile
{
public:
	RobotMobile(void);
};
