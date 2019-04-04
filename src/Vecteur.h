#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>

template <typename T>
class Vecteur
{
	friend std::ostream& operator <<(std::ostream& os, const Vecteur<T>& vect);

public :
	Vecteur(vector<T>)
	{

	}
	Vecteur(size_t n)
	{

	}

	T at(size_t n);
	void resize(size_t size);
	T somme();

	Vecteur<T> operator*(T valeur);
	Vecteur<T> operator*(Vecteur vect);
	Vecteur<T> operator+(Vecteur vect);
	Vecteur<T> operator-(Vecteur vect);

private :
	vector<T> contenuVecteur;
};
#include "VecteurImpl.h"
#endif // VECTEUR_H
