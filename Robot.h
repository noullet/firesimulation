//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_ROBOT_H)
#define _ROBOT_H

#include "Agent.h"
#include "Donnee.h"

class Robot : public Agent
{
public:
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
};

#endif  //_ROBOT_H
