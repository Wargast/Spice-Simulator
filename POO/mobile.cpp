#include <iostream>
#include "mobile.h"

using namespace std;

//////////// classe mobile ///////////

mobile::mobile(float vitesse, int immatriculation){
	m_vitesse = vitesse;
	m_immatriculation = immatriculation;
}
float mobile::calcul_position(float tps){
	return m_vitesse * tps;
}


void mobile::set_vit(float vitesse){
	m_vitesse = vitesse;
}
float mobile::get_vit(){
	return m_vitesse;
}

void mobile::set_pos(float position){
	m_position = position;
}
float mobile::get_pos(){
	return m_position;
}

///////////  classe voiture ///////////////



voiture::voiture(float conso,float vit, float masse): mobile(vit) , m_consommation(conso), m_masse(masse)
{

}

float voiture::get_conso(){
	return m_consommation;
}
void voiture::set_conso(float conso){
	m_consommation = conso;
}

float voiture::get_masse(){
	return m_masse; 
}
void voiture::set_masse(float masse){
	m_masse = masse; 
}



