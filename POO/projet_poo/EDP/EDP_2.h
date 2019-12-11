
#ifndef EDP2_H
#define EDP2_H

#include "EDP.h"
#include "../source/source.h" //pour pouvoir utiliser les source dans nos circuit


using Eigen::MatrixXd;

class EDP_2 : public EDP
{
public:
	// virtual void euler();
	virtual void heun();
	virtual void RK4();


	EDP_2(float u0,float u0p, float tmax, float h);
	virtual ~EDP_2();

protected:
	virtual void update_Unp(float t);
	virtual float func(float Un, float t) = 0;
	// float m_tmax;
	// float m_h;
	// int m_n;
	// MatrixXd m_Un;
	// MatrixXd m_Unp;

};

#endif
