// triang.cpp: implementation of the triang class.
//
//////////////////////////////////////////////////////////////////////

#include "triang.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

triang::triang(float V0, float phi, float periode):periodique(periode,V0,phi)
{

}

triang::~triang()
{

}

float triang::Ve(float t)
{
	if( t<0)
	{
		return 0;
	}
	
	else if (m_phi <= fmod(t,m_periode) <= m_periode/2 + m_phi)
	{
		return 2*m_V0/m_periode*t;
	}
	
	else
	{
		return -2*m_V0/m_periode*t;
	}

}