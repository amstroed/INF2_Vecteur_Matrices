/*
 * Erreurs.h
 *
 *  Created on: 8 Apr 2019
 *      Author: Teo
 */
/*
 ---------------------------------------------------------------------------------- -
 Laboratoire : G�N�RICIT� ET EXCEPTIONS
 Fichier : Erreurs.h
 Auteur(s) : Lo�c Geinoz, Teo Ferrari
 Date : 09.04.2019

 But : D�finition des diff�rentes classes d'erreur utilis�es par les classes
 Vecteur et Matrice
 ---------------------------------------------------------------------------------- -
 */

#ifndef ERREURS_H_
#define ERREURS_H_

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <exception>
#include <string>

class Erreur_Hors_limites: public std::out_of_range {
public:
	explicit Erreur_Hors_limites(const std::string& what) :
			out_of_range(what) {
	}
	explicit Erreur_Hors_limites(const char* what) :
			out_of_range(what) {
	}

};

class Erreur_overflow: public std::overflow_error {
public:
	explicit Erreur_overflow(const std::string& what) :
			overflow_error(what) {
	}
	explicit Erreur_overflow(const char* what) :
			overflow_error(what) {
	}

};

class Erreur_taille_vecteur: public std::logic_error {
public:
	explicit Erreur_taille_vecteur(const std::string& what) :
			logic_error(what) {

	}
	explicit Erreur_taille_vecteur(const char* what) :
			logic_error(what) {
	}
};

class Erreur_vecteurVide: public std::logic_error {
public:
	explicit Erreur_vecteurVide(const std::string& what) :
			logic_error(what) {

	}
	explicit Erreur_vecteurVide(const char* what) :
			logic_error(what) {

	}
};

class Erreur_matriceVide: public std::logic_error {
public:
	explicit Erreur_matriceVide(const std::string& what) :
			logic_error(what) {
	}
	explicit Erreur_matriceVide(const char* what) :
			logic_error(what) {
	}
};

class Erreur_allocation: public std::bad_alloc {
public:
	explicit Erreur_allocation() :
			bad_alloc() {
	}
};

class Erreur_Forme_Matrice: public std::logic_error {
public:
	explicit Erreur_Forme_Matrice(const std::string& what) :
			logic_error(what) {
	}
	explicit Erreur_Forme_Matrice(const char* what) :
			logic_error(what) {
	}

};

#endif /* ERREURS_H_ */
