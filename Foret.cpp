/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Foret.h"
#include "Case.h"

Foret::Foret()
{
    this->matrice = new Case**[NB_LIGNES];
    for(int i=0 ; i<NB_LIGNES ; i++)
    {
        this->matrice[i] = new Case*[NB_COLONNES];
        for(int j=0 ; j<NB_COLONNES ; j++)
        {
            this->matrice[i][j] = new Case(i,j,*this);
        }

    }
}
Case Foret::getCase(int x, int y)
{
    return *this->matrice[x][y];
}
void Foret::afficher()
{
    for(int i=0 ; i<NB_LIGNES ; i++)
    {
        for(int j=0 ; j<NB_COLONNES ; j++)
        {
                cout << getCase(i,j).getEtat() << " ";
        }
        cout << endl;
    }
}

Foret::~Foret()
{

}

