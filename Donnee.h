/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_DONNEE_H)
#define _DONNEE_H

#include <iostream>
using namespace std;

class Donnee
{
public:
	string type;
	int x;
	int y;
	bool traite;
	string pompier;
	Donnee(string aType, int aX, int aY): type(aType), x(aX), y(aY), traite(false), pompier(""){};
	void Donnee::afficher()
	{
        cout << type << "(" << x << ','<< y << ")" << endl;
	}
	bool Donnee::equals(Donnee * d)
	{
	    if(d != NULL)
        {
            if(type != (*d).type)
                return false;
            if(x != (*d).x)
                return false;
            if(y != (*d).y)
                return false;
            return true;
        }
        return false;
    }
};

#endif  //_DONNEE_H
