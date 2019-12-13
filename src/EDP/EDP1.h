#ifndef EDP1_H
#define EDP1_H


#include "EDP.h"

using Eigen::MatrixXd;

class EDP1 : public EDP
{
public:
	// virtual void euler() ;
	virtual void heun();
	virtual void RK4();

	EDP1(float u0, float tmax, float h);
	virtual ~EDP1();

protected:
	virtual float func(float Un, float t) = 0;
	virtual void update_Unp(float t);

};

#endif
