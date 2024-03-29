// triang.h: interface for the triang class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIANG_H__98C64AF3_EE38_49E5_B623_07BE44FE1411__INCLUDED_)
#define AFX_TRIANG_H__98C64AF3_EE38_49E5_B623_07BE44FE1411__INCLUDED_

#include "periodique.h"

class triang  : public periodique
{
public:
	virtual float Ve(float t)const;
	triang(float V0=1, float phi=0, float periode=1);
	virtual ~triang();

};

#endif // !defined(AFX_TRIANG_H__98C64AF3_EE38_49E5_B623_07BE44FE1411__INCLUDED_)
