#include "circuit.h"


circuit::circuit(float u0, float tmax, float h, Source* src):
EDP1(u0,tmax,h), m_src(src)
{
  // printf("-----Using circuit constructor-----\n");
}

circuit::~circuit()
{
}

void circuit::exportSrc()
{
  ofstream fichier_export("data/src.txt");
  if (fichier_export)
  {
    printf("---- Ouvertrure fichier_export ----\n");

    // int p =  m_tmax/m_h;
    printf("n = %d\ntmax = %.15f \nh = %.15f\nm_u0 = %f\n\n",m_n , m_tmax, m_h, m_u0 );
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
