// sinus.h: interface for the sinus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINUS_H__B1E079D4_FE8B_4491_9C6B_DDF14BE2CB8A__INCLUDED_)
#define AFX_SINUS_H__B1E079D4_FE8B_4491_9C6B_DDF14BE2CB8A__INCLUDED_

#include "periodique.h"

class sinus  : public periodique
{
public:
	virtual float Ve(float t)const;
	sinus(float	V0=0, float phi=0, float T = 0);
	virtual ~sinus();

};

#endif // !defined(AFX_SINUS_H__B1E079D4_FE8B_4491_9C6B_DDF14BE2CB8A__INCLUDED_)
