/////////////////////
// Fire Simulation //
// Nicolas Noullet //
// Bertrand Pagès  //
/////////////////////

#if !defined(_MOBILE_H)
#define _MOBILE_H

class Mobile
{
public:
	virtual void seDeplacer(string direction) = 0;
	virtual string getDirection() = 0;
};

#endif  //_MOBILE_H
