/**
* @file BOOGLE.cpp
* @brief Jeu boogle
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
* @version 1.0 05/01/2020
*/

#include <iostream>

#include "exo.h"
#include "jouer.h"

using namespace std;


int main() {
	int num;
	cout << "Saisissez \"0\" pour jouer une partie de BOOGLE" << endl;
	cin >> num;
	switch (num) {
	case 0:
		jouer(); break;
	case 1:
		exo1(); break;
	case 2:
		exo2(); break;
	case 3:
		exo3(); break;
	case 4:
		exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
}
