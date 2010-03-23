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
#define VFEU 3
#define NBROBOTS 2
#define NBROBOTSMOBILES 1
#define NBPDAS 1

using namespace std;

bool estTermine();
void continuer(Foret& f);
Robot* robots[NBROBOTS];
RobotMobile* robotsMobiles[NBROBOTSMOBILES];
PDA* pdas[NBPDAS];

int main()
{
    // Initialisation de la foret
    Foret f;
    f.getCase(0,0).allumerFeu();
    // Ajout des robots non mobiles
    robots[0] = new Capteur("cp1",&f.getCase(4,4));
    f.getCase(4,4).setAgent(robots[0]);
    robots[1] = new Capteur("cp2",&f.getCase(4,7));
    f.getCase(4,7).setAgent(robots[1]);
    // Ajout des robots mobiles
    robotsMobiles[0] = new RobotTerrestre("rt1",&f.getCase(2,2));
    f.getCase(2,2).setAgent(robotsMobiles[0]);
    // Ajout des PDAs
    pdas[0] = new PDAVictime("nico",&f.getCase(4,8));
    f.getCase(4,8).setAgent(pdas[0]);
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
    // Traitement robots
    for(int i=0 ; i<NBROBOTS ; i++)
    {
        (*robots[i]).decouvrirEnvironnement();
    }
    // Traitement robots mobiles
    for(int i=0 ; i<NBROBOTSMOBILES ; i++)
    {
        RobotMobile * rm = robotsMobiles[i];
        (*rm).seDeplacer((*rm).getDirection());
        (*rm).decouvrirEnvironnement();
    }
    // Traitement pdas
    for(int i=0 ; i<NBPDAS ; i++)
    {
        PDA * p = pdas[i];
        (*p).seDeplacer((*p).getDirection());
        (*p).decouvrirEnvironnement();
    }
}
