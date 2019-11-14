#ifndef rungeK_h
#define rungeK_h

class rungeK {
protected:
  float m_u0;
  float m_h;
  float m_tmax;
  /* data */

public:
  virtual float func() = 0;
  virtual float solveRK() = 0;
  rungeK (float u0, float h,float tmax);
  virtual ~rungeK ();
};


#endif
