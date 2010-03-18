//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_ROBOTMOBILE_H)
#define _ROBOTMOBILE_H

#include "Robot.h"
#include "Mobile.h"
#include "Donnee.h"

class RobotMobile : public Robot, public Robot, public Mobile
{
public:
	void seDeplacer(string direction);
	string getDirection();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void seDeplacer(string direction);
	string getDirection();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
};

#endif  //_ROBOTMOBILE_H
