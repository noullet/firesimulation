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
#define NBPDAS 2

using namespace std;

bool estTermine();
void continuer(Foret& f);
void initialiser(Foret& f);
Robot* robots[NBROBOTS];
RobotMobile* robotsMobiles[NBROBOTSMOBILES];
PDA* pdas[NBPDAS];

int main()
{
    // Initialisation de la foret
    Foret f;
    initialiser(f);
    // Debut de la simulation
    char c;
    f.afficher();
    while(!estTermine())
    {
        cout << "Appuyez sur la touche entree pour continuer" << endl;
        read(0,&c,sizeof(char));
        continuer(f);
        f.afficher();
    }
    return 0;
}

void initialiser(Foret &f)
{
    // Allumage du feu
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
    pdas[1] = new PDAPompier("beber",&f.getCase(5,4));
    f.getCase(5,4).setAgent(pdas[1]);
}

bool estTermine()
{
    return false;
}

void continuer(Foret &f)
{
    // Traitement robots
    for(int i=0 ; i<NBROBOTS ; i++)
    {
        if((*robots[i]).estASimuler())
            (*robots[i]).decouvrirEnvironnement();
    }
    // Traitement robots mobiles
    for(int i=0 ; i<NBROBOTSMOBILES ; i++)
    {
        RobotMobile * rm = robotsMobiles[i];
        if((*rm).estASimuler())
        {
            (*rm).seDeplacer((*rm).getDirection());
            (*rm).decouvrirEnvironnement();
        }
    }
    // Traitement pdas
    for(int i=0 ; i<NBPDAS ; i++)
    {
        PDA * p = pdas[i];
        if((*p).estASimuler())
        {
            (*p).seDeplacer((*p).getDirection());
            (*p).decouvrirEnvironnement();
        }
    }
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
}