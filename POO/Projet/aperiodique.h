// aperiodique.h: interface for the aperiodique class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APERIODIQUE_H__704B03FF_9EA1_45F2_8140_BB048E62301E__INCLUDED_)
#define AFX_APERIODIQUE_H__704B03FF_9EA1_45F2_8140_BB048E62301E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "source.h"
class aperiodique  : public Source
{
public:
	aperiodique(float V0 = 0, float phi = 0);
	virtual ~aperiodique();

};

#endif // !defined(AFX_APERIODIQUE_H__704B03FF_9EA1_45F2_8140_BB048E62301E__INCLUDED_)
