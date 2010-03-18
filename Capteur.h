/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_CAPTEUR_H)
#define _CAPTEUR_H

#include "Robot.h"
#include "Donnee.h"

class Capteur : public Robot
{
public:
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
};

#endif  //_CAPTEUR_H
