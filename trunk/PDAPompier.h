/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_PDAPOMPIER_H)
#define _PDAPOMPIER_H

#include "PDA.h"
#include "Donnee.h"

class PDAPompier : public PDA
{
public:
	void seDeplacer(string direction);
	string getDirection();
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);

};

#endif  //_PDAPOMPIER_H
