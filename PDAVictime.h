//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_PDAVICTIME_H)
#define _PDAVICTIME_H

#include "PDA.h"
#include "Donnee.h"

class PDAVictime : public PDA
{
public:
	bool blesse;
	bool priseEnCharge;
	bool estBlesse();
	bool estPriseEnCharge();
	void setPriseEnCharge(bool b);
	void seDeplacer(string direction);
	string getDirection();
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void seDeplacer(string direction);
	string getDirection();
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
	void decouvrirEnvironnement();
	void envoyerDonnee(Donnee donnee);
	void recevoirDonnee(Donnee donnee);
};

#endif  //_PDAVICTIME_H
