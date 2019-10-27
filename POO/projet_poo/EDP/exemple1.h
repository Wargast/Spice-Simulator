#ifndef EXEMPLE1_H
#define EXEMPLE1_H

#include "EDP1.h"

class exemple1 : public EDP1
{
public:
	//meow
	exemple1(float u0, float t_max, float h);
	virtual ~exemple1();
	virtual float func(float Un, float t)const;
	// meow


};

#endif
