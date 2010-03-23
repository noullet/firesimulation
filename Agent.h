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
    Donnee * lastDonnee;
	string nom;
	static const int vision = 2;
	Case *maCase;
	bool aSimuler;
public:
    Agent(string nom,Case* maCase) : nom(nom), maCase(maCase), lastDonnee(NULL), aSimuler(true) {};
	virtual void decouvrirEnvironnement() = 0;
	virtual void envoyerDonnee(Donnee& donnee) = 0;
	virtual void recevoirDonnee(Donnee& donnee) = 0;
	void exclureDeSimulation()
	{
        aSimuler = false;
    }
    bool estASimuler()
    {
        return aSimuler;
    }
};

#endif  //_AGENT_H
