/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pag�s  //
/////////////////////

#if !defined(_CAPTEUR_H)
#define _CAPTEUR_H

#include "Robot.h"
#include "Donnee.h"

class Capteur : public Robot
{
public:
    Capteur(string name,Case* maCase) : Robot(name, maCase) {};
};

#endif  //_CAPTEUR_H
