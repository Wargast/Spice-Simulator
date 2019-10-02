// periodique.h: interface for the periodique class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERIODIQUE_H__9E9EC518_83D7_419D_91D0_066895EEFCC4__INCLUDED_)
#define AFX_PERIODIQUE_H__9E9EC518_83D7_419D_91D0_066895EEFCC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "source.h"

class periodique : public Source 
{
public:
	periodique(float periode = 1, float V0 = 0, float phi = 0);
	virtual ~periodique();
protected:
	float m_periode;

};

#endif // !defined(AFX_PERIODIQUE_H__9E9EC518_83D7_419D_91D0_066895EEFCC4__INCLUDED_)
