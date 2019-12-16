// EDP.cpp: implementation of the EDP class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "EDP.h"
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EDP::EDP(float u0, float tmax, float h):m_tmax(tmax), m_h(h), m_u0(u0)
{
	m_n = m_tmax/m_h;
}

EDP::~EDP()
{
}

void EDP::euler()
{

	ofstream fichier_euler("data/euler.txt");
	if(fichier_euler){

		m_n = m_tmax/m_h;

		float t=0;
		fichier_euler << t << "	" << m_Un(0,0) << endl;

		for (int i=1; i<m_n ;i++)
		{
			update_Unp(t);
			m_Un= m_Un + m_h*m_Unp;
			t = i*m_h;
			fichier_euler << t << "	" << m_Un(0,0) << endl;
		}
		fichier_euler.close();
	}
	else {
		printf("ERROR : ouverture euler.txt impossible\n");
	}
}
