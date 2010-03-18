/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Foret.h"
#include "Case.h"

Foret::Foret()
{
    this->matrice = Matrix<Case*>(this->NB_LIGNES,this->NB_COLONNES);
    for(int i=0 ; i<this->NB_LIGNES ; i++)
    {
        for(int j=0 ; j<this->NB_COLONNES ; j++)
        {
                this->matrice[i][j] = new Case(i,j,*this);
        }
        cout << endl;
    }
}
Case Foret::getCase(int x, int y)
{
    return *(this->matrice[x][y]);
}
void Foret::afficher()
{
    for(int i=0 ; i<this->NB_LIGNES ; i++)
    {
        for(int j=0 ; j<this->NB_COLONNES ; j++)
        {
                cout << this->matrice[i][j]->getEtat();
        }
        cout << endl;
    }
}

Foret::~Foret()
{
    for(int i=0 ; i<this->NB_LIGNES ; i++)
    {
        for(int j=0 ; j<this->NB_COLONNES ; j++)
        {
                delete this->matrice[i][j];
        }
        cout << endl;
    }
}

