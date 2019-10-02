#include <iostream>
#include "duree.hpp"

Duree::Duree(int heure, int min, int sec): m_heure(heure), m_min(min), m_sec(sec)
{
  m_min += sec/60;
  m_sec %= 60;
  m_heure += min/60;
  m_min %= 60;
}

Duree::~Duree()
{}

void Duree::affiche() const
{
  std::cout << "h: " << m_heure << " min: " << m_min << " sec:" << m_sec << '\n';
}

void Duree::operator+=(Duree const& b)
{
  m_sec += b.m_sec;
  m_min += m_sec/60 + b.m_min;
  m_sec %= 60;

  m_heure += b.m_heure + m_min/60;
  m_min %= 60;

}
bool operator==(Duree const& a, Duree const& b)
{
  return (a.m_heure == b.m_heure && a.m_min == b.m_min && a.m_sec == b.m_sec);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b); //On utilise l'opérateur == qu'on a défini précédemment !
}
bool operator<(Duree const& a, Duree const& b)
{
  if (a.m_heure < b.m_heure)
    return true;
  else if(a.m_heure == b.m_heure && a.m_min < b.m_min)
    return true;
  else if (a.m_heure == b.m_heure && a.m_min == b.m_min && a.m_sec < b.m_sec)
    return true;
  else
    return false;
}

bool operator<=(Duree const& a, Duree const& b)
{
  return (a<b || a==b);
}

bool operator>(Duree const& a, Duree const& b)
{
  return !(a<=b);
}

bool operator>=(Duree const& a, Duree const& b)
{
  return (a>b || a==b);
}

Duree operator+(Duree const& a, Duree const& b)
{
  Duree resulat;
  resulat +=a;
  resulat +=b;
  // resulat.m_sec = a.m_sec + b.m_sec;
  // resulat.m_min += resulat.m_sec/60 + b.m_min + a.m_min;
  // resulat.m_sec %= 60;
  //
  // resulat.m_heure = a.m_heure + b.m_heure + resulat.m_min/60;
  // resulat.m_min %= 60;

  return resulat;
}
