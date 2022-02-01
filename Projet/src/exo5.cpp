/**
* @file exo5.cpp
* @brief Obtenir les mots écrit par au moins deux joueurs
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim 
*/

#include "Liste_mot.h"
#include "Tri_liste.h"

void exo5() {
	Dictionnaire dico;
	Liste l;
	remplir_dico(dico);
	enreg_mot_recurrent(dico, l);
	affichage(l);
	detruire(l);
}
