/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "PDA.h"
#include "Donnee.h"
#include "Case.h"

#define RAYON_VISION 1
#define RAYON_WIFI 2
using namespace std;
void PDA::decouvrirEnvironnement()
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
            Donnee * d = f.getCase(i,j).decouvrir();
            if((*d).type != "neant")
                envoyerDonnee(*d);
            else
                delete d;
        }
    }
}

void PDA::envoyerDonnee(Donnee& donnee)
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
                if(agent != NULL && (*agent).estASimuler())
                {
                    cout << "PDA " << nom << " envoie ";
                    donnee.afficher();
                    (*agent).recevoirDonnee(donnee);
                }
            }
        }
    }
}

void PDA::recevoirDonnee(Donnee& donneeRecu)
{

}

void PDA::seDeplacer(string direction)
{
    int nX = (*maCase).getX();
    int nY = (*maCase).getY();
    Foret& foret = (*maCase).getForet();
    (*maCase).setAgent(NULL);
    if(direction == "nord")
        nX--;
    if(direction == "sud")
        nX++;
    if(direction == "est")
        nY--;
    if(direction == "ouest")
        nY++;
    Case& nCase = (foret).getCase(nX,nY);
    nCase.setAgent(this);
    maCase = &nCase;
}

string PDA::getDirection()
{

}



