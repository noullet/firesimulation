/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_FORET_H)
#define _FORET_H
#include <string>
using namespace std;

class Case;

class Foret
{
private:
    Case*** matrice;
public:
    static const int NB_LIGNES = 15;
    static const int NB_COLONNES = 15;
    Foret();
    ~Foret();
    void afficher();
	Case& getCase(int x, int y);
	bool verifierDirection(int x,int y,string direction);
	Case * getLieuSur();
};

#endif  //_FORET_H
