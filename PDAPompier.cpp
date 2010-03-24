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
#include "PDA.h"



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
        if(direction != "rester")
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
    Case& nCase = (foret).getCase(nX,nY);
    nCase.setAgent(this);
    maCase = &nCase;
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
        if(mission != NULL && (*mission).type == "feu")
        {
            if((x - vX) < 1 && (x-vX) >= 0 && (y - vY) < 2 && (y - vY) >= 1)
            {
                direction = "sud";
                    if(!f.verifierDirection(x,y,direction))
                    direction = "rester";
            }
            else if((vX - x) < 1 && (vX - x) >= 0 && (vY - y) < 2 && (vY - y) >= 1)
            {
                direction = "nord";
                    if(!f.verifierDirection(x,y,direction))
                    direction = "rester";
            }
            else if((vY - y) < 1 && (vY - y) >= 0 && (vX - x) < 2 && (vX - x) >= 1)
            {
                direction = "ouest";
                    if(!f.verifierDirection(x,y,direction))
                    direction = "rester";
            }
            else if((y - vY) < 1 && (y - vY) >= 0 && (x - vX) < 2 && (x-vX) >= 1)
            {
                direction = "est";
                    if(!f.verifierDirection(x,y,direction))
                    direction = "rester";
            }
        }
    }
    return direction;
}

void PDAPompier::recevoirDonnee(Donnee& donneeRecu)
{
    bool dejaTraite = false;
    if(mission == NULL)
    {
        if(donneeRecu.traite == false)
        {
            if(!missionDejaTraite(donneeRecu))
            {
                donneeRecu.traite = true;
                donneeRecu.pompier = nom;
                mission = &donneeRecu;
            }
        }
        else
        {
            ajouterDonneeTraite(donneeRecu);
        }
    }
    else
    {
        if(donneeRecu.traite == true)
            ajouterDonneeTraite(donneeRecu);
        if(!missionDejaTraite(donneeRecu))
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
    }
    if(!donneeRecu.equals(lastDonnee))
    {
        envoyerDonnee(donneeRecu);
    }
}

void PDAPompier::exclureDeSimulation()
{
    if(this->aSimuler)
    {
    cout << "_______________________________" << endl;
    cout << "Pompier " << nom << " est brule" << endl;
    cout << "_______________________________" << endl;
    }
    Agent::exclureDeSimulation();
}

bool PDAPompier::missionDejaTraite(Donnee& donneeRecu)
{
    bool dejaTraite = false;
    for(int i = 0 ; i < nbPompier ; i++)
    {
        if(dtraite[i] != NULL)
        {
            if(donneeRecu.equals(dtraite[i]) && (*dtraite[i]).traite)
            {
                dejaTraite = true;
            }
        }
    }
    return dejaTraite;
}

void PDAPompier::ajouterDonneeTraite(Donnee& donneeRecu)
{
    if(donneeRecu.pompier != nom)
    {
        int indice = -1;
        for(int i = 0 ; i < nbPompier ; i++)
        {
            if(dtraite[i] != NULL)
                if((*dtraite[i]).pompier == donneeRecu.pompier)
                    indice = i;
        }
        if(indice == -1)
        {
            bool enregistre = false;
            for(int i = 0 ; i < nbPompier ; i++)
            {
                if(dtraite[i] == NULL && !enregistre)
                {
                    dtraite[i] = &donneeRecu;
                    enregistre = true;
                }
            }
        }
        else
        {
            dtraite[indice] = &donneeRecu;
        }
    }
}

