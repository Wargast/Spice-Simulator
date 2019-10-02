#include "iostream"
#include "duree.hpp"

int main(int argc, char const *argv[]) {

  Duree d1(0,1,29), d2(0, 1,30) ;
  Duree res;
  res = d1 + d2;
  bool b(d1>=d2);

  std::cout << b << '\n';
  d2.affiche();
  d1.affiche();
  res.affiche();
  return 0;
}
