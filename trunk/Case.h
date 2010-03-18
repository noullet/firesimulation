//////////////////////////////////
// Fire Simulation  //
// Nicolas Noullet  //
// Bertrand Pagès //
//////////////////////////////////


#if !defined(_CASE_H)
#define _CASE_H

#include "Donnee.h"
#include "Foret.h"

class Case
{
public:
	bool feu;
	int x;
	int y;
	void diffuserFeu();
	bool estFeu();
	void setFeu(bool estFeu);
	int getX();
	int getY();
	Donnee decouvrir();
	Foret getForet();
};

#endif  //_CASE_H
