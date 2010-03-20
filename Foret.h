/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pag�s  //
/////////////////////

#if !defined(_FORET_H)
#define _FORET_H

class Case;

class Foret
{
private:
    Case*** matrice;
public:
    static const int NB_LIGNES = 10;
    static const int NB_COLONNES = 10;
    Foret();
    ~Foret();
    void afficher();
	Case& getCase(int x, int y);
};

#endif  //_FORET_H
