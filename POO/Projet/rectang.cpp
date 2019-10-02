// rectang.cpp: implementation of the rectang class.
//
//////////////////////////////////////////////////////////////////////

#include "rectang.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

rectang::rectang(float T , float V0, float phi, float periode) : m_T(T),periodique(periode,V0,phi)
{

}

rectang::~rectang()
{

}

float rectang::Ve(float t)
{
	if(t<0)
		return 0;

	else if (fmod(t,m_periode)> m_phi && fmod(t,m_periode) < m_phi + m_T)
	{
		return m_V0;
	}
	else
		return 0;

}