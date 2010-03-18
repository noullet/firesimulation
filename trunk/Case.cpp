/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Case.h"
#include "Donnee.h"
#include "Foret.h"

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

}

Foret Case::getForet()
{
    return this->foret;
}

Agent Case::getAgent()
{
    return this->agent;
}

void Case::setAgent(Agent aAgent)
{
    this->agent = aAgent;
}

