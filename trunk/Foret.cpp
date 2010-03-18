/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#include "Foret.h"
#include "Case.h"
#include "Matrix.h"

Foret::Foret()
{

}
Case Foret::getCase(int x, int y)
{
    return this->matrice[x][y];
}

