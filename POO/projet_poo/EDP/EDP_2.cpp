#include "EDP_2.h"
#include <iostream>
#include <fstream>
using namespace std;
using Eigen::MatrixXd;

EDP_2::EDP_2(float u0, float u0p, float tmax, float h)
: m_tmax(tmax), m_h(h)
{
  MatrixXd m1(2,1);
  MatrixXd m2(2,1);
  m_Un = m1;
  m_Unp = m2;
  // std::cout << type(m_Un) << '\n';

  m_Un(0,0) = u0p;
  m_Un(1,0) = u0;
  std::cout << m_Un << '\n';
  std::cout << "fin Un" << '\n';
  // std::cout << m_Unp << '\n';
}

EDP_2::~EDP_2()
{
}

void EDP_2::update_Unp(float t)
{
  float fpp = func(m_Un(1,0),t);
  m_Unp(1,0) = m_Un(0,0);
  m_Unp(0,0) = fpp;
}

void EDP_2::euler()
{
  ofstream fichier_euler2("data/euler.txt");
	if(fichier_euler2){
    float t=0;
		fichier_euler2 << t << "	" << m_Un(1,0) << endl;

    m_n = m_tmax/m_h;

    for (int i=1; i<m_n ;i++)
		{
      // std::cout << m_Un << "Unp" << m_Unp<< '\n'<< endl;
      update_Unp(t);
			m_Un= m_Un + m_h*m_Unp;
			t = i*m_h;
			fichier_euler2 << t << "	" << m_Un(1,0) << endl;
		}


    fichier_euler2.close();
  }
  else {
		printf("ERROR : ouverture euler2.txt impossible\n");
	}
}


void EDP_2::heun()
{
  ofstream fichier_heun("data/euler.txt");
	if(fichier_heun){
    float t=0;
		fichier_heun << t << "	" << m_Un(1,0) << endl;

    m_n = m_tmax/m_h;

    MatrixXd A(2,2);
    A(1,0)=0;
    A(0,1)=0;
    MatrixXd B(2,1);
    float un1p;
    float un2p;

    for (int i=1; i<m_n ;i++)
		{
      // std::cout << m_Un << "Unp" << m_Unp<< '\n'<< endl;
      t = i*m_h;

      update_Unp(t);
      un1p = m_Unp(1,0);
      un2p = func(m_Un(1,0) + m_h*un1p, t+m_h) ;
      A(0,0) = 1;
      A(1,1) = 2;

      B(0,0) = un2p;
      B(1,0) = m_h*un1p;
      // std::cout << "res" << '\n';
      // std::cout << A*m_Unp << '\n';
			m_Un= m_Un + m_h/2*(A*m_Unp+B);
      fichier_heun << t << "	" << m_Un(1,0) << endl;
		}


    fichier_heun.close();
  }
  else {
		printf("ERROR : ouverture heun.txt impossible\n");
	}
}
void EDP_2::RK4(){


}


circuit2::circuit2(float u0,float u0p, float tmax, float h, Source* src):
EDP_2(u0, u0p,tmax, h), m_src(src)
{
}


void circuit2::exportSrc()
{
  ofstream fichier_export("data/src.txt");
  if (fichier_export)
  {
    printf("---- Ouvertrure fichier_export ----\n");

    // int p =  m_tmax/m_h;
    printf("n = %d\ntmax = %.15f \nh = %.15f\nm_u0 = %f\n\n",m_n , m_tmax, m_h, 0.0 );
    float t;
    for (int i=0; i<m_n ;i++)
  	{
  		t = i*m_h;
  		fichier_export << t << "	" << m_src->Ve(t) << endl;

  	}
    fichier_export.close();
  }
  else{
    printf("ERROR : ouverture src.txt impossible\n");
  }
}


circuit2::~circuit2(){}


RLC::RLC(float u0,float u0p, float tmax, float h, Source* src,float R, float L, float C):
circuit2(u0,u0p, tmax, h, src), m_R(R), m_L(L), m_C(C)
{
}

RLC::~RLC(){}


float RLC::func(float Un, float t)
{
  return (-m_R/m_L * m_Un(0,0) +(m_src->Ve(t) - Un )/m_L/m_C   );
}
