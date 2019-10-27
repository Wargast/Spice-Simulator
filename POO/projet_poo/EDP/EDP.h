#ifndef EDP_H
#define EDP_H


class EDP
{
public:
	virtual void euler()= 0;
	virtual float func(float Un, float t)const = 0;
	EDP();
	virtual ~EDP();

};

#endif
