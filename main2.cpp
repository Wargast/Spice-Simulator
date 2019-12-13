#include <fstream>
#include <iostream>
#include "include.h"

using namespace std;


std::string getFileContents (std::ifstream& File);
void print_lunching(string);


int main()
{
	system("chcp 65001");
	bool run = true;
	int state = 0; // etat de la machine d'etat
	int circuit_num, source_num, method_num = 0; //stockage des choix de l'utilisateur
	float U0, phi, T, period = 0; //parametres source
	float tmax, h, S0, S0p; //parametre simu
	float R,R1,R2,C,L; //parametre circuit
	Source* src;

	system("clear");// permet de clear la console (uniquement sous linux)
	print_lunching("UI_terminal/UI_0.txt"); // Ecran titre de demamrage

	while(run){ //boucle qui permet de relancer le programme quand a simulation est terminee
		switch (state) { //machine etat generale qui gere le fonctionnement du prog
			case 0://choix des circuit à simuler et de la source utilisee
			{
				print_lunching("UI_terminal/UI_1.txt"); //demande du circuit
				std::cout << "num > ";
				std::cin >> circuit_num;
				print_lunching("UI_terminal/UI_2.txt"); // demande de la source
				std::cout << "num > ";
				std::cin >> source_num;

				if(source_num<6 && 0<source_num && 0<circuit_num && circuit_num<5){ // verification que les choix de l'utilisateur sont valides
					/********* Parametrage de la source dans les cases suivants  **************/
					std::cout << "please enter the needed parameters" << '\n';
					state = source_num;
					break;
				}
				else{
					system("clear");
					std::cout << "your source or circuit are invalid !! try again" << '\n';
				}

				break;}

			case 1: // Step
			{
				std::cout << "U0  < ";
				std::cin >> U0;
				std::cout << "phi < ";
				std::cin >> phi;
				state = 6; //on va maintenant dans l'état 6 de la machine qui va veritablement simuler le cicuit

				src = new echelon(U0,phi);
				break;}

			case 2: // pulse
			{
				std::cout << "U0 < ";
				std::cin >> U0;
				std::cout << "phi < ";
				std::cin >> phi;
				std::cout << "T < ";
				std::cin >> T;
				state = 6;//on va maintenant dans l'état 6 de la machine qui va veritablement simuler le cicuit

				src = new creneau(T,U0,phi);
				break;}

			case 3: //triangular
			{
				std::cout << "U0 < ";
				std::cin >> U0;
				std::cout << "phi < ";
				std::cin >> phi;
				std::cout << "period < ";
				std::cin >> period;
				state = 6;//on va maintenant dans l'état 6 de la machine qui va veritablement simuler le cicuit

				src = new triang(U0, phi,period);
				break;}

			case 4: // Square
			{
				std::cout << "U0 < ";
				std::cin >> U0;
				std::cout << "phi < ";
				std::cin >> phi;
				std::cout << "period < ";
				std::cin >> period;
				std::cout << "T < ";
				std::cin >> T;
				state = 6;//on va maintenant dans l'état 6 de la machine qui va veritablement simuler le cicuit

				src = new rectang(T, U0, phi, period);
				break;}

			case 5: //sine
			{
				std::cout << "state = 5" << '\n';
				std::cout << "U0 < ";
				std::cin >> U0;
				std::cout << "phi < ";
				std::cin >> phi;
				std::cout << "period   < ";
				std::cin >> period;
				state = 6;//on va maintenant dans l'état 6 de la machine qui va veritablement simuler le cicuit

				src = new sinus(U0, phi,period);
				break;}

			case 6: //etat pour demander les parametres du circuit lancer la simulation
			{
				switch (circuit_num) {
					case 1: //circuit RC
					{
						std::cout << "please enter the circuit parameters :" << endl;
						std::cout << "R < ";
						std::cin >> R;
						std::cout << "C < ";
						std::cin >> C;

						print_lunching("UI_terminal/UI_3.txt"); // demande de la methode de resolution
						std::cout << "num < ";
						std::cin >> method_num;
						std::cout << "Enter the simulation parameters :" << endl;
						std::cout << "step h < ";
						std::cin >> h;
						std::cout << "simulation time <";
						std::cin >> tmax;
						std::cout << "Start value < 0 ";
						S0 = 0;

						RC montage(S0, tmax, h, R, C, src);
						if(method_num == 1){
							montage.euler();
						}
						if(method_num == 2){
							montage.heun();
						}
						if(method_num == 3){
							montage.RK4();
						}
						if(method_num == 4){// comparaison : on lance les 3 methodes
							montage.euler();
							montage.heun();
							montage.RK4();
						}

						montage.exportSrc();// on export les valeurs de la source dans un fichier data
					break;
				}

					case 2: //circuit RLC serie
					{
						std::cout << "please enter the circuit parameters :" << endl;
						std::cout << "R <";
						std::cin >> R;
						std::cout << "C < ";
						std::cin >> C;
						std::cout << "L < ";
						std::cin >> L;

						print_lunching("UI_terminal/UI_3.txt"); // demande de la methode de resolution
						std::cout << "num < ";
						std::cin >> method_num;
						std::cout << "Enter the simulation parameters :" << endl;
						std::cout << "step h < ";
						std::cin >> h;
						std::cout << "simulation time <";
						std::cin >> tmax;
						std::cout << "Start value < 0";
						S0 = 0;
						std::cout << "Start derivate value < 0";
						S0p = 0;

						RLC montage(S0, S0p, tmax, h, src, R, L, C);
						if(method_num == 1){//Euler
							montage.euler();
						}
						if(method_num == 2){//Heun
							montage.heun();
						}
						if(method_num == 3){//RK4
							montage.RK4();
						}
						if(method_num == 4){// comparaison
							montage.euler();
							montage.heun();
							montage.RK4();
						}
						montage.exportSrc();

					break;
				}

					case 3: //circuit RC diode
					{
						std::cout << "please enter the circuit parameters :" << endl;
						std::cout << "R1 <";
						std::cin >> R1;
						std::cout << "R2 <";
						std::cin >> R2;
						std::cout << "C < ";
						std::cin >> C;


						print_lunching("UI_terminal/UI_3.txt"); // demande de la methode de resolution
						std::cout << "num < ";
						std::cin >> method_num;
						std::cout << "Enter the simulation parameters :" << endl;
						std::cout << "step h < ";
						std::cin >> h;
						std::cout << "simulation time <";
						std::cin >> tmax;
						std::cout << "Start value < 0";
						S0 = 0;

						RCD montage(S0, tmax, h, R1, R2, C, src );
						if(method_num == 1){
							montage.euler();
						}
						if(method_num == 2){
							montage.heun();
						}
						if(method_num == 3){
							montage.RK4();
						}
						if(method_num == 4){// comparaison
							montage.euler();
							montage.heun();
							montage.RK4();
						}
						montage.exportSrc();

					break;
				}

					case 4: //circuit RLC parallele
					{
						std::cout << "please enter the circuit parameters :" << endl;
						std::cout << "R < ";
						std::cin >> R;
						std::cout << "L < ";
						std::cin >> L;
						std::cout << "C < ";
						std::cin >> C;


						print_lunching("UI_terminal/UI_3.txt"); // demande de la methode de resolution
						std::cout << "num < ";
						std::cin >> method_num;
						std::cout << "Enter the simulation parameters :" << endl;
						std::cout << "step h < " ;
						std::cin >> h;
						std::cout << "simulation time < ";
						std::cin >> tmax;
						std::cout << "Start value < 0";
						S0 = 0;
						std::cout << "Start derivate value < 0";
						S0p = 0;

						RLCparallel montage(S0, S0p, tmax, h, src, R, L, C );
						if(method_num == 1){
							std::cout << "Start Euler sim" << '\n';
							montage.euler();
							std::cout << "Euler sim completed" << '\n';
						}
						if(method_num == 2){
							montage.heun();
						}
						if(method_num == 3){
							montage.RK4();
						}
						if(method_num == 4){// comparaison
							montage.euler();
							montage.heun();
							montage.RK4();
						}
						montage.exportSrc();
					break;
				}
					}
				std::cout << "End Of the simulation. You can fin the solution iun the data folder. Launch the python script trace.py to display your results.\nSelect 'r' to restart a new simulation or 'q' to quit." << '\n';
				state = 7; // on va dans l'etat final du programme ou l'on demande de quitter ou de refaire une autre simulation

			break;}

			// default :
			// std::cout << "NON !" << '\n';
			// break;
			case 7 :
			{
				char select;
				std::cin >> select;
				if (select == 'r')
				{
					state = 0;// on relance le programme
				}
				else if(select == 'q') // 27 = esc key
				{
					run = false; // on quitte la boucle et donc le programme
				}
				else
				{
					std::cout << "Please select a valid character " << '\n';
				}
				break;
			}
		}
	}
	return 0;
}

void print_lunching(string fileName)
{
  std::ifstream Reader (fileName);             //Open file

  std::string Art = getFileContents (Reader);       //Get file

  std::cout << Art;               //Print it to the screen

  Reader.close ();
}

std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}
