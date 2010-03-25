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
#define VFEU 2
#define NBROBOTS 2
#define NBROBOTSMOBILES 2
#define NBPDAS 5
#define NBPOMPIER 3

using namespace std;

bool estTermine(Foret& f);
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
    while(!estTermine(f))
    {
        cout << "Appuyez sur la touche entree pour continuer" << endl;
        read(0,&c,sizeof(char));
        continuer(f);
        f.afficher();
    }
    cout << "\n___________________________________________" << endl;
    cout << "La simulation s'est terminée avec succes : " << endl;
    cout << "Tous les blessés sont sauves et le feu est eteint" << endl;
    cout << "___________________________________________" << endl;

    return 0;
}

void initialiser(Foret &f)
{
    // Allumage du feu
    f.getCase(0,0).allumerFeu();
    f.getCase(1,0).allumerFeu();
    f.getCase(2,0).allumerFeu();
    // Ajout des robots non mobiles
    robots[0] = new Capteur("cp1",&f.getCase(4,4));
    f.getCase(4,4).setAgent(robots[0]);
    robots[1] = new Capteur("cp2",&f.getCase(4,7));
    f.getCase(4,7).setAgent(robots[1]);
    // Ajout des robots mobiles
    robotsMobiles[0] = new RobotTerrestre("rt1",&f.getCase(1,1));
    f.getCase(1,1).setAgent(robotsMobiles[0]);
    robotsMobiles[1] = new Drone("dr1",&f.getCase(7,8));
    f.getCase(7,8).setAgent(robotsMobiles[1]);
    // Ajout des PDAs
    pdas[0] = new PDAVictime("nico",&f.getCase(4,8), true);
    f.getCase(4,8).setAgent(pdas[0]);
    pdas[1] = new PDAPompier("beber",&f.getCase(3,4), NBPOMPIER);
    f.getCase(3,4).setAgent(pdas[1]);
    f.getCase(13,13).setLieuSur();
    pdas[2] = new PDAVictime("jiji",&f.getCase(8,8), false);
    f.getCase(8,8).setAgent(pdas[2]);
    pdas[3] = new PDAPompier("alex",&f.getCase(5,4), NBPOMPIER);
    f.getCase(5,4).setAgent(pdas[3]);
    pdas[4] = new PDAPompier("manech",&f.getCase(5,6), NBPOMPIER);
    f.getCase(5,6).setAgent(pdas[4]);
}

bool estTermine(Foret & f)
{
    // Verification feu
    for(int i=0 ; i<f.NB_LIGNES ; i++)
    {
        for(int j=0 ; j<f.NB_COLONNES ; j++)
        {
            Case& c = f.getCase(i,j);
            int feu = c.getFeu();
            if(feu > 0)
                return false;
        }
    }
    // Verification blessés
    for(int i=0 ; i<NBPDAS ; i++)
    {
        PDA * p = pdas[i];
        if( typeid(*p) == typeid(PDAVictime) )
        {
            PDAVictime * pv = dynamic_cast<PDAVictime*>(p);
            if( (*pv).estBlesse() && (*pv).estASimuler() )
                return false;
        }
    }
    return true;
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
