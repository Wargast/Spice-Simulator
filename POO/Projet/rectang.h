// rectang.h: interface for the rectang class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANG_H__5C3D4D28_D665_4D4A_B8D3_D4D389969BA7__INCLUDED_)
#define AFX_RECTANG_H__5C3D4D28_D665_4D4A_B8D3_D4D389969BA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "periodique.h"

class rectang  : public periodique
{
public:
	virtual float Ve(float t);
	rectang(float T = 1, float V0=0, float phi=0, float periode=1);
	virtual ~rectang();
private : float m_T;

};

#endif // !defined(AFX_RECTANG_H__5C3D4D28_D665_4D4A_B8D3_D4D389969BA7__INCLUDED_)
