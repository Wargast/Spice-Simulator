#ifndef RLCPARALLEL_H
#define RLCPARALLEL_H

#include "circuit2.h"

class RLCparallel : public circuit2 {
private:
	float m_R;
	float m_L;
	float m_C;

public:
	RLCparallel (float u0,float u0p, float tmax, float h, Source* src,float R, float L, float C);
	virtual ~RLCparallel ();
	virtual float func(float Un, float t);

};

#endif
