/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_DRONE_H)
#define _DRONE_H

#include "RobotMobile.h"
#include "Donnee.h"

class Drone : public RobotMobile
{
public:
    Drone(string name) : RobotMobile(name) {};
};

#endif  //_DRONE_H
