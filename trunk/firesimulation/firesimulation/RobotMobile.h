#pragma once
#include "robot.h"
#include "mobile.h"

class RobotMobile :
public Robot, public Mobile
{
public:
	RobotMobile(void);
};
