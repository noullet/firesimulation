/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_AGENT_H)
#define _AGENT_H

#include "Donnee.h"

class Agent
{
protected:
	string nom;
	int vision;
public:
	virtual void decouvrirEnvironnement() = 0;
	virtual void envoyerDonnee(Donnee donnee) = 0;
	virtual void recevoirDonnee(Donnee donnee) = 0;
};

#endif  //_AGENT_H
