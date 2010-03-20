/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_PDA_H)
#define _PDA_H

#include "Agent.h"
#include "Mobile.h"
#include "Donnee.h"

class PDA : public Agent, public Mobile
{
public:
    PDA(string nom, Case* maCase) : Agent(nom,maCase){};
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee& donnee);
	void recevoirDonnee(Donnee& donnee);
	void seDeplacer(string direction);
	string getDirection();
};

#endif  //_PDA_H
