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
    PDAVictime(string nom,Case* maCase, bool estblesse) : PDA(nom,maCase), blesse(estblesse), donnee(NULL), priseEnCharge(false){};
	bool estBlesse();
	bool estPriseEnCharge();
	void setPriseEnCharge(bool b);
	//void seDeplacer(string direction);
	string getDirection();
	void recevoirDonnee(Donnee& donnee);
	Case * getCase();
	void exclureDeSimulation();
	void setPriseEnCharge();
};

#endif  //_PDAVICTIME_H
