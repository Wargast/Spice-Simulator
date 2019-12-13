// sinus.cpp: implementation of the sinus class.
//
//////////////////////////////////////////////////////////////////////

#include "sinus.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

sinus::sinus(float V0,float phi,float T):periodique(T,V0,phi)
{

}

sinus::~sinus()
{

}

float sinus::Ve(float t)const
{
	return m_V0*cos(2*3.1415/m_periode*t+m_phi);

}