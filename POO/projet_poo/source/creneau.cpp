// creneau.cpp: implementation of the creneau class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "creneau.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

creneau::creneau(float duree, float V0, float phi): m_duree(duree), aperiodique(V0, phi)
{
	cout<<"duree   "<<m_duree <<"    phi   "<<m_phi<<endl;
}

creneau::~creneau()
{

}

float creneau::Ve(float t)const
{
	if (t>=m_phi && t<=m_phi+m_duree)
		return m_V0;
	
	else
		return 0;

}