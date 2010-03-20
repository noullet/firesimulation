/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_AGENT_H)
#define _AGENT_H

#include "Donnee.h"
class Case;

class Agent
{
protected:
	string nom;
	static const int vision = 2;
	Case *maCase;
public:
    Agent(string nom,Case* maCase) : nom(nom), maCase(maCase) {};
	virtual void decouvrirEnvironnement() = 0;
	virtual void envoyerDonnee(Donnee& donnee) = 0;
	virtual void recevoirDonnee(Donnee& donnee) = 0;
};

#endif  //_AGENT_H
