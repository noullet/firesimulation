/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pag�s  //
/////////////////////

#if !defined(_FORET_H)
#define _FORET_H

#include "Matrix.h"
class Case;

class Foret
{
private:
    static const int NB_LIGNES = 10;
    static const int NB_COLONNES = 10;
    Matrix<Case*> matrice;
public:
    Foret();
    void afficher();
	Case getCase(int x, int y);
};

#endif  //_FORET_H
