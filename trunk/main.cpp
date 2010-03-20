#include <iostream>
#include "Foret.h"
#include "Case.h"
#include "Agent.h"
#include <unistd.h>
#define VFEU 1

using namespace std;

bool estTermine();
void continuer(Foret& f);

int main()
{
    Foret f;
    f.getCase(0,0).allumerFeu();
    char c;
    while(!estTermine())
    {
        f.afficher();
        cout << "Appuyez sur la touche entree pour continuer" << endl;
        read(0,&c,sizeof(char));
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
            Case& c = f.getCase(i,j);
            // Traitement feu
            int feu = c.getFeu();
            if(feu > 0)
                c.bruler();
            if(feu > VFEU)
                c.diffuserFeu();
            // Traitement agent
            Agent* agent = c.getAgent();
            if(agent != NULL)
            {
                (*agent).decouvrirEnvironnement();
            }
        }
    }
}
