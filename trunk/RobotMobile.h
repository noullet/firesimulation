/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_ROBOTMOBILE_H)
#define _ROBOTMOBILE_H

#include "Robot.h"
#include "Mobile.h"
#include "Donnee.h"

class RobotMobile : public Robot, public Mobile
{
public:
    RobotMobile(string name) : Robot(name) {};
	void seDeplacer(string direction);
	string getDirection();
};

#endif  //_ROBOTMOBILE_H
