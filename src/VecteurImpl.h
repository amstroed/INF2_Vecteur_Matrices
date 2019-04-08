#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include "Vecteur.h"
#include "Erreurs.h"
#include <vector>

using namespace std;

template<typename T>
T& Vecteur<T>::at(unsigned n) {
	return this->contenuVecteur.at(n);
}

template<typename T>
T Vecteur<T>::at(size_t n) const {

}

template<typename T>
void Vecteur<T>::resize(size_t nouvelleCapacite) {

	this->contenuVecteur.resize(nouvelleCapacite);
}

template<typename T>
unsigned Vecteur<T>::size() const {
	return this->contenuVecteur.size();
}

template<typename T>
T Vecteur<T>::somme() const {
	T somme = T();
	for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
		somme += this->contenuVecteur.at(i);
	}
	return somme;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(T valeur) {
	vecteur<T> temp = this;
	for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
		temp.contenuVecteur.at(i) = this->contenuVecteur.at(i) * valeur;
	}
	return temp;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator *(Vecteur vect) {
	Vecteur<T> temp = this;
	if (vect.contenuVecteur.size() != this->contenuVecteur.size()) {
		throw Erreur_taille("Les deux vecteurs devant etre multiplies ne sont pas de la meme taille");
	} else {
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) = this->contenuVecteur.at(i) * vect.contenuVecteur.at(i);
		}
	}
	return temp;
}
template<typename T>
Vecteur<T> Vecteur<T>::operator +(Vecteur vect) {
	Vecteur<T> temp = this;
	if (vect.contenuVecteur.size() != this->contenuVecteur.size()) {
		throw Erreur_taille("Les deux vecteurs devant etre additionnes ne sont pas de la meme taille");
	} else {
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) = this->contenuVecteur.at(i) + vect.contenuVecteur.at(i);
		}
	}
	return temp;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator -(Vecteur vect) {
	Vecteur<T> temp = this;
	if (vect.contenuVecteur.size() != this->contenuVecteur.size()) {
		throw Erreur_taille("Les deux vecteurs devant etre soustraits ne sont pas de la meme taille");
	} else {
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) = this->contenuVecteur.at(i) - vect.contenuVecteur.at(i);
		}
	}
	return temp;
}

#endif // VECTEURIMPL_H
