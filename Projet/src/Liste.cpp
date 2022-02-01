/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */

#include <cassert> 
#include <cstring>

#pragma warning ( disable : 4996 )

#include "Liste.h"

void initialiser(Liste& l, const unsigned int capa, const unsigned int pas) {
	assert((capa > 0) && (pas > 0));
	initialiser(l.c, capa, pas);
	l.nb = 0;
}

void detruire(Liste& l) {
	for (unsigned int i = 0; i < l.nb; i++) {
		delete[] l.c.tab[i];
	}
	detruire(l.c);
}

unsigned int longueur(const Liste& l) {
	return l.nb;
}

Item lire(const Liste& l, const unsigned int pos) {
	assert(pos < l.nb);
	return lire(l.c, pos);
}

void ecrire(Liste& l, const unsigned int pos, const Item& it) {
	assert(pos < l.c.capacite);
	ecrire(l.c, pos, it);
}

void inserer(Liste& l, const unsigned int pos, const Item& it) {
	assert(pos <= l.nb);
	for (unsigned int i = l.nb; i > pos; i--) {
		ecrire(l.c, i, lire(l.c, i - 1));
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

void supprimer(Liste& l, const unsigned int pos) {
	assert((l.nb != 0) && (pos < l.nb));
	l.nb--;
	for (unsigned int i = pos; i < l.nb; ++i)
		ecrire(l.c, i, lire(l.c, i + 1));
}

void ajouter_fin(Liste& l, const Item it)
{
	l.c.tab[l.nb] = new char[30];
	strcpy(l.c.tab[l.nb], it);
	l.nb++;
	if (l.nb >= l.c.capacite) {
		unsigned int newTaille = (l.nb + 1) * l.c.pasExtension;
		Item* newT = new Item[newTaille];
		for (unsigned int i = 0; i < l.c.capacite; ++i)
			newT[i] = l.c.tab[i];
		delete[] l.c.tab;
		l.c.tab = newT;
		l.c.capacite = newTaille;
	}
}
