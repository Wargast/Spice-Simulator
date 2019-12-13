#include "circuit2.h"
#include <iostream>
#include <fstream>
using namespace std;


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
    printf("n = %d \ntmax = %.15f \nh = %.15f \nm_u0 = %f \n\n",m_n , m_tmax, m_h, 0.0 );
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
