#ifndef EDP_H
#define EDP_H


class EDP
{
public:
	virtual void heun()=0;
	virtual void RK4()=0;
	virtual void euler()= 0;
	EDP();
	virtual ~EDP();

protected:
	virtual float func(float Un, float t) = 0;
};

#endif
