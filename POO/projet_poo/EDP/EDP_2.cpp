#include "EDP_2.h"
#include <iostream>
#include <fstream>
using namespace std;

EDP_2::EDP_2(float u0, float u0p, float tmax, float h)
: EDP(u0,tmax,h)
{
  MatrixXd m1(2,1);
  MatrixXd m2(2,1);
  m_Un = m1;
  m_Unp = m2;

  m_Un(1,0) = u0p;
  m_Un(0,0) = u0;

}

EDP_2::~EDP_2()
{
}

void EDP_2::update_Unp(float t)
{
  float fpp = func(m_Un(0,0),t);
  m_Unp(0,0) = m_Un(1,0);
  m_Unp(1,0) = fpp;
}


void EDP_2::heun()
{
  ofstream fichier_heun("data/heun.txt");
	if(fichier_heun){

    float t=0;
		fichier_heun << t << "	" << m_Un(0,0) << endl;

    m_n = m_tmax/m_h;

    MatrixXd A(2,2);
    A(1,0)=0;         // A = 2  0
    A(0,1)=0;         //     0  1
    A(0,0) = 2;
    A(1,1) = 1;
    MatrixXd B(2,1);
    float un1p;
    float un2p;

    for (int i=1; i<m_n ;i++)
		{
      t = i*m_h;

      update_Unp(t);

      un1p = m_Unp(0,0);
      un2p = func(m_Un(0,0) + m_h*un1p, t+m_h) ;

      B(0,0) = m_h*un1p;
      B(1,0) = un2p;

			m_Un= m_Un + m_h/2*(A*m_Unp+B);
      fichier_heun << t << "	" << m_Un(0,0) << endl;
		}


    fichier_heun.close();
  }
  else {
		printf("ERROR : ouverture heun.txt impossible\n");
	}
}

void EDP_2::RK4(){
  // A faire

}
