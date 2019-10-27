#ifndef RC_H
#define RC_H

#include "circuit.h"
class RC : public circuit
{
public:
	RC(float u0, float tmax, float h, float R, float C, Source* src);
	virtual ~RC();
	virtual float func(float Un, float t)const;

private :
float m_R;
float m_C;

};

#endif
