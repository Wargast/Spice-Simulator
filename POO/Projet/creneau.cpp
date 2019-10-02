// creneau.cpp: implementation of the creneau class.
//
//////////////////////////////////////////////////////////////////////

#include "creneau.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

creneau::creneau(float duree, float V0, float phi): m_duree(duree), aperiodique(V0, phi)
{

}

creneau::~creneau()
{

}

float creneau::Ve(float t)
{
	if (t>=m_phi && t<=m_phi+m_duree)
		return m_V0;
	
	else
		return 0;

}