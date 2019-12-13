#include "RCD.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


RCD::RCD(float u0, float tmax, float h, float R1, float R2, float C, Source* src, float Vbe):
circuit(u0, tmax, h, src), m_R1(R1), m_R2(R2), m_C(C), m_Vbe(Vbe)
{
}
RCD::~RCD()
{
}


float RCD::func(float Un, float t)
{
	float Ve = m_src->Ve(t);
	if ( Ve > m_Vbe)
	{
		float result = ( -(1/(m_R1*m_C)+1/(m_R2*m_C))*Un + (Ve- m_Vbe)/(m_R1*m_C));
		// printf("result = %f\n", result);
		return result;
	}
	else
	{
		float result = -Un/(m_R2*m_C);
		// printf("result = %f\n", result);
		return result;
	}
}
