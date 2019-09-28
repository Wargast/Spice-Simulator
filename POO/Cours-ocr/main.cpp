#include <iostream>
#include <vector>
#include "vehicule.hpp"

int main()
{
  std::vector<vehicule*> listVehicule;

 listVehicule.push_back(new Voiture(12000,5));
 listVehicule.push_back(new Moto(22000,340));

 listVehicule[0]->affiche();
 std::cout  << listVehicule[0]->nbrRoues() << "\n";
 listVehicule[1]->affiche();


 return 1;
}
