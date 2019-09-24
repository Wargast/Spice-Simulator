#include <iostream>
#include "mobile.h"
using namespace std;

int main(){
	float vit=2;
	int imm = 0000;
	mobile voiture1(vit,imm);

	vit = voiture1.get_vit();

	cout << vit <<endl;


	return 0;
}
