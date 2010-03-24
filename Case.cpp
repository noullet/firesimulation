/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Case.h"
#include "Donnee.h"
#include "Foret.h"
#include "Agent.h"
#include "PDAVictime.h"
#include "PDAPompier.h"
#include "RobotMobile.h"
#include "Drone.h"
#include "RobotTerrestre.h"
#include "Capteur.h"
#include <typeinfo>
#include <unistd.h>

void Case::diffuserFeu()
{
    int i = rand();
    i = i%2;
    if(i == 0)
    {
        if(y+1 < foret.NB_COLONNES)
        {
                foret.getCase(x,y+1).allumerFeu();
        }
        if(y-1 >= 0)
        {
                foret.getCase(x,y-1).allumerFeu();
        }
    }
    else
    {
        if(x+1 < foret.NB_COLONNES)
        {
                foret.getCase(x+1,y).allumerFeu();
        }
        if(x-1 >= 0)
        {
                foret.getCase(x-1,y).allumerFeu();
        }
    }
    feu = 1;
}

int Case::getFeu()
{
    return(this->feu);
}

void Case::allumerFeu()
{
    if(feu == 0)
        feu = 1;
}

void Case::eteindreFeu()
{
    this->feu = 0;
}

void Case::bruler()
{
    this->feu ++;
    if(agent!=NULL)
    {
        (*agent).exclureDeSimulation();
        agent = NULL;
    }
}

int Case::getX()
{
    return this->x;
}

int Case::getY()
{
 return this->y;
}

Donnee* Case::decouvrir()
{
    string type;
    type = "neant";
    if(this->getFeu() > 0)
    {
        type = "feu";
    }
    else if(this->agent != NULL)
    {
        if(typeid(*agent) == typeid(PDAVictime))
        {
            PDAVictime * vict = (PDAVictime*)agent;
            if((*vict).estBlesse() && (!(*vict).estPriseEnCharge()))
            {
                type = "blesse";
            }
        }
    }
    return new Donnee(type, x, y);
}

Foret& Case::getForet()
{
    return this->foret;
}

Agent* Case::getAgent()
{
    return this->agent;
}

void Case::setAgent(Agent *aAgent)
{
    this->agent = aAgent;
}

char Case::getEtat()
{
    if(this->estLieuSur())
    {
        return 'H';
    }
    else if(this->getFeu() > 0)
    {
        return 'F';
    }
    else if(this->agent != NULL)
    {
        if(typeid(*(this->agent))==typeid(Drone))
        {
            return 'D';
        }
        else if(typeid(*(this->agent)) == typeid(RobotTerrestre))
        {
            return 'R';
        }
        else if(typeid(*(this->agent)) == typeid(Capteur))
        {
            return 'C';
        }
        else if(typeid(*(this->agent)) == typeid(PDAPompier))
        {
            return 'P';
        }
        else if(typeid(*(this->agent)) == typeid(PDAVictime))
        {
                if(((PDAVictime*)(this->agent))->estBlesse())
                { return 'B'; }
                else
                { return 'V'; }
        }
    }
    else
    {
        return '*';
    }
}

void Case::setLieuSur()
{
    lieuSur = true;
}

bool Case::estLieuSur()
{
    return lieuSur;
}

