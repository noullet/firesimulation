/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Foret.h"
#include "Case.h"
#include <iostream>
using namespace std;

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
Case& Foret::getCase(int x, int y)
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

bool Foret::verifierDirection(int x, int y, string direction)
{
    int nX = x;
    int nY = y;
    if(direction == "nord")
        nX--;
    if(direction == "sud")
        nX++;
    if(direction == "est")
        nY--;
    if(direction == "ouest")
        nY++;
    if(nX < 0 || nX >= NB_LIGNES || nY < 0 || nY >= NB_COLONNES)
        return false;
    Case & nCase = getCase(nX,nY);
    if(nCase.getAgent() != NULL  || nCase.getFeu() > 0)
        return false;
    return true;
}

Foret::~Foret()
{
    for(int i=0 ; i<NB_LIGNES ; i++)
    {
        for(int j=0 ; j<NB_COLONNES ; j++)
        {
            delete this->matrice[i][j];
        }
        delete[] this->matrice[i];
    }
    delete[] this->matrice;
    cout << "La foret a ete detruite" << endl;
}

Case* Foret::getLieuSur()
{
    for(int i=0 ; i<NB_LIGNES ; i++)
    {
        for(int j=0 ; j<NB_COLONNES ; j++)
        {
            if(getCase(i,j).estLieuSur())
                return &getCase(i,j);
        }
    }
    return NULL;
}

