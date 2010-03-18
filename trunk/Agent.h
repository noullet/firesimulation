/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pag�s  //
/////////////////////

#if !defined(_AGENT_H)
#define _AGENT_H

#include "Donnee.h"

class Agent
{
protected:
	string nom;
	static const int vision = 2;
public:
    Agent(string nom) : nom(nom) {};
	virtual void decouvrirEnvironnement() = 0;
	virtual void envoyerDonnee(Donnee donnee) = 0;
	virtual void recevoirDonnee(Donnee donnee) = 0;
};

#endif  //_AGENT_H