#ifndef RCD_H
#define RCD_H

#include "circuit.h"
class RCD : public circuit
{
public:
	RCD(float u0, float tmax, float h, float R1, float R2, float C, Source* src, float Vbe = 0.6);
	virtual ~RCD();
	virtual float func(float Un, float t)const;

private :
float m_R1;
float m_R2;
float m_Vbe;
float m_C;

};

#endif
