#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <iostream>
#include "Vecteur.h"
template <typename T>
class Matrice
{
	//std::ostream& operator <<(std::ostream& os, const Matrice<T>& matrice);

public:

	Matrice();
	Matrice(unsigned lignes);
	Matrice(unsigned lignes, unsigned colonnes);

	vector<T> at(unsigned n);
	unsigned size();
	void resize(unsigned taille);
	void resize(unsigned taille, unsigned colonne);

	bool estVide();
	bool estCarree();
	bool estReguliere();

	vector<T> sommeLigne();
	vector<T> sommeColonne();
	vector<T> sommeDiagonaleGD();
	vector<T> sommeDiagonaleDG();
	
	Matrice<T> operator*(T valeur);
	Matrice<T> operator*(Matrice matrice);
	Matrice<T> operator+(Matrice matrice);

private:
	std::vector<std::vector<T>> contenuMatrice;
};


#include "MatriceImpl.h"
#endif // MATRICE_H
