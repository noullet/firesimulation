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

void Case::diffuserFeu()
{
    if(y+1 < foret.NB_COLONNES)
    {
            foret.getCase(x,y+1).allumerFeu();
    }
    if(y-1 >= 0)
    {
            foret.getCase(x,y-1).allumerFeu();
    }
    if(x+1 < foret.NB_COLONNES)
    {
            foret.getCase(x+1,y).allumerFeu();
    }
    if(x-1 >= 0)
    {
            foret.getCase(x-1,y).allumerFeu();
    }
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
}

int Case::getX()
{
    return this->x;
}

int Case::getY()
{
 return this->y;
}

Donnee Case::decouvrir()
{
    string type;
    if(this->getFeu() > 0)
    {
        type = "feu";
    }
    else if(typeid(*(this->agent)) == typeid(PDAVictime))
    {
        if(((PDAVictime*)(this->agent))->estBlesse())
        {
            type = "blesse";
        }
    }
    else
    {
        type = "neant";
    }
    Donnee d(type, this->x, this->y);
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
    if(this->getFeu() > 0)
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

