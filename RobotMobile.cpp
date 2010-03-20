/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "RobotMobile.h"
#include "Donnee.h"
#include "Case.h"
#include "Foret.h"
#include <iostream>

void RobotMobile::seDeplacer(string direction)
{
    int nX = (*maCase).getX();
    int nY = (*maCase).getY();
    Foret& foret = (*maCase).getForet();
    (*maCase).setAgent(NULL);
    if(direction == "nord")
    {
        nX--;
    }
    if(direction == "sud")
    {
        nX++;
    }
    if(direction == "est")
    {
        nY--;
    }
    if(direction == "ouest")
    {
        nY++;
    }
    Case& nCase = (foret).getCase(nX,nY);
    nCase.setAgent(this);
    maCase = &nCase;
}

string RobotMobile::getDirection()
{
    return("sud");
}
