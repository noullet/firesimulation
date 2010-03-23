/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "PDAPompier.h"
#include "Donnee.h"
#include "Foret.h"
#include "Case.h"

string PDAPompier::getDirection()
{
    string direction;
    Foret& f = (*maCase).getForet();
    int x = (*maCase).getX();
    int y = (*maCase).getY();
    if(mission == NULL)
    {
        direction = "rester";
    }
    else
    {
        int dX, dY;
        dX = std::abs(x - (*mission).x);
        dY = std::abs(y - (*mission).y);
        string directionH;
        string directionV;
        if((*mission).x > x)
        {
            directionH = "sud";
        }
        else
        {
            directionH = "nord";
        }
        if((*mission).y < y)
        {
            directionV = "est";
        }
        else
        {
            directionV = "ouest";
        }
        if(dX < dY)
        {
            direction = directionH;
            if(!f.verifierDirection(x,y,direction))
            {
                direction = directionV;
                if(!f.verifierDirection(x,y,direction))
                    direction = "rester";
            }
        }
        else
        {
            direction = directionV;
            if(!f.verifierDirection(x,y,direction))
            {
                direction = directionH;
                if(!f.verifierDirection(x,y,direction))
                    direction = "rester";
            }
        }
    }
}

void PDAPompier::recevoirDonnee(Donnee& donneeRecu)
{


    if(!donneeRecu.equals(lastDonnee))
    {
        envoyerDonnee(donneeRecu);
    }
}

