#include <iostream>
#include "mobile.h"
using namespace std;

int main(){
	float vit=2;
	int imm = 0000;
	int mode = 0;
	float price;
	int type;
	float conso;
	float masse;
	mobile *p_mobile;
	while(mode !=2)
	{
		std::cout << "que voulez vous générer ?\n voiture(0)\n deux-roues(1)\n quitter(2)" << '\n';;
		cin >> mode;
		switch (choix) {
			case 0:
			std::cout << "vitesse de la voiture :" << '\n';
			std::cin >> vit;
			std::cout << "masse de la voiture :" << '\n';
			std::cin >> masse;
			std::cout << "conso de la voiture" << '\n';
			std::cin >> conso;
			p_mobile = new voiture(conso,vit,masse);
			break;

			case 1:
			std::cout << "vitesse du deux_roues :" << '\n';
			std::cin >> vit;
			std::cout << "Prix du deux_roues :" << '\n';
			std::cin >> price;
			std::cout << "type du deux_roues : 1- essence  2-électrique" << '\n';
			std::cin >> type;
		  p_mobile = 	new deux_roues(price, type, vit);
			break;

			case 2:
			break;

			default :
			std::cout << "Votre choix ne correspond pas à ceux proposés. veuillez recommencer." << '\n';
			}

	}





	cout << vit <<endl;


	return 0;
}
