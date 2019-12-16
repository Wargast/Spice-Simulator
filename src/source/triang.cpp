// triang.cpp: implementation of the triang class.
//
//////////////////////////////////////////////////////////////////////

#include "triang.h"
#include <cmath>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

triang::triang(float V0, float phi, float periode):periodique(periode,V0,phi)
{

}

triang::~triang()
{

}

float triang::Ve(float t)const
{
	float t2 = t-m_phi;
	if( t2<0)
	{
		return 0;
	}

	else if (fmod(t2,m_periode) >= 0 && (fmod(t2,m_periode) <= m_periode/2) )
	{
		return 2*m_V0/m_periode*(fmod(t2,m_periode));
	}

	else
	{
		return -2*m_V0/m_periode*(fmod(t2,m_periode))+2*m_V0;
	}

}
