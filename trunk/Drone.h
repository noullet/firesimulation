/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_DRONE_H)
#define _DRONE_H

#include "RobotMobile.h"
#include "Donnee.h"

class Drone : public RobotMobile
{
public:
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	string getDirection();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
};

#endif  //_DRONE_H
