// EDP_2.h: interface for the EDP_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDP_2_H__290EFD0B_AB21_4012_9A77_DA3B51EFE44C__INCLUDED_)
#define AFX_EDP_2_H__290EFD0B_AB21_4012_9A77_DA3B51EFE44C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EDP.h"

class EDP_2 : public EDP
{
public:
	virtual void euler() ;
	virtual float func(float Un, float t)const = 0;

	EDP_2(float u0, float tmax, float h);
	virtual ~EDP_2();

protected:
	float m_tmax;
	float m_h;
	float m_u0;


};

#endif // !defined(AFX_EDP_2_H__290EFD0B_AB21_4012_9A77_DA3B51EFE44C__INCLUDED_)
