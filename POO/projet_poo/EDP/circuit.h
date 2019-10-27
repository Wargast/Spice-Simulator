#ifndef CIRCUIT_H
#define CIRCUIT_H


#include <fstream>
using namespace std;
#include <iostream>

#include "EDP1.h"
#include "../source/source.h"

class circuit : public EDP1
{
public:
	virtual float func(float Un, float t)const = 0;
	void exportSrc();

	circuit(float u0, float tmax, float h, Source* src );
	virtual ~circuit();

protected:
  Source* m_src;


};

#endif
