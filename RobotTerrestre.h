//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_ROBOTTERRESTRE_H)
#define _ROBOTTERRESTRE_H

#include "RobotMobile.h"
#include "Donnee.h"

class RobotTerrestre : public RobotMobile
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

#endif  //_ROBOTTERRESTRE_H
