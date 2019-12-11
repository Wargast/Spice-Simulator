// EDP.cpp: implementation of the EDP class.
//
//////////////////////////////////////////////////////////////////////

#include "EDP1.h"
#include <iostream>
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EDP1::EDP1(float u0, float tmax, float h):
EDP(u0,tmax,h)
{
	MatrixXd m1(1,1);
  MatrixXd m2(1,1);
  m_Un = m1;
  m_Unp = m2;

	m_Un(0,0) = u0;
}

EDP1::~EDP1()
{

}


void EDP1::update_Unp(float t)
{
  float fpp = func(m_Un(0,0),t);
  m_Unp(0,0) = fpp;
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
			un1=m_h*func(u,t);
			un2=m_h*func(u+un1/2, t+m_h/2);
			un3=m_h*func(u+un2/2, t+m_h/2);
			un4=m_h*func(u+un3, t+m_h);
			u= u + (un1 + 2*un2 + 2*un3 + un4)/6;
			t = i*m_h;

			fichier_RK4 << t << "	" << u << endl;
		}
		fichier_RK4.close();
	}
	else {
		printf("ERROR : ouverture euler.txt impossible\n");
	}
}
