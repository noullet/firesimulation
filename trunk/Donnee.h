/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_DONNEE_H)
#define _DONNEE_H

#include <string>
using namespace std;

class Donnee
{
public:
	string type;
	int x;
	int y;
	Donnee(string aType, int aX, int aY): type(aType), x(aX), y(aY){};
};

#endif  //_DONNEE_H
