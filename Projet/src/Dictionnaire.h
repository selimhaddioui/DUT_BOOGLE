#pragma once

/**
 * @file Dictionnaire.h
 * @brief Gestion du dictionnaire
 * @author Groupe 104 : AKHAYAR Mahir et HADDIOUI Sélim
 */

#include "Liste.h"

// Dico
struct Dico {

	Mot mot;
	int repetition;	// clé comptant les redondances du mot

};

// Dictionnaire
struct Dictionnaire {

	Dico* tab;		// Dictionnaire contenant les mot et leurs clés
	unsigned int nb;	// nb d'éléments contenus
	unsigned int capa;	// capacité du dictionnaire
	unsigned int pas;	// pas d'extension du dictionnaire
};

/**
 * @brief Initialise un dictionnaire.
 * Allocation en mémoire dynamique du dictionnaire
 * de capacité (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa désallocation en fin d'utilisation.
 * @param[out] D Le Dictionnaire.
 * @param [in] capa Capacité du conteneur.
 * @param [in] p Pas d'extension de capacité.
 * @pre capa > 0 et p > 0.
 */
void initialiser_dico(Dictionnaire& d, unsigned int capa, unsigned int pas);

/**
 * @brief Désalloue le dictionnaire en mémoire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void detruire_dico(Dictionnaire& d);

/**
 * @brief Lecture d'un mot du dictionnaire.
 * @param[in] d Le dictionnaire.
 * @param[in] i La position du mot dans le dictionnaire.
 * @return Le mot à la position i.
 * @pre i < c.capacite
 */
Mot lire_dico_it(const Dictionnaire& d, unsigned int i);

/**
 * @brief Lecture du nombre de répétition d'un mot du dictionnaire.
 * @param[in] d Le dictionnaire.
 * @param[in] i La position du mot dans le dictionnaire.
 * @return Le nombre de répétition du mot à la position i.
 * @pre i < c.capacite
 */
int lire_dico_rep(const Dictionnaire& d, unsigned int i);

/**
 * @brief Ecrire mot dans le dictionnaire.
 * @param[in,out] d Le dictionnaire.
 * @param[in] i La position où modifier le mot.
 * @param[in] it L'item à écrire.
 */
void ecrire_dico(Dictionnaire& c, unsigned int i, const Dico& it);

/**
 * @brief Ajoute un item Dico à la fin du Dictionnaire
 * si celui-ci est complet, le rend extensible.
 * @param[in-out] d La variable de type Dico où est rentrer l'Item.
 * @param[in] it Le mot à saisir
 */
void ajouter_fin_dico(Dictionnaire& dic, const Dico& it);

/**
 * @brief Affiche les mots et le nombre de répétition du mot d'un dictionnaire.
 * @param[in-out] dic Le dictionnaire à afficher.
 */
void affichage_dico(const Dictionnaire& dic);

/**
 * @brief Enregistre plusieurs liste dans un dictionnaire jusqu'à 
 * la saisit d'une liste vide.
 * @param[in-out] dic Le dictionnaire où sont enregistrer les listes.
 * @param[in] l La liste à saisir.
 */
void recursiv_dico(Dictionnaire& dic, const Liste& l);

/**
 * @brief Change un Item en Dico et initialise sa répétition à 1.
 * @param[in-out] d La variable de type Dico où est rentrer l'Item.
 * @param[in] it Le mot à saisir
 */
void conversion_dico(Dico& d, const Item& it);

/**
 * @brief Ajouter des mots dans un dictionnaire où incrémenter son
 * nombre de répétition s'il y est déjà présent.
 * @param[in-out] dic Le dictionnaire à remplir.
 */
void remplir_dico(Dictionnaire& dic);