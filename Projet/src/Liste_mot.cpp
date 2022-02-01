/** 
* @file Liste_mot.cpp
* @brief Gestion des listes de mots
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include <iostream>
#include "Tri_liste.h"
#include "Liste_mot.h"

using namespace std;

bool saisir_liste(Liste& l) {
	initialiser(l, 10, 5);			// liste de 10 mots avec un pas de 5
	char mot[31];
	int i = 0;
	bool a;
	while (1) {
		cin >> mot;
		if (strcmp(mot, "*") == 0) {
			if (i == 0){			// Si le premier mot de la liste est * on retourne 1 et on stop la fonction
				a = 1;
				break;
			}
			a = 0;				// Si ce n'est pas * on retourne 0 et on stop la fonction
			break;
		}
		ajouter_fin(l, mot);
		i++;
	}
	return a;
}

void point(const Liste& l) {
	cout << calcul_point(l);
}

int calcul_point(const Liste& l) {
	int car;
	int point = 0;
	for (unsigned int x = 0; x < l.nb; x++) {
		car = strlen(lire(l, x));
		switch (car)
		{
		case 0:
		case 1:
		case 2:
			break;
		case 3:
		case 4:
			point += 1;
			break;
		case 5:
			point += 2;
			break;
		case 6:
			point += 3;
			break;
		case 7:
			point += 5;
			break;
		default:
			point += 11;
			break;
		}
	}
	return point;
}

void affichage(const Liste& l) {
	for (unsigned int u = 0; u < l.nb; u++) {
		cout << lire(l, u) << endl;
	}
	cout << "*" << endl;
}

void enreg_mot_recurrent(Dictionnaire& dic, Liste& l) {
	initialiser(l, 10, 5);
	for (unsigned int i = 0; i < dic.nb; i++) {
		if (dic.tab[i].repetition > 1)
			ajouter_fin(l, dic.tab[i].mot);
	}
	tri(l);
	detruire_dico(dic);
}
