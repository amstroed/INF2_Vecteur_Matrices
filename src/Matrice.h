#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <iostream>
#include "Vecteur.h"

template<typename T> class Matrice;
template<typename T>
std::ostream& operator<<(std::ostream& os, Matrice<T>& matrice) {
	cout << "[";
	for (size_t i = 0; i < matrice.size(); i++) {
			std::cout << matrice.at(i);

	}
	std::cout << "]" << std::endl;
	return os;
}

template<typename T>
class Matrice {

	friend std::ostream& operator<<<T>(std::ostream& os, Matrice<T>& matrice);

public:

	Matrice();
	Matrice(const Matrice<T>& matrice);
	Matrice(unsigned lignes);
	Matrice(unsigned lignes, unsigned colonnes);

	Vecteur<T>& at(unsigned n);
	size_t size() const;
	void resize(unsigned taille);
	void resize(unsigned taille, unsigned colonne);

	bool estVide();
	bool estCarree();
	bool estReguliere();

	Vecteur<T> sommeLigne();
	Vecteur<T> sommeColonne();
	T sommeDiagonaleGD();
	T sommeDiagonaleDG();

	Matrice<T> operator*(T valeur);
	Matrice<T> operator*(Matrice<T> matrice);
	Matrice<T> operator+(Matrice<T> matrice);

private:
	Vecteur<Vecteur<T>> contenuMatrice;
};

#include "MatriceImpl.h"
#endif // MATRICE_H
