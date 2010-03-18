//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_MOBILE_H)
#define _MOBILE_H

#include "Agent.h"
#include "Donnee.h"

class Mobile : public Agent
{
public:
	virtual void seDeplacer(string direction) = 0;
	virtual string getDirection() = 0;
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
};

#endif  //_MOBILE_H
