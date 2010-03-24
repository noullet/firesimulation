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
protected :
    Donnee * mission;
    PDA * secours;
    Donnee * dtraite;
public:
    PDAPompier(string nom,Case* maCase) : PDA(nom,maCase), mission(NULL), secours(NULL), dtraite(NULL){};
	string getDirection();
	void recevoirDonnee(Donnee& donnee);
	void seDeplacer(string direction);
	void exclureDeSimulation();

};

#endif  //_PDAPOMPIER_H
