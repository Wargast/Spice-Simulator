
#ifndef EDP2_H
#define EDP2_H

#include "EDP.h"
#include <Eigen/Dense>
#include "../source/source.h"


using Eigen::MatrixXd;

class EDP_2 : public EDP
{
public:
	virtual void euler();
	virtual void heun();
	virtual void RK4();

	void update_Unp(float t);

	EDP_2(float u0,float u0p, float tmax, float h);
	virtual ~EDP_2();

protected:
	virtual float func(float Un, float t) = 0;
	float m_tmax;
	float m_h;
	int m_n;
	MatrixXd m_Un;

	MatrixXd m_Unp;


};

class circuit2 : public EDP_2 {
protected:
	Source* m_src;

public:
	void exportSrc();
	circuit2 (float u0,float u0p, float tmax, float h,Source* src);
	virtual ~circuit2 ();
};

class RLC : public circuit2 {
private:
	float m_R;
	float m_L;
	float m_C;

public:
	RLC (float u0,float u0p, float tmax, float h, Source* src,float R, float L, float C);
	virtual ~RLC ();
	virtual float func(float Un, float t);

};


#endif
