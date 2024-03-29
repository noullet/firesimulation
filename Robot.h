/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pag�s  //
/////////////////////

#if !defined(_ROBOT_H)
#define _ROBOT_H

#include "Agent.h"
#include "Donnee.h"

class Robot : public Agent
{
public:
    Robot(string name,Case* maCase) : Agent(name,maCase) {};
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee& donnee);
	void recevoirDonnee(Donnee& donnee);
};

#endif  //_ROBOT_H
