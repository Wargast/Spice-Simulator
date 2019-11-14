#ifndef EXEMPLE2_H
#define EXEMPLE2_H

#include "EDP_2.h"

class exemple2 : public EDP_2
{
private:
  virtual float func(float Un, float t);
  float m_lambda;

public:

  exemple2(float u0, float u0p, float tmax, float h, float lambda);
  virtual ~exemple2();
};

#endif
