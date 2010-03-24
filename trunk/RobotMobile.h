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
    RobotMobile(string name,Case* maCase) : Robot(name,maCase) {};
	void seDeplacer(string direction);
	string getDirection();
	void exclureDeSimulation();
};

#endif  //_ROBOTMOBILE_H
