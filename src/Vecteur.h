/*
 ---------------------------------------------------------------------------------- -
 Laboratoire : G�N�RICIT� ET EXCEPTIONS
 Fichier : Vecteur.h
 Auteur(s) : Lo�c Geinoz, Teo Ferrari
 Date : 09.04.2019

 But : D�finition des diff�rentes fonctions de la classe Vecteur ainsi que des
 surcharges d'op�rateur et d�finition et impl�menation des constructeurs
 ---------------------------------------------------------------------------------- -
 */

#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>

//Impl�mentation de l'op�rateur <<
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

//D�finission de la classe vecteur
template<typename T>
class Vecteur {
	friend std::ostream& operator<<<T>(std::ostream& os,
			const Vecteur<T>& vect);

public:
	//D�finission des constructeurs
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

	//D�finission des fonctions publiques
	T& at(size_t n);
	T at(size_t n) const;
	void resize(size_t size);
	T somme() const;
	unsigned size() const noexcept;

	//D�finission des surcharges d'op�rateur
	Vecteur<T> operator*(T valeur);
	Vecteur<T> operator*(Vecteur vect);
	Vecteur<T> operator+(Vecteur vect);
	Vecteur<T> operator-(Vecteur vect);

private:
	//D�finission de la propri�t� pour les contenu
	vector<T> contenuVecteur;
};
#include "VecteurImpl.h"
#endif // VECTEUR_H
