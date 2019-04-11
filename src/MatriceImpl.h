#ifndef MATRICEIMPL_H
#define MATRICEIMPL_H

#include <vector>
#include<string>
#include "Erreurs.h"
#include "Vecteur.h"

const string FILENAMEMATRICE = "MatriceImpl.h";


template<typename T>
Vecteur<T>& Matrice<T>::at(unsigned n) {

	try {
		return contenuMatrice.at(n);
	} catch (Erreur_taille&) {
		throw;
	}
}

template<typename T>
Vecteur<T> Matrice<T>::at(unsigned n) const {

	try {
		return contenuMatrice.at(n);
	} catch (Erreur_taille&) {
		throw;
	}
}

template<typename T>
size_t Matrice<T>::size() const noexcept {

	return contenuMatrice.size();

}

template<typename T>
void Matrice<T>::resize(unsigned taille) {
	try {
		this->contenuMatrice.resize(taille);
	} catch (Erreur_resize&) {
		throw;
	}
}

template<typename T>
void Matrice<T>::resize(unsigned taille, unsigned colonne) {
	try {
		this->resize(taille);

		for (size_t i = 0; i < this->size(); i++) {

			this->at(i).resize(colonne);
		}
	} catch (Erreur_resize&) {
		throw;
	}
}

template<typename T>
bool Matrice<T>::estVide() noexcept {
	return (this->size() == 0);
}

template<typename T>
bool Matrice<T>::estCarree() noexcept {

	if (!this->estVide()) {
		if (this->estReguliere()) {

			return this->size() == this->at(0).size();

		}
	}
	return true;
}

template<typename T>
bool Matrice<T>::estReguliere() noexcept {

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
	if (this->estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative d'op�ration sur une matrice vide");
	}
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
	if (this->estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative d'op�ration sur une matrice vide");
	}
	if (!(this->estReguliere())) {
		throw Erreur_Forme_Matrice(
				FILENAMEMATRICE
						+ "::Certaines colonnes sont incompletes dans une matrice irreguliere");
	}
	Vecteur < T > resultat(this->at(0).size());
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
	if (this->estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative d'op�ration sur une matrice vide");
	}
	if (!this->estCarree()) {
		throw Erreur_Forme_Matrice(
				FILENAMEMATRICE
						+ "::Une matrice non carree n'as pas de diagonale");
	}
	T resultat = 0;

	for (size_t i = 0; i < this->size(); i++) {
		// si un vecteur est vide?
		resultat += this->at(i).at(i);
	}
	return resultat;
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() {
	if (this->estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative d'opération sur une matrice vide");
	}
	if (!this->estCarree()) {
		throw Erreur_Forme_Matrice(
				FILENAMEMATRICE
						+ "::Une matrice non carree n'as pas de diagonale");
	}
	T resultat = 0;
	for (size_t i = 0; i < this->size(); i++) {
		// si un vecteur est vide?
		resultat += this->at(i).at(this->at(i).size() - i - 1);
	}
	return resultat;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(T valeur) {
	if (this->estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative de multiplication sur une matrice vide");
	}

	Matrice < T > resultat(*this);
	try {
		for (size_t i = 0; i < this->size(); i++) {
			resultat.at(i) = this->at(i) * valeur;
		}
	} catch (Erreur_vecteurVide&) {
		throw;
	}
	return resultat;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(Matrice<T> matrice) {
	if (this->estVide() || matrice.estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative de multiplication sur une matrice vide");
	}

	if (this->size() != matrice.size()) {
		throw Erreur_Forme_Matrice(
				FILENAMEMATRICE
						+ "::Tentative de multiplication entre des matrices differentes");
	}
	for (size_t i = 0; i < this->size(); i++) {
		if (this->at(i).size() != matrice.at(i).size()) {
			throw Erreur_Forme_Matrice(
					FILENAMEMATRICE
							+ "::Tentative de multiplication entre des matrices differentes");
		}
	}
	Matrice < T > resultat(*this);
	try {

		for (size_t i = 0; i < this->size(); i++) {
			resultat.at(i) = this->at(i) * matrice.at(i);
		}
	} catch (Erreur_vecteurVide&) {
		throw;
	} catch (Erreur_taille&) {
		throw;
	}
	return resultat;
}

template<typename T>
Matrice<T> Matrice<T>::operator+(Matrice<T> matrice) {

	if (this->estVide() || matrice.estVide()) {
		throw Erreur_matriceVide(
				FILENAMEMATRICE
						+ "::Tentative d'addition sur une matrice vide");
	}
	if (this->size() != matrice.size()) {
		throw Erreur_Forme_Matrice(
				FILENAMEMATRICE
						+ "::Tentative d'addition entre des matrices differentes");
	}

	Matrice < T > resultat(*this);
	for (size_t i = 0; i < this->size(); i++) {
		try {
			for (size_t j = 0; j < this->at(i).size(); j++) {
				resultat.at(i).at(j) = this->at(i).at(j) + matrice.at(i).at(j);
			}
		} catch (Erreur_vecteurVide&) {
			throw;
		} catch (Erreur_taille&) {
			throw;
		}
	}
	return resultat;
}

#endif // MATRICEIMPL_H
