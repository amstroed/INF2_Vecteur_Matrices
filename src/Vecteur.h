#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>

template <typename T> class Vecteur;
template <typename T>
std::ostream & operator<< (std::ostream & os, const Vecteur<T>& vect)
{
	vect.contenuVecteur.at(0);
}

template <typename T>
class Vecteur
{
	friend std::ostream& operator<< <T>(std::ostream& os, const Vecteur<T>& vect);

public :
	Vecteur(vector<T> vect)
	{
		contenuVecteur = vect;
		capaciteVecteur = vect.capacity();
		tailleVecteur = vect.size();
	}
	Vecteur(size_t n)
	{
		capaciteVecteur = n;
		tailleVecteur = 0;
	}

	T& at(size_t n);
	T at(size_t n) const;
	void resize(size_t size);
	T somme() const;
	unsigned size();

	Vecteur<T> operator*(T valeur);
	Vecteur<T> operator*(Vecteur vect);
	Vecteur<T> operator+(Vecteur vect);
	Vecteur<T> operator-(Vecteur vect);

private :
	vector<T> contenuVecteur;
	unsigned capaciteVecteur;
	unsigned tailleVecteur;
};
#include "VecteurImpl.h"
#endif // VECTEUR_H
