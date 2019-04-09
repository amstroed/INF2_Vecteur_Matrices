#ifndef MATRICEIMPL_H
#define MATRICEIMPL_H

#include <vector>
#include "Erreurs.h"
#include "Vecteur.h"

const string FILENAMEMATRICE = "MatriceImpl.h";

template<typename T>
Matrice<T>::Matrice() {
}

template<typename T>
Matrice<T>::Matrice(const Matrice<T>& matrice)  : contenuMatrice(matrice.contenuMatrice){
}

template<typename T>
Matrice<T>::Matrice(unsigned lignes) :
		contenuMatrice(Vecteur < Vecteur < T >> (lignes)) {
}

template<typename T>
Matrice<T>::Matrice(unsigned lignes, unsigned colonnes) :
		contenuMatrice(Vecteur < Vecteur < T >> (lignes)) {

	for (size_t i = 0; i < contenuMatrice.size(); i++) {
		this->at(i).resize(colonnes);
	}

}

template<typename T>
Vecteur<T>& Matrice<T>::at(unsigned n) {

	try {
		return contenuMatrice.at(n);
	} catch (Erreur_taille&) {
		throw;
	}

}

template<typename T>
size_t Matrice<T>::size() const {

	return contenuMatrice.size();

}

template<typename T>
void Matrice<T>::resize(unsigned taille) {

	this->contenuMatrice.resize(taille);

}

template<typename T>
void Matrice<T>::resize(unsigned taille, unsigned colonne) {

	this->contenuMatrice.resize(taille);

	for (size_t i = 0; i < this->contenuMatrice.size(); i++) {

		this->contenuMatrice.at(i).resize(colonne);

	}
}

template<typename T>
bool Matrice<T>::estVide() {
	return this->contenuMatrice.size() = 0;
}

template<typename T>
bool Matrice<T>::estCarree() {

	if (!this->estVide()) {
		if (this->estReguliere()) {

			return this->size() == this->at(0).size();

		}
	}
}

template<typename T>
bool Matrice<T>::estReguliere() {

	if (!this->estVide()) {
		for (size_t i = 1; i < this->contenuMatrice.size(); i++) {
			if (this->contenuMatrice.at(i - 1).size()
					!= this->contenuMatrice.at(i).size()) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeLigne() {
	Vecteur < T > resultat(this->size());
	T temp;
	for (size_t i = 0; i < this->size(); i++) {
		temp = 0;
		for (size_t j = 0; j < this->at(i).size(); j++) {
			temp += this->at(i).at(j);
		}
		resultat.at(i) = temp;
	}
	return resultat;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeColonne() {
	Vecteur < T > resultat(this->size());
	T temp;
	for (size_t j = 0; j < this->at(0).size(); j++) {
		temp = 0;
		for (size_t i = 0; i < this->size(); i++) {
			temp += this->at(i).at(j);
		}
		resultat.at(j) = temp;
	}
	return resultat;

}

template<typename T>
T Matrice<T>::sommeDiagonaleGD() {
	T resultat = 0;
	for (size_t i = 0; i < this->size(); i++) {
		resultat += this->at(i).at(i);
	}
	return resultat;
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() {
	T resultat = 0;
	for (size_t i = 0; i < this->size(); i++) {
		resultat += this->at(i).at(this->at(i).size() - i - 1);
	}
	return resultat;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(T valeur) {

	Matrice < T > resultat(*this);
	for (size_t i = 0; i < this->size(); i++) {
		resultat.at(i) = this->at(i) * valeur;

	}
	return resultat;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(Matrice<T> matrice) {

	if (this->size() != matrice.size()) {
		throw Operation_Matrices_Differentes(
				"Multiplication entre des matrices differentes", FILENAMEMATRICE);
	}
	for (size_t i = 0; i < this->size(); i++) {
		if (this->at(i).size() != matrice.at(i).size()) {
			throw Operation_Matrices_Differentes(
					"Multiplication entre des matrices differentes", FILENAMEMATRICE);
		}
	}
	Matrice < T > resultat(*this);
	for (size_t i = 0; i < this->size(); i++) {
		resultat.at(i) = this->at(i) * matrice.at(i);

	}
	return resultat;

}

template<typename T>

Matrice<T> Matrice<T>::operator+(Matrice<T> matrice) {
	if (this->size() != matrice.size()) {
			throw Operation_Matrices_Differentes(
					"Addition entre des matrices differentes", FILENAMEMATRICE);
		}
		for (size_t i = 0; i < this->size(); i++) {
			if (this->at(i).size() != matrice.at(i).size()) {
				throw Operation_Matrices_Differentes(
						"Addition entre des matrices differentes", FILENAMEMATRICE);
			}
		}

	Matrice < T > resultat(this);
	for (size_t i = 0; i < this->size(); i++) {
		for (size_t j = 0; j < this->at(i).size(); j++) {
			resultat.at(i).at(j) = this->at(i).at(j) + matrice.at(i).at(j);
		}
	}
	return resultat;
}

#endif // MATRICEIMPL_H
