/**
* @file exo2.cpp
* @brief Affichage sous forme canonique d'une liste
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include "Liste_mot.h"
#include "Tri_liste.h"

void exo2() {
	Liste l;
	saisir_liste_trie(l);
	affichage(l);
	detruire(l);
}
