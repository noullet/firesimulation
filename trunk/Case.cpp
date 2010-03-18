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

}

bool Case::estFeu()
{
    return (this->feu);
}

void Case::setFeu(bool estFeu)
{
    this->feu = estFeu;
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
    if(this->estFeu())
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

Foret Case::getForet()
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
    if(this->estFeu())
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

