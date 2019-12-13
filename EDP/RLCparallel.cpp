#include "RLCparallel.h"
#include <iostream>
#include <fstream>
using namespace std;



RLCparallel::RLCparallel(float u0,float u0p, float tmax, float h, Source* src,float R, float L, float C):
circuit2(u0,u0p, tmax, h, src), m_R(R), m_L(L), m_C(C)
{
}

RLCparallel::~RLCparallel(){}

float RLCparallel::func(float Un, float t)
{
  float Vcp = (m_src->Ve(t+m_h) - m_src->Ve(t))/m_h;
  return ( (Vcp - m_Un(1,0))/(m_R*m_C) - (m_Un(0,0)/(m_L*m_C)) );
}

float RLCparallel::func2(float Un, float Unp, float t)
{
  float Vcp = (m_src->Ve(t+m_h) - m_src->Ve(t))/m_h;
  return ( (Vcp - m_Un(1,0))/(m_R*m_C) - (m_Un(0,0)/(m_L*m_C)) );
}
