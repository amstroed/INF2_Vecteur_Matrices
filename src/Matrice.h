#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <iostream>
#include "Vecteur.h"

template<typename T> class Matrice;
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrice<T>& matrice) {
	cout << "[";
	for (size_t i = 0; i < matrice.size(); i++) {
		std::cout << matrice.at(i);

	}
	std::cout << "]" << std::endl;
	return os;
}

template<typename T>
class Matrice {

	friend std::ostream& operator<<<T>(std::ostream& os,
			const Matrice<T>& matrice);

public:

	/**
	 * @brief Constructeur par défaut. Créées une matrice vide
	 */
	Matrice() {

	}
	/**
	 * @brief Constructeur de copie. Créées une matrice  qui est la copie d'une autre
	 * @param matrice
	 */
	Matrice(const Matrice<T>& matrice) :
			contenuMatrice(matrice.contenuMatrice) {
	}
	/**
	 * @brief Constructeur créant une de l lignes
	 * @param lignes
	 */
	Matrice(unsigned lignes) :
			contenuMatrice(Vecteur<Vecteur<T>>(lignes)) {
	}
	/**
	 * @brief Constructeur créant une matrice de l lignes et de c colonnes
	 * @param lignes
	 * @param colonnes
	 */
	Matrice(unsigned lignes, unsigned colonnes) :
			contenuMatrice(Vecteur<Vecteur<T>>(lignes)) {

		for (size_t i = 0; i < contenuMatrice.size(); i++) {
			this->at(i).resize(colonnes);
		}
	}
	/**
	 * @brief Renvoies le contenu de l'emplacement n de la matrice en écriture
	 * @param n
	 * @return
	 */
	Vecteur<T>& at(unsigned n);

	/**
	 * @brief Renvoies le contenu de l'emplacement n de la matrice en lecture
	 * @param n
	 * @return
	 */
	Vecteur<T> at(unsigned n) const;
	/**
	 * @brief Renvoies le nombre de lignes de la matrice
	 * @return
	 */
	size_t size() const noexcept;

	/**
	 * @brief Modifie le nombre de lignes de la matrice
	 * @param taille
	 */
	void resize(unsigned taille);

	/**
	 * @brief modifie le nombre de lignes et de colonnes de la matrice
	 * @param taille
	 * @param colonne
	 */
	void resize(unsigned taille, unsigned colonne);

	/**
	 * @brief Retourne true si la amtrice est vide
	 * @return
	 */
	bool estVide() noexcept;
	/**
	 * @brief retourne true si la matrice est carrée
	 * @return
	 */
	bool estCarree() noexcept;

	/**
	 * @brief retourne true si la matrice est régulière
	 * @return
	 */
	bool estReguliere() noexcept;

	/**
	 * @brief retourne un Vecteur contenant la somme de chauque ligne de la matrice
	 * @return
	 */
	Vecteur<T> sommeLigne();

	/**
	 * @brief retourne un Vecteur contenant la somme de chaque colonne de la matrice
	 * @return
	 */
	Vecteur<T> sommeColonne();

	/**
	 * @brief retourne le resultat de la somme de la diagonale de gauche à droite de la matrice
	 * @return
	 */
	T sommeDiagonaleGD();

	/**
	 * @brief retourne le resultat de la somme de la diagonale de droite à gauche de la matrice
	 * @return
	 */
	T sommeDiagonaleDG();

	/**
	 * @brief retourne une Matrice contenant la multiplication de chque élément de la matrice de départ par une valeur
	 * @param valeur
	 * @return
	 */
	Matrice<T> operator*(T valeur);

	/**
	 * @brief retourne une matrice contenant la multiplicaton de chauqe élément de la matrice de base avec l'élément au même endroit de l'autre matrice
	 * @param matrice
	 * @return
	 */
	Matrice<T> operator*(Matrice<T> matrice);

	/**
	 * @brief retourne une matrice contenant l'addition de chauqe élément de la matrice de base avec l'élément au même endroit de l'autre matrice
	 * @param matrice
	 * @return
	 */
	Matrice<T> operator+(Matrice<T> matrice);

private:

	Vecteur<Vecteur<T>> contenuMatrice;
};

#include "MatriceImpl.h"
#endif // MATRICE_H
