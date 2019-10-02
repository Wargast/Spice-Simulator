// echelon.h: interface for the echelon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ECHELON_H__82D1855F_F156_4996_9A3D_C8041269BEFA__INCLUDED_)
#define AFX_ECHELON_H__82D1855F_F156_4996_9A3D_C8041269BEFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "aperiodique.h"

class echelon  : public aperiodique
{
public:
	virtual float Ve(float t);
	echelon(float V0= 1, float phi = 0);
	virtual ~echelon();

};

#endif // !defined(AFX_ECHELON_H__82D1855F_F156_4996_9A3D_C8041269BEFA__INCLUDED_)
