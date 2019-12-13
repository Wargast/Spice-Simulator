// Source.h: interface for the Source class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOURCE_H__84F29404_DEBC_4723_AD89_B173E7EC1E3C__INCLUDED_)
#define AFX_SOURCE_H__84F29404_DEBC_4723_AD89_B173E7EC1E3C__INCLUDED_

class Source
{
public:
	virtual float Ve(float t) const = 0;
	Source(float V0 = 1, float phi = 0);
	virtual ~Source();

protected:
	float m_V0;
	float m_phi;

};

#endif // !defined(AFX_SOURCE_H__84F29404_DEBC_4723_AD89_B173E7EC1E3C__INCLUDED_)
