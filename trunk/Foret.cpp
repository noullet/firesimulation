/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Foret.h"
#include "Case.h"
#include "Matrix.h"

Foret::Foret()
{
    this.matrice = Matrix<Case*>(this->NB_LIGNES,this->NB_COLONNES)
}
Case Foret::getCase(int x, int y)
{
    return this->matrice[x][y];
}
void Foret::afficher()
{
    for(int i=0 ; i<this->NB_LIGNES ; i++)
    {
        for(int j=0 ; j<this->NB_COLONNES ; j++)
        {
                cout << this.matrice[i][j].getEtat();
        }
        cout << endl;
    }
}

