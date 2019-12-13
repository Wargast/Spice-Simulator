#include "RLC.h"
#include <iostream>
#include <fstream>
using namespace std;



RLC::RLC(float u0,float u0p, float tmax, float h, Source* src,float R, float L, float C):
circuit2(u0,u0p, tmax, h, src), m_R(R), m_L(L), m_C(C)
{
}

RLC::~RLC(){}

float RLC::func(float Un, float t)
{
  return (-m_R/m_L * m_Un(0,0) +(m_src->Ve(t) - Un )/m_L/m_C   );
}
float RLC::func2(float Un, float Unp, float t)
{
  return (-m_R/m_L * Un +(m_src->Ve(t) - Un )/m_L/m_C   );
}
