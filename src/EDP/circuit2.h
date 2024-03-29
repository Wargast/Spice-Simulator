#ifndef CIRCUIT2_H
#define CIRCUIT2_H

#include "EDP_2.h"
#include "../source/source.h" //pour pouvoir utiliser les source dans nos circuit

class circuit2 : public EDP_2 {

public:
	void exportSrc();
	circuit2 (float u0,float u0p, float tmax, float h,Source* src);
	virtual ~circuit2 ();

protected:
	virtual float func(float Un, float t) = 0;
	virtual float func2(float Un, float Unp, float t) = 0;
  Source* m_src;

};


#endif
