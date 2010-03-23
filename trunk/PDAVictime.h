/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_PDAVICTIME_H)
#define _PDAVICTIME_H

#include "PDA.h"
#include "Donnee.h"

class PDAVictime : public PDA
{
protected:
    Donnee * donnee;
	bool blesse;
	bool priseEnCharge;
public:
    PDAVictime(string nom,Case* maCase) : PDA(nom,maCase), blesse(true), donnee(NULL){};
	bool estBlesse();
	bool estPriseEnCharge();
	void setPriseEnCharge(bool b);
	//void seDeplacer(string direction);
	string getDirection();
	void recevoirDonnee(Donnee& donnee);
};

#endif  //_PDAVICTIME_H
