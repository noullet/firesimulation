//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_AGENT_H)
#define _AGENT_H

#include "Donnee.h"

class Agent
{
public:
	string nom;
	int vision;
	virtual void decouvrirEnvironnement() = 0;
	virtual void envoyerDonnee(Donnee donnee) = 0;
	virtual void recevoirDonnee(Donnee donnee) = 0;
};

#endif  //_AGENT_H
