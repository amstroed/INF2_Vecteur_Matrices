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
#include <string>

class Depassement_Capacite: public std::logic_error {
public:
	explicit Depassement_Capacite(const std::string& what) :
			logic_error(what) {
	}
	explicit Depassement_Capacite(const char* what) :
			logic_error(what) {
	}

};

class Erreur_taille: public std::logic_error {
public:
	explicit Erreur_taille(const std::string& what) :
			logic_error(what) {

	}
	explicit Erreur_taille(const char* what) :
			logic_error(what) {
	}
};

class Erreur_vecteurVide : public std::logic_error {
public:
	explicit Erreur_vecteurVide(const std::string& what) : logic_error(what) {

	}
	explicit Erreur_vecteurVide(const char* what) : logic_error(what) {

	}
};

class Erreur_matriceVide : public std::logic_error {
public:
	explicit Erreur_matriceVide(const std::string& what) : logic_error(what) {
	}
	explicit Erreur_matriceVide(const char* what) : logic_error(what) {
	}
};

class Erreur_resize : public std::logic_error {
public:
	explicit Erreur_resize(const std::string& what) : logic_error(what) {

	}
	explicit Erreur_resize(const char* what) : logic_error(what) {
	}
};




class Erreur_Forme_Matrice: public std::logic_error {
public:
	explicit Erreur_Forme_Matrice(const std::string& what) : logic_error (what) {
	}
	explicit Erreur_Forme_Matrice(const char* what) : logic_error (what) {
	}

};


#endif /* ERREURS_H_ */
