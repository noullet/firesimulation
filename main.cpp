#include <iostream>
#include "Foret.h"
#include "Case.h"
#include "Agent.h"

using namespace std;

bool estTermine();
void continuer(Foret& f);

int main()
{
    Foret f;
    char c;
    while(!estTermine())
    {
        f.afficher();
        cin >> c;
        continuer(f);
    }
    return 0;
}

bool estTermine()
{
    return false;
}

void continuer(Foret &f)
{
    for(int i=0 ; i<f.NB_LIGNES ; i++)
    {
        for(int j=0 ; j<f.NB_COLONNES ; j++)
        {
            if(f.getCase(i,j).estFeu())
            {
               f.getCase(i,j).diffuserFeu();
            }
            Agent* agent = f.getCase(i,j).getAgent();
            if(agent != NULL)
            {
                (*agent).decouvrirEnvironnement();
            }
        }
    }
}
