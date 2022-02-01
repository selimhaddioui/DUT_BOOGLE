/**
* @file exo6.cpp
* @brief Recherche des mots apparaissant dans le plateau
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim 
*/

#include "Grille.h"
#include "Tri_liste.h"

void exo6() {
	plateau plat;
	Liste l;
	saisir_grille(plat);
	saisir_liste_trie(l);
	afficher_mot_correct(plat, l);
	detruire(l);
}

