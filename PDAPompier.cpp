/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "PDAPompier.h"
#include "Donnee.h"
#include "Foret.h"
#include "Case.h"

void PDAPompier::seDeplacer(string direction)
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
        if(dX > dY)
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
    return direction;
}

void PDAPompier::recevoirDonnee(Donnee& donneeRecu)
{
    cout << "PDAPompier " << nom << " recoit ";
    donneeRecu.afficher();
    if(mission == NULL)
    {
        donneeRecu.traite = true;
        mission = &donneeRecu;
    }
    if(!donneeRecu.equals(lastDonnee))
    {
        envoyerDonnee(donneeRecu);
    }
}

