#include "RC.h"
#include <fstream>
using namespace std;
#include <iostream>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RC::RC(float u0, float tmax, float h, float R, float C, Source* src):
circuit(u0, tmax, h, src), m_R(R), m_C(C)
{
}

RC::~RC()
{

}

float RC::func(float Un, float t)const
{
	return (m_src->Ve(t) - Un)/m_R/m_C;
}
