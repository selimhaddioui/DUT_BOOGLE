#pragma once

/**
 * @file Tri_liste.h
 * @brief Fonction de tri de liste.
 * @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
 */

#include "Liste.h"

/**
 * @brief Initialiser une liste, la saisir et la trier.
 * @see detruire, la liste est à désallouer en fin d'utilisation.
 * @param[in-out] l La liste à initialiser, saisir et trier.
 * @return Un booléen permettant de savoir si la liste est vide
 */
bool saisir_liste_trie(Liste& l);

/**
 * @brief Permet de savoir quel est l'ordre alphabétique de deux mots l'un vis-à-vis de l'autre.
 * @param[in] A pointeur const vers le mot 1.
 * @param[in] B pointeur const vers le mot 2.
 * @return Un entier indiquant lequel est au dessus de l'autre
 */
int tri_alphabetique(const void* A, const void* B);

/**
 * @brief Tri une liste dans l'ordre alphabétique.
 * @param[in-out] l la liste a trier.
 */
void tri(Liste& l);

/**
 * @brief Supprime les mots de la deuxième liste qui ne sont pas présents dans la première.
 * @param[in] la liste à consulter.
 * @param[in-out] lb la liste à modifier.
 */
void rep_entre_listes(const Liste& la, Liste& lb);

/**
 * @brief Supprimer les mots redondant à l'intérieur d'une liste.
 * @param[in-out] l la liste a modifier.
 */
void suppr_repetition(Liste& l);

/**
 * @brief Supprime les mots de la deuxième liste qui sont présents dans la première.
 * @param[in] la liste à consulter.
 * @param[in-out] lb la liste à modifier.
 */
void suppr_rep_entre_listes(const Liste& la, Liste& lb);
