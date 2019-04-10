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
Matrice<T>::Matrice(const Matrice<T>& matrice) :
		contenuMatrice(matrice.contenuMatrice) {
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
bool Matrice<T>::estVide() noexcept {
	return (this->contenuMatrice.size() == 0);
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
	if (!(this->estReguliere())) {
		throw Erreur_Forme_Matrice("Certaines colonnes sont incompletes dans une matrice irreguliere",
				FILENAMEMATRICE);
	}
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
	if (!this->estCarree()) {
		throw Erreur_Forme_Matrice(
				"Une matrice non carree n'as pas de diagonale",
				FILENAMEMATRICE);
	}
	T resultat = 0;
	for (size_t i = 0; i < this->size(); i++) {
		resultat += this->at(i).at(i);
	}
	return resultat;
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() {
	if (!this->estCarree()) {
		throw Erreur_Forme_Matrice(
				"Une matrice non carree n'as pas de diagonale",
				FILENAMEMATRICE);
	}
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
		throw Erreur_Forme_Matrice(
				"Multiplication entre des matrices differentes",
				FILENAMEMATRICE);
	}
	for (size_t i = 0; i < this->size(); i++) {
		if (this->at(i).size() != matrice.at(i).size()) {
			throw Erreur_Forme_Matrice(
					"Multiplication entre des matrices differentes",
					FILENAMEMATRICE);
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
	if (this->empty() || matrice.empty())
		{
			throw Erreur_vecteurVide("Tentative d'addition sur un vecteur vide", FILENAME);
		}
	if (this->size() != matrice.size()) {
		throw Erreur_Forme_Matrice("Addition entre des matrices differentes",
				FILENAMEMATRICE);
	}

	Matrice < T > resultat(*this);
	for (size_t i = 0; i < this->size(); i++) {
		try{
		for (size_t j = 0; j < this->at(i).size(); j++) {
			resultat.at(i).at(j) = this->at(i).at(j) + matrice.at(i).at(j);
		}
		}catch(Erreur_vecteurVide){
			throw;
		}catch(Erreur_taille){
			throw;
		}
	}
	return resultat;
}

#endif // MATRICEIMPL_H
