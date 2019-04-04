#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <iostream>
#include "Vecteur.h"
template <typename T>
class Matrice
{
	friend std::ostream& operator <<(std::ostream& os, const Matrice<T>& matrice);

public:

	Matrice(){}
	Matrice(unsigned lignes){}
	Matrice(unsigned lignes, unsigned colonnes){}

	Vecteur<T> at(unsigned n);
	unsigned size();
	void resize(unsigned taille);

	bool estVide();
	bool estReguliere();
	bool estCarree();

	Vecteur<T> sommeLigne();
	Vecteur<T> sommeColonne();
	Vecteur<T> sommeDiagonaleGD();
	Vecteur<T> sommeDiagonaleDG();
	
	Matrice<T> operator*(T valeur);
	Matrice<T> operator*(Matrice matrice);
	Matrice<T> operator+(Matrice matrice);

private:
	Vecteur<Vecteur<T>> contenuMatrice;
};


#include "MatriceImpl.h"
#endif // MATRICE_H
