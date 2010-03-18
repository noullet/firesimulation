/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_FORET_H)
#define _FORET_H

class Case;

class Foret
{
private:
    static const int NB_LIGNES = 10;
    static const int NB_COLONNES = 10;
    Case*** matrice;
public:
    Foret();
    ~Foret();
    void afficher();
	Case getCase(int x, int y);
};

#endif  //_FORET_H
