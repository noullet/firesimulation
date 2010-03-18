/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_ROBOTTERRESTRE_H)
#define _ROBOTTERRESTRE_H

#include "RobotMobile.h"
#include "Donnee.h"

class RobotTerrestre : public RobotMobile
{
public:
    RobotTerrestre(string name) : RobotMobile(name){};
};

#endif  //_ROBOTTERRESTRE_H
