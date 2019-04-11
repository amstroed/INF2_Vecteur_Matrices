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
	
        /**
	 * @brief Constructeur par défaut. Créée un vecteur vide
	 */
	Vecteur() :
			contenuVecteur(vector < T > (0)) {

	}
                        
        /**
	 * @brief Constructeur avec un vector
	 */
	Vecteur(vector<T> vect) :
			contenuVecteur(vector<T>()) {
		contenuVecteur = vect;
	}
        
        /**
	 * @brief Constructeur avec un size_t, créé un vecteur avec la taille 
         * spécifiée
	 */
	Vecteur(size_t n) :
			contenuVecteur(vector < T > (n)) {
	}

	/**
	 * @brief Renvoies le contenu de l'emplacement n du vecteur en écriture
	 * @param n
	 * @return
	 */
	T& at(size_t n);
        
        /**
	 * @brief Renvoies le contenu de l'emplacement n du vecteur en lecture
	 * @param n
	 * @return
	 */
	T at(size_t n) const;
        
        /**
	 * @brief Modifie la taille du vecteur
	 * @param size
	 */
	void resize(size_t size);
        
        /**
	 * @brief retourne la somme des éléments du vecteur
	 * @return
	 */
	T somme() const;
        
        /**
	 * @brief Renvoie la taille du vecteur
	 * @return
	 */
	unsigned size() const noexcept;

	/**
	 * @brief retourne un vecteur contenant la multiplication de chaque élément 
         * du vecteur de départ par une valeur
	 * @param valeur
	 * @return
	 */
	Vecteur<T> operator*(T valeur);
        
        /**
	 * @brief retourne un vecteur contenant la multiplicaton de chauqe élément 
         * du vecteur de base avec l'élément au même endroit d'un autre vecteur
	 * @param vect
	 * @return
	 */
	Vecteur<T> operator*(Vecteur vect);
        
        /**
	 * @brief retourne un vecteur contenant l'addition de chauque élément du 
         * vecteur de base avec l'élément au même endroit de l'autre vecteur
	 * @param vect
	 * @return
	 */
	Vecteur<T> operator+(Vecteur vect);
        
        /**
	 * @brief retourne un vecteur contenant la soustraction de chauque élément du 
         * vecteur de base avec l'élément au même endroit de l'autre vecteur
	 * @param vect
	 * @return
	 */
	Vecteur<T> operator-(Vecteur vect);

private:
	//D�finission de la propri�t� pour les contenu
	vector<T> contenuVecteur;
};
#include "VecteurImpl.h"
#endif // VECTEUR_H
