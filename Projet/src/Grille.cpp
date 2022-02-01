/**
* @file Grille.cpp
* @brief Gestion du plateau
* @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
*/

#include <iostream>
#include "Grille.h"

using namespace std;


bool recherche(plateau& plat, const Mot mot) {
	for (unsigned int i = 0; i < CASE; i++) {
		plat[i].visite = false;
	}
	for (unsigned int i = 0; i < CASE; i++) {
		if (sous_recherche(plat, mot, 0, i))
			return true;
	}
	return false;
}

bool est_adjacent(const Position& pos, const Position& posTest)
{
	if (pos.x == posTest.x && (pos.y + 1 == posTest.y || pos.y - 1 == posTest.y)) // Haut / Bas
		return true;
	if (pos.y == posTest.y && (pos.x == posTest.x + 1 || pos.x == posTest.x - 1)) // Gauche / Droite
		return true;
	if (posTest.y == pos.y - 1 && posTest.x == pos.x - 1) // Haut gauche
		return true;
	if (posTest.y == pos.y + 1 && posTest.x == pos.x - 1) // Haut droite
		return true;
	if (posTest.y == pos.y + 1 && posTest.x == pos.x + 1) // Bas droite
		return true;
	if (posTest.y == pos.y - 1 && posTest.x == pos.x + 1) // Bas gauche
		return true;

	return false;
}

void saisir_grille(plateau& plat) {
	char mot[Mot_Plateau + 1];
	unsigned int j;
	for (j = 0; j < CASE;) {
		cin >> mot;
		for (unsigned int i = 0; i < Mot_Plateau; i++) {
			plat[j].lettre = mot[i];
			plat[j].pos = enreg_pos(j);
			j++;
		}
	}
	plat[CASE].lettre = '\0';
}

Position enreg_pos(const unsigned int pos)
{
	Position p;
	p.x = pos % Mot_Plateau;
	p.y = (pos - p.x) / Mot_Plateau;
	return p;
}

bool sous_recherche(plateau& plat, const Mot mot, const unsigned int posi, const unsigned int coord)
{
	if (coord > CASE - 1)
		return false;

	if (posi >= strlen(mot))
		return true;

	if (plat[coord].lettre != mot[posi])
		return false;

	if (plat[coord].visite)
		return false;

	plat[coord].visite = true;
	for (unsigned int i = 0; i < CASE; ++i)
		if (est_adjacent(plat[coord].pos, plat[i].pos))
			if (sous_recherche(plat, mot, posi + 1, i))
				return true;
	plat[coord].visite = false;
	return false;
}

void afficher_mot_correct(plateau& plat, const Liste& l) {
	for (unsigned int i = 0; i < l.nb; i++) {
		if (recherche(plat, l.c.tab[i]))
			cout << l.c.tab[i] << endl;
	}
	cout << "*" << endl;
}

void afficher_grille(const plateau& plat) {
	for (int i = 0; i < CASE; i++) {
		cout << plat[i].lettre;
		if (i % Mot_Plateau == Mot_Plateau - 1)
			cout << endl;
	}
}