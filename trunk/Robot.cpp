/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Robot.h"
#include "Donnee.h"
#include "Foret.h"
#include "Case.h"
#include "Donnee.h"
#include <iostream>
using namespace std;

#define RAYON_VISION 1
#define RAYON_WIFI 3

void Robot::decouvrirEnvironnement()
{
    Foret& f = (*maCase).getForet();
    int x = (*maCase).getX();
    int y = (*maCase).getY();
    // Champ de vision réel
    int xMin = x - RAYON_VISION;
    int xMax = x + RAYON_VISION + 1;
    int yMin = y - RAYON_VISION;
    int yMax = y + RAYON_VISION + 1;
    if(xMin < 0)
        xMin = 0;
    if(xMax > f.NB_LIGNES)
        xMax = f.NB_LIGNES;
    if(yMin < 0)
        yMin = 0;
    if(yMax > f.NB_COLONNES)
        yMax = f.NB_COLONNES;
    // Découverte de l'environnement
    for(int i=xMin ; i<xMax ; i++)
    {
        for(int j=yMin ; j<yMax ; j++)
        {
            // On ne se découvre pas
            if(!(i == x & j==y))
            {
                Donnee * d = f.getCase(i,j).decouvrir();
                if((*d).type != "neant")
                    envoyerDonnee(*d);
                else
                    delete d;
            }
        }
    }
}

void Robot::envoyerDonnee(Donnee& donnee)
{
    lastDonnee = &donnee;
    Foret& f = (*maCase).getForet();
    int x = (*maCase).getX();
    int y = (*maCase).getY();
    // Champ de vision réel
    int xMin = x - RAYON_WIFI;
    int xMax = x + RAYON_WIFI + 1;
    int yMin = y - RAYON_WIFI;
    int yMax = y + RAYON_WIFI + 1;
    if(xMin < 0)
        xMin = 0;
    if(xMax > f.NB_LIGNES)
        xMax = f.NB_LIGNES;
    if(yMin < 0)
        yMin = 0;
    if(yMax > f.NB_COLONNES)
        yMax = f.NB_COLONNES;
    // Découverte de l'environnement
    for(int i=xMin ; i<xMax ; i++)
    {
        for(int j=yMin ; j<yMax ; j++)
        {
            // On ne s'envoie pas la donnee
            if(!(i == x & j==y))
            {
                Agent* agent = f.getCase(i,j).getAgent();
                if(agent != NULL)
                {
                    cout << "Robot " << nom << " envoie ";
                    donnee.afficher();
                    (*agent).recevoirDonnee(donnee);
                }
            }
        }
    }
}

void Robot::recevoirDonnee(Donnee& don)
{
    cout << "Robot " << nom << " recoit ";
    don.afficher();

    if(!don.equals(lastDonnee))
        envoyerDonnee(don);
}

