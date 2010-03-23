/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_CAPTEUR_H)
#define _CAPTEUR_H

#include "Robot.h"
#include "Donnee.h"

class Capteur : public Robot
{
public:
    Capteur(string name,Case* maCase) : Robot(name, maCase) {};
    void exclureDeSimulation()
	{
        Agent::exclureDeSimulation();
        cout << "_______________________________" << endl;
        cout << "Capteur " << nom << " grille" << endl;
        cout << "_______________________________" << endl;
    }
};

#endif  //_CAPTEUR_H
