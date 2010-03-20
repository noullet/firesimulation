/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pag�s  //
/////////////////////

#if !defined(_DRONE_H)
#define _DRONE_H

#include "RobotMobile.h"
#include "Donnee.h"

class Drone : public RobotMobile
{
public:
    Drone(string name, Case* maCase) : RobotMobile(name,maCase) {};
};

#endif  //_DRONE_H
