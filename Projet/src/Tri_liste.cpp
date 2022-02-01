/**
* @file Tri_liste.cpp
* @brief Fonction de tri d'une liste
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
* @version 1.0 05/01/2020
*/

#include <cstring>
#include <cstdlib>
#include "Tri_liste.h"
#include "Liste_mot.h"

bool saisir_liste_trie(Liste& l) {
	bool a = saisir_liste(l);
	tri(l);
	return a;
}

int tri_alphabetique(const void* A, const void* B)
{
	const Item* a = (const Item*)A;
	const Item* b = (const Item*)B;
	return strcmp(*a, *b);
}

void tri(Liste& l) {
	qsort(l.c.tab, l.nb, sizeof(Item), tri_alphabetique);
	suppr_repetition(l);
}

void rep_entre_listes(const Liste& la, Liste& lb) {
	int a = 1;
	for (unsigned int i = 0; i < lb.nb; i++) {
		for (unsigned int j = 0; j < la.nb; j++) {
			a = strcmp(lb.c.tab[i], la.c.tab[j]);
			if (a != 0) {
				if (j == la.nb - 1) {
					supprimer(lb, i);
					i--;
				}
			}
			else
				break;
		}
	}
}

void suppr_repetition(Liste& l) {
	for (unsigned int i = 0; i < l.nb; i++) {
		if (i + 1 == l.nb)
			break;
		while (strcmp(l.c.tab[i], l.c.tab[i + 1]) == 0) {
			supprimer(l, i + 1);
			if (i + 1 == l.nb)
				return;
		}
	}
}

void suppr_rep_entre_listes(const Liste& la, Liste& lb) {
	int a = 1;
	for (unsigned int i = 0; i < lb.nb; i++) {
		for (unsigned int j = 0; j < la.nb; j++) {
			a = strcmp(lb.c.tab[i], la.c.tab[j]);
			if (a == 0)
			{
				supprimer(lb, i);
			}

		}
	}
}
