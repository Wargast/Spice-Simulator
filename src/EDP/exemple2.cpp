#include "exemple2.h"

exemple2::exemple2(float u0, float u0p, float tmax, float h, float lambda) :
EDP_2(u0, u0p, tmax, h), m_lambda(lambda)
{

}

exemple2::~exemple2()
{

}

float exemple2::func(float Un, float t)
{
  return (-m_lambda * Un);
}
