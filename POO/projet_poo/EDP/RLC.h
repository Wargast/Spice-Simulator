#ifndef RLC_H
#define RLC_H

#include "circuit2.h"

class RLC : public circuit2 {
private:
	float m_R;
	float m_L;
	float m_C;

public:
	RLC (float u0,float u0p, float tmax, float h, Source* src,float R, float L, float C);
	virtual ~RLC ();
	virtual float func(float Un, float t);

};


#endif
