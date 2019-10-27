#ifndef EDP1_H
#define EDP1_H


#include "EDP.h"

class EDP1 : public EDP
{
public:
	virtual void euler() ;
	virtual float func(float Un, float t)const = 0;

	EDP1(float u0, float tmax, float h);
	virtual ~EDP1();

protected:
	float m_tmax;
	float m_h;
	float m_u0;
	int m_n;


};

#endif
