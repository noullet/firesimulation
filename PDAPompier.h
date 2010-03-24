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
    Donnee ** dtraite;
    int nbPompier;
public:
    PDAPompier(string nom,Case* maCase, int nbPompier) : PDA(nom,maCase), mission(NULL), secours(NULL), nbPompier(nbPompier)
    {
        this->nbPompier = this->nbPompier - 1;
        dtraite = new Donnee*[nbPompier];
        for(int i = 0 ; i < nbPompier ; i++)
        {
            dtraite[i] = NULL;
        }
    };
	string getDirection();
	void recevoirDonnee(Donnee& donnee);
	void seDeplacer(string direction);
	void exclureDeSimulation();
	bool missionDejaTraite(Donnee& donneeRecu);
	void ajouterDonneeTraite(Donnee& donneeRecu);

};

#endif  //_PDAPOMPIER_H
