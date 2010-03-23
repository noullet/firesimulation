/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "PDAVictime.h"
#include "Donnee.h"
#include "Foret.h"
#include "Case.h"


#define RAYON_VISION 1
#define RAYON_WIFI 2

bool PDAVictime::estBlesse()
{
    return this->blesse;
}

bool PDAVictime::estPriseEnCharge()
{
    return this->priseEnCharge;
}

void PDAVictime::setPriseEnCharge(bool b)
{
    this->priseEnCharge = b;
}

string PDAVictime::getDirection()
{

    string direction;
    if(this->estBlesse())
    {
        direction = "rester";
    }
    else
    {
        Foret& f = (*maCase).getForet();
        int x = (*maCase).getX();
        int y = (*maCase).getY();
        bool directionOk = false;
        if(donnee == NULL)
        {
            int i;

            // Si aucune direction possible
            if(!f.verifierDirection(x,y,"sud")
            && !f.verifierDirection(x,y,"est")
            && !f.verifierDirection(x,y,"ouest")
            && !f.verifierDirection(x,y,"nord"))
                return "rester";

        // Direction aléatoire
            while(!directionOk)
            {
                i = rand();
                i = i%4;
                switch(i)
                {
                    case 0 :
                        direction = "sud";
                        break;
                    case 1 :
                        direction = "nord";
                        break;
                    case 2 :
                        direction = "est";
                        break;
                    case 3 :
                        direction = "ouest";
                        break;
                }
                directionOk = f.verifierDirection(x,y,direction);
            }
        }
        else
        {
            int dX, dY;
            dX = std::abs(x - (*donnee).x);
            dY = std::abs(y - (*donnee).y);
            string directionH;
            string directionV;
            if((*donnee).x < x)
            {
                directionH = "sud";
            }
            else
            {
                directionH = "nord";
            }
            if((*donnee).y > y)
            {
                directionV = "est";
            }
            else
            {
                directionV = "ouest";
            }
            if(dX < dY)
            {
                direction = directionH;
                if(!f.verifierDirection(x,y,direction))
                {
                    direction = directionV;
                    if(!f.verifierDirection(x,y,direction))
                        direction = "rester";
                }
            }
            else
            {
                direction = directionV;
                if(!f.verifierDirection(x,y,direction))
                {
                    direction = directionH;
                    if(!f.verifierDirection(x,y,direction))
                        direction = "rester";
                }
            }
        }
    }
    return direction;
}

void PDAVictime::recevoirDonnee(Donnee& donneeRecu)
{
    cout << "PDAVictime " << nom << " recoit ";
    donneeRecu.afficher();
    if(donneeRecu.type == "feu")
    {
        int dX, dY, dX2, dY2;
        dX = (*maCase).getX();
        dY = (*maCase).getY();
        if(donnee != NULL)
        {
            dX = abs(dX - (*donnee).x);
            dY = abs(dY - (*donnee).y);
        }
        else
        {
            donnee == &donneeRecu;
        }
        dX2 = abs((*maCase).getX() - donneeRecu.x);
        dY2 = abs((*maCase).getY() - donneeRecu.y);
        if(dX2 < dX || dY2 < dX)
        {
            donnee = &donneeRecu;
        }
    }
    if(!donneeRecu.equals(lastDonnee))
    {
        envoyerDonnee(donneeRecu);
    }
}

Case * PDAVictime::getCase()
{
    return maCase;
}

void PDAVictime::exclureDeSimulation()
{
    Agent::exclureDeSimulation();
    cout << "_______________________________" << endl;
    cout << "Victime " << nom << " est sauve" << endl;
    cout << "_______________________________" << endl;
}

void PDAVictime::setPriseEnCharge()
{
    priseEnCharge = true;
}

