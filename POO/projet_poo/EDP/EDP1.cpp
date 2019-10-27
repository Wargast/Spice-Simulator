// EDP.cpp: implementation of the EDP class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "EDP1.h"
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EDP1::EDP1(float u0, float tmax, float h):
m_tmax(tmax), m_h(h), m_u0(u0)
{
	// printf("-----Using EDP1 constructor----\n");
}

EDP1::~EDP1()
{

}



void EDP1::euler()
{

	ofstream fichier_euler("data/euler.txt");
	if(fichier_euler){
		printf("---- ouverture fichier_euler ----\n");

		m_n = m_tmax/m_h;
		printf("n = %d\ntmax = %.15f \nh = %.15f\n\n", m_n, m_tmax, m_h );

		float u=m_u0;
		float t=0;
		fichier_euler << t << "	" << u << endl;
		int i;
		for (i=1; i<m_n ;i++)
		{
			u= u + m_h*func(u,t);
			t = i*m_h;
			fichier_euler << t << "	" << u << endl;
		}
		fichier_euler.close();
	}
	else {
		printf("ERROR : ouverture euler.txt impossible\n");
	}
}
