/*
 ---------------------------------------------------------------------------------- -
 Laboratoire : GÉNÉRICITÉ ET EXCEPTIONS
 Fichier : Vecteur.h
 Auteur(s) : Loïc Geinoz, Teo Ferrari
 Date : 09.04.2019

 But : Définition des différentes fonctions de la classe Vecteur ainsi que des
 surcharges d'opérateur et définition et implémenation des constructeurs
 ---------------------------------------------------------------------------------- -
 */

#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>

//Implémentation de l'opérateur <<
template<typename T> class Vecteur;
template<typename T>
std::ostream & operator<<(std::ostream & os, const Vecteur<T>& vect) {
	os << "[";
	for (size_t i = 0; i < vect.contenuVecteur.size(); ++i) {
		os << vect.contenuVecteur.at(i);
		if (i != vect.contenuVecteur.size() - 1) {
			os << ", ";
		}
	}
	os << "]";
	return os;
}

//Définission de la classe vecteur
template<typename T>
class Vecteur {
	friend std::ostream& operator<<<T>(std::ostream& os,
			const Vecteur<T>& vect);

public:
	//Définission des constructeurs
	Vecteur() :
			contenuVecteur(vector < T > (0)) {

	}
	Vecteur(vector<T> vect) :
			contenuVecteur(vector<T>()) {
		contenuVecteur = vect;
	}
	Vecteur(size_t n) :
			contenuVecteur(vector < T > (n)) {
	}

	//Définission des fonctions publiques
	T& at(size_t n);
	T at(size_t n) const;
	void resize(size_t size);
	T somme() const;
	unsigned size() const noexcept;

	//Définission des surcharges d'opérateur
	Vecteur<T> operator*(T valeur);
	Vecteur<T> operator*(Vecteur vect);
	Vecteur<T> operator+(Vecteur vect);
	Vecteur<T> operator-(Vecteur vect);

private:
	//Définission de la propriété pour les contenu
	vector<T> contenuVecteur;
};
#include "VecteurImpl.h"
#endif // VECTEUR_H
