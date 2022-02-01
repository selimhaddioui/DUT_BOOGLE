/**
* @file exo4.cpp
* @brief Obtenir les mots étant dans le dictionnaire
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include "Liste_mot.h"
#include "Tri_liste.h"

void exo4() {
	Liste la;
	Liste lb;
	saisir_liste_trie(la);
	saisir_liste_trie(lb);
	rep_entre_listes(la, lb);
	affichage(lb);
	detruire(la);
	detruire(lb);
}
