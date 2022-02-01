/**
* @file Dictionnaire.cpp
* @brief Gestion du dictionnaire
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include <iostream>
#include <cassert>

#include "Liste_mot.h"
#include "Tri_liste.h"

#pragma warning ( disable : 4996 )

using namespace std;


void initialiser_dico(Dictionnaire& d, unsigned int capa, unsigned int pas) {
	assert((capa > 0) && (pas > 0));
	d.capa = capa;
	d.pas = pas;
	d.nb = 0;
	d.tab = new Dico[capa];
}

void detruire_dico(Dictionnaire& d) {
	delete[] d.tab;
	d.tab = NULL;
}

Mot lire_dico_it(const Dictionnaire& d, unsigned int i) {
	assert(i < d.capa);
	return d.tab[i].mot;
}

int lire_dico_rep(const Dictionnaire& d, unsigned int i) {
	assert(i < d.capa);
	return d.tab[i].repetition;
}

void ecrire_dico(Dictionnaire& d, unsigned int i, const Dico& it) {
	if (i >= d.capa) {
		unsigned int newTaille = (i + 1) * d.pas;
		Dico* newT = new Dico[newTaille];
		for (unsigned int i = 0; i < d.capa; ++i)
			newT[i] = d.tab[i];
		delete[] d.tab;
		d.tab = newT;
		d.capa = newTaille;
	}
	d.tab[i] = it;
}

void ajouter_fin_dico(Dictionnaire& dic, const Dico& it) {
	dic.tab[dic.nb].mot = new char[30];
	strcpy(dic.tab[dic.nb].mot, it.mot);
	dic.tab[dic.nb].repetition = 1;
	dic.nb++;
	if (dic.nb >= dic.capa) {
		unsigned int newTaille = (dic.nb + 1) * dic.pas;
		Dico* newT = new Dico[newTaille];
		for (unsigned int i = 0; i < dic.capa; ++i)
			newT[i] = dic.tab[i];
		delete[] dic.tab;
		dic.tab = newT;
		dic.capa = newTaille;
	}
}

void affichage_dico(const Dictionnaire& dic) {
	for (unsigned int u = 0; u < dic.nb; u++) {
		cout << lire_dico_it(dic, u) << " " << lire_dico_rep(dic, u) << endl;
	}
	cout << "*" << endl;
}

void recursiv_dico(Dictionnaire& dic, const Liste& l) {
	Dico it;
	int comp;
	if (dic.nb == 0) {
		conversion_dico(it, l.c.tab[0]);
		ajouter_fin_dico(dic, it);
	}
	for (unsigned int i = 0; i < l.nb; i++) {
		for (unsigned int j = 0; j < dic.nb; j++) {
			comp = strcmp(l.c.tab[i], dic.tab[j].mot);
			if (comp == 0) {
				dic.tab[j].repetition++;
				break;
			}
			else
			{
				if (j == dic.nb - 1) {
					conversion_dico(it, l.c.tab[i]);
					ajouter_fin_dico(dic, it);
					break;
				}
			}
		}
	}
}

void conversion_dico(Dico& d, const Item& it) {
	d.mot = it;
	d.repetition = 1;
}

void remplir_dico(Dictionnaire& dic) {
	Liste l;
	initialiser_dico(dic, 10, 5);
	bool v = 0;
	while ( 1 ) {
		v = saisir_liste_trie(l);
		if (v == 1)
			break;
		recursiv_dico(dic, l);
	}
	dic.tab[0].repetition--;		// permet de résoudre un problème de surincrémentation du premier mot
}