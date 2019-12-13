#ifndef EDP_H
#define EDP_H

#include <Eigen/Dense> //library perttant de faire du calcul matriciel

using Eigen::MatrixXd;

class EDP
{
public:
	virtual void heun()=0;
	virtual void RK4()=0;
	void euler();
	EDP(float u0, float tmax, float h);
	virtual ~EDP();

protected:
	virtual float func(float Un, float t) = 0;

	virtual void update_Unp(float t)=0;
	float m_tmax;
	float m_h;
	float m_u0;
	int m_n;

	MatrixXd m_Un;
	MatrixXd m_Unp;

};

#endif
