#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <iostream>
#include "Vecteur.h"
template<typename T>
class Matrice {

//	friend std::ostream& operator<<(std::ostream& os,
//			const Matrice<T>& matrice) {
//		cout << "[";
//		for (size_t i = 0; i < contenuMatrice.size(); i++) {
//			cout << "[";
//			for (size_t j = 0; j < contenuMatrice.t(i).size(); j++) {
//				std::cout << contenuMatrice.at(i).at(j) << ", ";
//			}
//			std::cout << "], ";
//		}
//		std::cout << "] " << std::endl;
//		return os;
//	}

public:

	Matrice();
	Matrice(unsigned lignes);
	Matrice(unsigned lignes, unsigned colonnes);

	vector<T> at(unsigned n);
	size_t size();
	void resize(unsigned taille);
	void resize(unsigned taille, unsigned colonne);

	bool estVide();
	bool estCarree();
	bool estReguliere();

	vector<T> sommeLigne();
	vector<T> sommeColonne();
	T sommeDiagonaleGD();
	T sommeDiagonaleDG();

	Matrice<T> operator*(T valeur);
	Matrice<T> operator*(Matrice<T> matrice);
	Matrice<T> operator+(Matrice<T> matrice);

private:
	std::vector<std::vector<T>> contenuMatrice;
};

#include "MatriceImpl.h"
#endif // MATRICE_H
