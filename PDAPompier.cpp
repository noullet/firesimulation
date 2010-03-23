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
    if(secours != NULL)
    {
        (*secours).seDeplacer(direction);
    }
    if(mission != NULL)
    {
        int mX = (*mission).x;
        int mY = (*mission).y;
        int dX = abs((*maCase).getX() - mX);
        int dY = abs((*maCase).getY() - mY);
        if((dX == 1 && dY == 0) || (dY == 1 && dX == 0))
        {
            Agent * a = foret.getCase(mX, mY).getAgent();
            if(a != NULL)
            {
                secours = (PDA*)a;
            }
        }
    }
}

string PDAPompier::getDirection()
{
    string direction;
    Foret& f = (*maCase).getForet();
    int x = (*maCase).getX();
    int y = (*maCase).getY();
    int vX;
    int vY;
    if(mission == NULL)
    {
        direction = "rester";
    }
    else
    {
        int dX, dY;
        if(secours != NULL)
        {
            Case * c = f.getLieuSur();
            vX = (*c).getX();
            vY = (*c).getY();
        }
        else
        {
            vX = (*mission).x;
            vY = (*mission).y;
        }
        dX = std::abs(x - vX);
        dY = std::abs(y - vY);
        string directionH;
        string directionV;
        if(vX > x)
        {
            directionH = "sud";
        }
        else
        {
            directionH = "nord";
        }
        if(vY < y)
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

