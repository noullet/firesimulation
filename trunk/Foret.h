/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_FORET_H)
#define _FORET_H

#include "Case.h"
#include "Matrix.h"

#define NB_LIGNES 10
#define NB_COLONNES 10

class Foret
{
private:
    Matrix<Case> matrice(NB_LIGNES, NB_COLONNES);
public:
    Foret();
	Case getCase(int x, int y);
};

#endif  //_FORET_H
