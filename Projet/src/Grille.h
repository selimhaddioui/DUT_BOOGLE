#pragma once

/**
 * @file Grille.h
 * @brief Composant du plateau de BOOGLE
 * @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
 */


#include "Liste_mot.h"

// Nombre de lettre dans le plateau
#define CASE 16

// Nombre de ligne du plateau
#define Mot_Plateau 4

 /** @brief Position d'une lettre dans le plateau
  */
struct Position {
	unsigned int x;	// abscisse
	unsigned int y; // ordonnée
};

/** @brief Lettre du plateau
*/
struct Lettre {
	char lettre; 
	Position pos;
	bool visite; // si vrai alors la case a déjà était consulté
};

/** @brief Plateau
*/
typedef Lettre plateau[CASE + 1];

/**
 * @brief Recherche un mot dans le plateau.
 * @param[in-out] plat Le plateau à consulter, 
 * les lettres du plateau sont mis à jour au moment de la visite.
 * @param[in] mot Le mot à rechercher
 * @return Un booléen permettant de savoir si le mot est présent dans
 * le plateau.
 */
bool recherche(plateau& plat, const Mot mot);

/**
 * @brief Indique si un lettre est adjacente à une autre
 * @param[in] pos La position de la lettre 1.
 * @param[in] posTest La position de la lettre 2.
 * @return Un booléen permettant de savoir si les lettres sont adjacentes entre
 * elles.
 */
bool est_adjacent(const Position& pos, const Position& posTest);

/**
 * @brief Saisir le plateau et enregistrer la position des lettres 
 * de celui-ci.
 * @param[in-out] plat Le plateau à modifié.
 */
void saisir_grille(plateau& plat);

/**
 * @brief Indique la position en 2D d'une lettre
 * @param[in] pos La position en 1D de la lettre.
 * @return La position en 2D de la lettre.
 */
Position enreg_pos(const unsigned int pos);

/**
 * @brief Recherche si une lettre adjacente correspond à la lettre recherchée.
 * @param[in-out] plat Le plateau à consulter,
 * les lettres du plateau sont mis à jour au moment de la visite.
 * @param[in] mot Le mot à rechercher
 * @param[in] posi Position de la lettre dans le mot à rechercher
 * @param[in] coord Position de la lettre dans le mot à rechercher
 * @return Un booléen permettant de savoir si la lettre est présente autour
 * de celle consulté.
 */
bool sous_recherche(plateau& plat, const Mot mot, const unsigned int posi, const unsigned int coord);

/**
 * @brief Affiche les mots saisit qui sont présents dans le plateau.
 * @param[in-out] plat Le plateau à consulter,
 * les lettres du plateau sont mis à jour au moment de la visite.
 * @param[in] l La liste de mot à consulter
 */
void afficher_mot_correct(plateau& plat, const Liste& l);

/**
* @brief Affiche le plateau
*/
void afficher_grille(const plateau& plat);