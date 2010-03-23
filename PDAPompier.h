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
public:
    PDAPompier(string nom,Case* maCase) : PDA(nom,maCase), mission(NULL){};
	string getDirection();
	void recevoirDonnee(Donnee& donnee);
	void seDeplacer(string direction);

};

#endif  //_PDAPOMPIER_H
