// exemple1.cpp: implementation of the exemple1 class.
//
//////////////////////////////////////////////////////////////////////

#include "exemple1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

exemple1::exemple1(float u0,float t_max, float h) : EDP1(u0,t_max,h)
{

}

exemple1::~exemple1()
{

}

float exemple1::func(float Un, float t)
{
	return -3*Un-3*t;
}