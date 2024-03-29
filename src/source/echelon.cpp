// echelon.cpp: implementation of the echelon class.
//
//////////////////////////////////////////////////////////////////////

#include "echelon.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

echelon::	echelon(float V0, float phi):aperiodique(V0,phi)
{

}

echelon::~echelon()
{

}


float echelon::Ve(float t) const
{
	
	if (t >= m_phi)
	{
		return m_V0;
	}
	else
	{
		return 0;
	}
}