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
    if(direction != "rester")
    {
        int nX = (*maCase).getX();
        int nY = (*maCase).getY();
        Foret& foret = (*maCase).getForet();
        (*maCase).setAgent(NULL);
        if(direction == "nord")
            nX--;
        if(direction == "sud")
            nX++;
        if(direction == "est")
            nY--;
        if(direction == "ouest")
            nY++;
        Case& nCase = (foret).getCase(nX,nY);
        nCase.setAgent(this);
        maCase = &nCase;
    }
}

string RobotMobile::getDirection()
{
    int x = (*maCase).getX();
    int y = (*maCase).getY();
    int i;
    string direction;
    Foret& f = (*maCase).getForet();
    bool directionOk = false;

    // Si aucune direction possible
    if(!f.verifierDirection(x,y,"sud")
    && !f.verifierDirection(x,y,"est")
    && !f.verifierDirection(x,y,"ouest")
    && !f.verifierDirection(x,y,"nord"))
        return "rester";

    // Direction aléatoire
    while(!directionOk)
    {
        i = rand();
        i = i%4;
        switch(i)
        {
            case 0 :
                direction = "sud";
                break;
            case 1 :
                direction = "nord";
                break;
            case 2 :
                direction = "est";
                break;
            case 3 :
                direction = "ouest";
                break;
        }
        directionOk = f.verifierDirection(x,y,direction);
	}
	return direction;
}
