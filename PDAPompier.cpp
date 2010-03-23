/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "PDAPompier.h"
#include "Donnee.h"
#include "Foret.h"
#include "Case.h"
#include "PDAVictime.h"

void PDAPompier::seDeplacer(string direction)
{
    int aX, aY;
    int nX = (*maCase).getX();
    int nY = (*maCase).getY();
    aX = nX;
    aY = nY;
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
        string directionVict;
        Case * caseVict = (*((PDAVictime*)secours)).getCase();
        int vX = (*caseVict).getX();
        int vY = (*caseVict).getY();
        if(vX+1 == aX && vY == aY)
            directionVict = ("sud");
        else if (vX - 1 == aX && vY == aY)
            directionVict = ("nord");
        else if (vY - 1 == aY && vX == aX)
            directionVict = ("est");
        else
            directionVict = ("ouest");
        (*secours).seDeplacer(directionVict);
        caseVict = (*((PDAVictime*)secours)).getCase();
        cout << (*caseVict).estLieuSur() << endl;
        if((*caseVict).estLieuSur())
        {
            (*secours).exclureDeSimulation();
            secours = NULL;
            mission = NULL;
        }
    }
    if(mission != NULL)
    {
        if((*mission).type == "blesse")
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
                    PDAVictime* v = (PDAVictime*)a;
                    (*v).setPriseEnCharge();
                }
            }
        }
        if((*mission).type == "feu")
        {
            int mX = (*mission).x;
            int mY = (*mission).y;
            int dX = abs((*maCase).getX() - mX);
            int dY = abs((*maCase).getY() - mY);
            if(dX <= 2 && dY <= 2)
            {
                cout << "Pompier eteint le feu <" << mX << "," << mY << ">" << endl;
                foret.getCase(mX, mY).eteindreFeu();
                cout << foret.getCase(mX, mY).getFeu() << endl;
                mission = NULL;
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
            directionH = "sud";
        else
            directionH = "nord";
        if(vY < y)
            directionV = "est";
        else
            directionV = "ouest";
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
        if(donneeRecu.traite == false)
        {
            if(dtraite != NULL)
            {
                if(!donneeRecu.equals(dtraite))
                {
                    donneeRecu.traite = true;
                    donneeRecu.traite = "nom";
                    mission = &donneeRecu;
                }
            }
            else
            {
                donneeRecu.traite = true;
                donneeRecu.traite = "nom";
                mission = &donneeRecu;
            }
        }
        else
        {
                dtraite = &donneeRecu;
        }
    }
    else
    {
        if(donneeRecu.type == "feu" && (*mission).type == "feu")
        {
            int dX, dY, dX2, dY2;
            dX = (*maCase).getX();
            dY = (*maCase).getY();
            dX = abs(dX - (*mission).x);
            dY = abs(dY - (*mission).y);
            dX2 = abs((*maCase).getX() - donneeRecu.x);
            dY2 = abs((*maCase).getY() - donneeRecu.y);
            if(dX2 < dX || dY2 < dX)
            {
                (*mission).traite = false;
                mission = &donneeRecu;
            }
        }
    }
    if(!donneeRecu.equals(lastDonnee))
    {
        envoyerDonnee(donneeRecu);
    }
}

