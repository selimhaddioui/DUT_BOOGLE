#pragma once

/**
 * @file Liste_mot.h
 * @brief Composant d'une liste de chaine de caractère de capacité extensible.
 * @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
 */

#include "Dictionnaire.h"

/**
 * @brief Initialise et permet la saisit d'une liste.
 * @see detruire, pour sa désallocation en fin d'utilisation.
 * @param[in-out] l La liste.
 */
bool saisir_liste(Liste& l);

/**
 * @brief affiche la valeur des points d'une liste.
 * @param[in] l La liste concerné.
 */
void point(const Liste& l);

/**
 * @brief calcul la valeur des points d'une liste.
 * @param[in] l La liste concerné.
 * @return un entier ayant comme valeur les points de la liste
 */
int calcul_point(const Liste& l);

/**
 * @brief Affiche les mots d'une liste.
 * @param[in] l La liste à afficher.
 */
void affichage(const Liste& l);

/**
 * @brief Enregistre dans la liste les mots présent plus d'une fois dans le dictionnaire
 * et désalloue ce dernier.
 * @param[in-out] l La liste à remplir.
 * @param[in-out] dic Dictionnaire à consulter puis désallouer.
 */
void enreg_mot_recurrent(Dictionnaire& dic, Liste& l);