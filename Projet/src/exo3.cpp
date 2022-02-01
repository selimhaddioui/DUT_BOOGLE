/**
* @file exo3.cpp
* @brief Obtenir les mots dit valides
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include "Liste_mot.h"
#include "Tri_liste.h"

void exo3() {
	Liste la;
	Liste lb;
	saisir_liste_trie(la);
	saisir_liste_trie(lb);
	suppr_rep_entre_listes(la, lb);
	affichage(lb);
	detruire(la);
	detruire(lb);
}
