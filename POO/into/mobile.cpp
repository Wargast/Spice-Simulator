#include <iostream>
#include "mobile.h"

using namespace std;

//////////// classe mobile ///////////

mobile::mobile(float vitesse, int immatriculation){
	m_vitesse = vitesse;
	m_immatriculation = immatriculation;
}

mobile::mobile(float vit): m_vitesse(vit)
{

}

float mobile::calcul_position(float tps){
	return m_vitesse * tps;
}


void mobile::set_vit(float vitesse){
	m_vitesse = vitesse;
}
float mobile::get_vit() const{
	return m_vitesse;
}

void mobile::set_pos(float position){
	m_position = position;
}
float mobile::get_pos() const{
	return m_position;
}

///////////  classe voiture ///////////////



voiture::voiture(float conso,float vit, float masse): mobile(vit) , m_consommation(conso), m_masse(masse)
{

}

float voiture::get_conso() const{
	return m_consommation;
}
void voiture::set_conso(float conso){
	m_consommation = conso;
}

float voiture::get_masse() const{
	return m_masse;
}
void voiture::set_masse(float masse){
	m_masse = masse;
}

/////////// classe deux_roues //////////////

deux_roues::deux_roues(float price,int type, float vit): mobile(vit) , m_price(price), m_type(type)
{

}

float deux_roues::get_price() const{
	return m_price;
}
void deux_roues::set_price(float price){
	m_price = price;
}

int deux_roues::get_type() const{
	return m_type;
}
void deux_roues::set_type(int type){
	m_type = type;
}
