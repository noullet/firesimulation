#include <iostream>
#include "Foret.h"
#include "Case.h"
#include "Agent.h"
#include "RobotTerrestre.h"
#include "RobotMobile.h"
#include "Drone.h"
#include "PDA.h"
#include "Capteur.h"
#include "PDAVictime.h"
#include "PDAPompier.h"
#include "Mobile.h"
#include <unistd.h>
#define VFEU 1
#define NBAGENTS 2

using namespace std;

bool estTermine();
void continuer(Foret& f);
Agent* agents[NBAGENTS];

int main()
{
    // Initialisation de la foret
    Foret f;
    f.getCase(0,0).allumerFeu();
    agents[0] = new RobotTerrestre("rt1",&f.getCase(2,2));
    agents[1] = new Drone("cp1",&f.getCase(4,4));
    f.getCase(2,2).setAgent(agents[0]);
    f.getCase(4,4).setAgent(agents[1]);
    // Debut de la simulation
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
    // Traitement feu
    for(int i=0 ; i<f.NB_LIGNES ; i++)
    {
        for(int j=0 ; j<f.NB_COLONNES ; j++)
        {
            Case& c = f.getCase(i,j);
            int feu = c.getFeu();
            if(feu > 0)
                c.bruler();
            if(feu > VFEU)
                c.diffuserFeu();
        }
    }
    // Traitement agents
    for(int i=0 ; i<NBAGENTS ; i++)
    {
        Agent* agent = agents[i];
        (*agent).decouvrirEnvironnement();
        if( typeid(RobotMobile).before(typeid(*agent)))
        {
            RobotMobile* m = (RobotMobile*)(agent);
            (*m).seDeplacer((*m).getDirection());
        }
        if( typeid(PDA).before(typeid(*agent)))
        {
            PDA* m = (PDA*)(agent);
            (*m).seDeplacer((*m).getDirection());
        }
    }
}
