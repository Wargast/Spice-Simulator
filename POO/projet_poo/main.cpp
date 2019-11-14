#include <iostream>
#include "include.h"

using namespace std;

#include <Eigen/Dense>


using Eigen::MatrixXd;

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
	src = new rectang(0.00000005, 1.0, 0.0, 1.0/10000000.0);
	float tmax = 0.0000005;
	float h = 0.000000000001 ;
	// std::cout << "h = " << '\n';
	// std::cin >> h;
	float R1 = 50;
	float R2 = 180;
	float C = 0.0000000001;
	float L = 0.000001;
	// float U0 = src->Ve(0);

	float lambda = 1;
	// std::cout << "lambda" << '\n';
	// std::cin >> lambda;

	float U0 = 0;
	// std::cout << "u0" << '\n';
	// std::cin >> U0;


	float U0p = 0;
	// std::cout << "u0p" << '\n';
	// std::cin >> U0p;
	// exemple2 montage(U0,U0p, 25.0, 0.01, lambda);
	RLC montage(U0,U0p, tmax, h,src,R1,L,C);
	// RCD montage(U0, tmax, h,R1, R2, C, src);
	montage.heun();
	montage.exportSrc();
	//
	// float vect1[3] = {1.2,1.3,1.4};
	// float vect2[3] = {1,1,1};
	//
	// MatrixXd m_Un(1,3);
	// m_Un(0,0)=0;
	// m_Un(0,1)=1;
	// m_Un(0,2)=2;
	//
	//
	// std::cout <<2*m_Un << '\n';

	return 0;
}


//RC(float u0, float tmax, float h, float R, float C, Source* src);
