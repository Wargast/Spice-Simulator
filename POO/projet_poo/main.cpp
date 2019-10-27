#include <iostream>
#include "include.h"

using namespace std;

/*int main()
{

	//float duree;
	float V0;
	float phi;
	float pas=0.5;
	float T;
	float periode;
	ofstream fichier("D:/pooooo/sinus.txt");
	fichier << "##sinus" << endl;

	Source *signal;



	//cout << "duree ?" <<endl;
	//cin >> duree;
	//cout << "T?" << endl;
	//cin >> T;
	cout << "periode?" << endl;
	cin >> periode;
	cout << "V0 ?" << endl;
	cin >> V0;
	cout << "phi ?" << endl;
	cin >> phi;

	signal = new sinus(V0,phi,periode);


	float tableau_t[100]; // cr�e un vecteur de 100 cases
	int i;
	for (i = 0;i<100; i++)
	{
		//cout << "i   " << i <<endl;
		tableau_t[i] = i*pas;
	}

	int j;

	float ve = 0;
	float t;

	for (j=0; j<100;j++)
	{
		//cout << "j  " << j <<endl;

		//cout <<  t << endl ;
		cout << "Ve   " << signal->Ve(tableau_t[j]) << endl;
		fichier << tableau_t[j] << "	" << signal->Ve(tableau_t[j]) << endl;
	}

		cin >> phi;

	return 0;
}
*/


int main()
{
	Source* src;
	src = new creneau(0.0000001, 1, 0.00000001);

	float tmax = 0.000001;
	float h = 0.0000000001 ;
	float R1 = 36;
	flaot R2 = 180;
	float C = 0.000000001;
	float U0 = src->Ve(0);

	RCD montage(U0, tmax, h,R1, R2, C, src);
	montage.euler();
	montage.exportSrc();

	return 0;
}


//RC(float u0, float tmax, float h, float R, float C, Source* src);
