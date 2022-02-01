/**
* @file jouer.cpp
* @brief Jouer une partie de BOOGLE
* Fichier crée postérieurement au projet afin de permettre une utilisation 
* guidée du programme pour les visiteurs venue de github
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include <iostream>
#include "Grille.h"
#include "Tri_liste.h"

using namespace std;

void jouer() {
	// Initialisation du jeu
	plateau plat;
	Liste dictionnaire, tour;

	cout << "Pour initialiser le plateau veuillez saisir 4 mots de 4 lettres" << endl;
	saisir_grille(plat);

	cout << "Initialiser le dictionnaire de mots en les saisissant séparés d'un espace avec pour dernier mot ce caractère : * ." << endl;
	saisir_liste_trie(dictionnaire);

	// Jeu
	int score = calcul_point(dictionnaire);
	cout << endl << "Le jeu finira lorsque tout les mots du dictionnaire auront été trouvés" << endl;
	afficher_grille(plat);

	cout << endl << "Jouez en respectant la même synthaxe que précedemment" << endl;
	while (dictionnaire.nb > 0) {
		saisir_liste_trie(tour);
		suppr_rep_entre_listes(tour, dictionnaire);
		cout << endl << "Il reste " << dictionnaire.nb << " mots à trouver" << endl;
	}

	// Fin du jeu
	cout << "Vous avez remporté " << score << " points" << endl;
	detruire(dictionnaire);
	detruire(tour);
}

