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

void EDP1::heun()
{

	ofstream fichier_heun("data/heun.txt");
	if(fichier_heun){
		printf("---- ouverture fichier_heun ----\n");

		m_n = m_tmax/m_h;
		printf("n = %d\ntmax = %.15f \nh = %.15f\n\n", m_n, m_tmax, m_h );

		float u=m_u0;
		float t=0;
		float un1,un2;

		fichier_heun << t << "	" << u << endl;
		int i;
		for (i=1; i<m_n ;i++)
		{
			un1=func(u,t);
			un2=func(u+m_h*un1,t+m_h);
			u= u + m_h/2*(un1 + un2);
			t = i*m_h;
			fichier_heun << t << "	" << u << endl;
		}
		fichier_heun.close();
	}
	else {
		printf("ERROR : ouverture euler.txt impossible\n");
	}
}


void EDP1::RK4()
{

	ofstream fichier_RK4("data/RK4.txt");
	if(fichier_RK4){
		printf("---- ouverture fichier_RK4 ----\n");

		m_n = m_tmax/m_h;
		printf("n = %d\ntmax = %.15f \nh = %.15f\n\n", m_n, m_tmax, m_h );

		float u=m_u0;
		float t=0;
		float un1,un2,un3,un4;

		fichier_RK4 << t << "	" << u << endl;
		int i;
		for (i=1; i<m_n ;i++)
		{
			un1=func(u,t);
			un2=func(u+m_h/2*un1,t+m_h/2);
			un3=func(u+m_h/2*un2,t+m_h/2);
			un4=func(u+m_h*un3,t*m_h);
			u= u + m_h/6*(un1+un2+un3+un4);
			t = i*m_h;

			fichier_RK4 << t << "	" << u << endl;
		}
		fichier_RK4.close();
	}
	else {
		printf("ERROR : ouverture euler.txt impossible\n");
	}
}
