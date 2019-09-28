#include <iostream>
#include "vehicule.hpp"

vehicule::vehicule(int prix): m_prix(prix)
{}
void vehicule::affiche()const
{
  std::cout << "ceci est un véhicule coutant "<< m_prix << " euros." << '\n';
}
vehicule::~vehicule()
{}

/*******************************/

Voiture::Voiture(int prix, int portes): vehicule(prix) , m_portes(portes)
{}
void Voiture::affiche() const
{
  std::cout << "Ceci est une voiture qui a " << m_portes << " portes et qui coute "<< m_prix << " euros." << '\n';
}
int Voiture::nbrRoues() const
{
    return 4;
}
Voiture::~Voiture()
{}

/********************************/
Moto::Moto(int prix, double vitesseMax): vehicule(prix), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
  std::cout << "Ceci est une moto qui peut rouler jusqu'a " << m_vitesse << " Km/h et qui coute " << m_prix << " euros." << '\n';
}
int Moto::nbrRoues() const
{
    return 2;
}
Moto::~Moto()
{}

/**********************************/


Camion::Camion(int prix, int poids): vehicule(prix), m_poids(poids)
{}
Camion::~Camion()
{}
int Camion::nbrRoues() const
{
    return 10;
}
void Camion::affiche() const
{
  std::cout << "ceci est un camion qui pèse " << m_poids << " T et qui coute " << m_prix << "euros."<< '\n';
}
