/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_ROBOTTERRESTRE_H)
#define _ROBOTTERRESTRE_H

#include "RobotMobile.h"

class RobotTerrestre : public RobotMobile
{
public:
    RobotTerrestre(string name,Case* maCase) : RobotMobile(name,maCase){};
};

#endif  //_ROBOTTERRESTRE_H
