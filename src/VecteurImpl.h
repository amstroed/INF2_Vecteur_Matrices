/*
 ---------------------------------------------------------------------------------- -
 Laboratoire : G�N�RICIT� ET EXCEPTIONS
 Fichier : VecteurImpl.h
 Auteur(s) : Lo�c Geinoz, Teo Ferrari
 Date : 09.04.2019

 But : Impl�menation des diff�rentes fonctions de la classe Vecteur ainsi que des
 surcharges d'op�rateur.
 ---------------------------------------------------------------------------------- -
 */

#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include "Vecteur.h"
#include "Erreurs.h"
#include <vector>
#include <string>

const string FILENAMEVECTEUR = "VecteurImpl.h";

using namespace std;

template<typename T>
T& Vecteur<T>::at(size_t n) {
	try {
		return this->contenuVecteur.at(n);
	} catch (out_of_range&) {
		throw Erreur_Hors_limites(
				FILENAMEVECTEUR + "::Element en dehors des limites");
	}
}

template<typename T>
T Vecteur<T>::at(size_t n) const {
	try {
		return this->contenuVecteur.at(n);
	}
	//On r�cup�re l'erreur dans le cas o� l'utilisateur essaye d'acc�der � 
        //un �l�ment en dehors des limites
	catch (out_of_range&) {
		throw Erreur_Hors_limites(
				FILENAMEVECTEUR + "::Element en dehors des limites");
	}
}

template<typename T>
void Vecteur<T>::resize(size_t nouvelleCapacite) {
	try {
		this->contenuVecteur.resize(nouvelleCapacite);
	}
	//On r�cup�re l'erreur qui peut survenir dans le cas d'un resize d'un vecteur
	catch (bad_alloc&) {
		throw Erreur_allocation();
	}
}

template<typename T>
unsigned Vecteur<T>::size() const noexcept {
	return this->contenuVecteur.size();
}

template<typename T>
T Vecteur<T>::somme() const {
	T somme = T();
	if (this->contenuVecteur.empty()) {
		throw Erreur_vecteurVide(
				(FILENAMEVECTEUR + "::Tentative de somme sur un vecteur vide"));
	} else {
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			somme += this->contenuVecteur.at(i);
		}
		return somme;
	}
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(T valeur) {
	if (!this->contenuVecteur.empty()) {
		Vecteur<T> temp(this->contenuVecteur);
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) *= valeur;
		}
		return temp;
	} else {
		throw Erreur_vecteurVide(
				FILENAMEVECTEUR
						+ "::Tentative de multiplication sur un vecteur vide");
	}
}

template<typename T>
Vecteur<T> Vecteur<T>::operator *(Vecteur vect) {
	if (this->contenuVecteur.empty() || vect.contenuVecteur.empty()) {
		throw Erreur_vecteurVide(
				FILENAMEVECTEUR
						+ "Tentative de multiplication sur un vecteur vide");
	} else if (vect.contenuVecteur.size() != this->contenuVecteur.size()) {
		throw Erreur_taille_vecteur(
				FILENAMEVECTEUR
						+ "::Les deux vecteurs devant etre multiplies ne sont pas de la meme taille");
	} else {
		Vecteur<T> temp(this->contenuVecteur);
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) *= vect.contenuVecteur.at(i);
		}
		return temp;
	}
}

template<typename T>
Vecteur<T> Vecteur<T>::operator +(Vecteur vect) {
	if (this->contenuVecteur.empty() || vect.contenuVecteur.empty()) {
		throw Erreur_vecteurVide(
				FILENAMEVECTEUR + "::Tentative d'addition sur un vecteur vide");
	} else if (vect.contenuVecteur.size() != this->contenuVecteur.size()) {
		throw Erreur_taille_vecteur(
				FILENAMEVECTEUR
						+ "::Les deux vecteurs devant etre additionnes ne sont pas de la meme taille");
	} else {
		Vecteur<T> temp(this->contenuVecteur);
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) += vect.contenuVecteur.at(i);
		}
		return temp;
	}
}

template<typename T>
Vecteur<T> Vecteur<T>::operator -(Vecteur vect) {
	if (this->contenuVecteur.empty() || vect.contenuVecteur.empty()) {
		throw Erreur_vecteurVide(
				FILENAMEVECTEUR
						+ "::Tentative de soustraction sur un vecteur vide");
	} else if (vect.contenuVecteur.size() != this->contenuVecteur.size()) {
		throw Erreur_taille_vecteur(
				FILENAMEVECTEUR
						+ "::Les deux vecteurs devant etre soustraits ne sont pas de la meme taille");
	} else {
		Vecteur<T> temp(this->contenuVecteur);
		for (size_t i = 0; i < this->contenuVecteur.size(); ++i) {
			temp.contenuVecteur.at(i) -= vect.contenuVecteur.at(i);
		}
		return temp;
	}
}

#endif // VECTEURIMPL_H
