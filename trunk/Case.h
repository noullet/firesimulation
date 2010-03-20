/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_CASE_H)
#define _CASE_H

#include "Donnee.h"
#include "Foret.h"
#include "Agent.h"

class Case
{
protected:
    Foret& foret;
    Agent* agent;
	int feu;
	int x;
	int y;
public:
    Case(int aX, int aY, Foret& aForet): x(aX), y(aY), foret(aForet), agent(NULL), feu(0) {};
	void diffuserFeu();
	int getFeu();
	void allumerFeu();
	void eteindreFeu();
	void bruler();
	int getX();
	int getY();
	Donnee decouvrir();
	Foret getForet();
	Agent* getAgent();
	void setAgent(Agent *aAgent);
	char getEtat();
};

#endif  //_CASE_H
