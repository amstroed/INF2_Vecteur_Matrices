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
	explicit Depassement_Capacite(const string& what, const string& file) :
			logic_error(what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
	explicit Depassement_Capacite(const char* what, const string& file) :
			logic_error(what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}

};

class Erreur_taille: public std::logic_error {
public:
	explicit Erreur_taille(const string& what, const string& file) :
			logic_error(what) {

		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
	explicit Erreur_taille(const char* what, const string& file) :
			logic_error(what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
};

class Erreur_vecteurVide : public std::logic_error {
public:
	explicit Erreur_vecteurVide(const string& what, const string& file) : logic_error(what) {

		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
	explicit Erreur_vecteurVide(const char* what, const string& file) : logic_error(what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
};

class Erreur_matriceVide : public std::logic_error {
public:
	explicit Erreur_matriceVide(const string& what, const string& file) : logic_error(what) {

		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
	explicit Erreur_matriceVide(const char* what, const string& file) : logic_error(what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
};

class Erreur_resize : public std::logic_error {
public:
	explicit Erreur_resize(const string& what, const string& file) : logic_error(what) {

		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
	explicit Erreur_resize(const char* what, const string& file) : logic_error(what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
};




class Erreur_Forme_Matrice: public std::logic_error {
public:
	explicit Erreur_Forme_Matrice(const string& what, const string& file) : logic_error (what) {

		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}
	explicit Erreur_Forme_Matrice(const char* what, const string& file) : logic_error (what) {
		cout << "Fichier : " << file << endl;
		cout << "Erreur : " << what << endl;
	}

};


#endif /* ERREURS_H_ */
