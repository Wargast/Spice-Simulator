// creneau.h: interface for the creneau class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRENEAU_H__6CB20DD5_C6DC_4BCC_B4F2_DFD7DD916743__INCLUDED_)
#define AFX_CRENEAU_H__6CB20DD5_C6DC_4BCC_B4F2_DFD7DD916743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "aperiodique.h"



class creneau  : public aperiodique
{
public:
	virtual float Ve(float t)const;
	creneau(float duree = 10, float V0=1, float phi=0);
	virtual ~creneau();
private :
	float m_duree;

};

#endif // !defined(AFX_CRENEAU_H__6CB20DD5_C6DC_4BCC_B4F2_DFD7DD916743__INCLUDED_)
