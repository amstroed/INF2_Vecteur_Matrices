#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>

template<typename T> class Vecteur;
template<typename T>
std::ostream & operator<<(std::ostream & os, const Vecteur<T>& vect) {
	os << "[";
	for (size_t i = 0; i < vect.contenuVecteur.size(); ++i)
	{
		os << vect.contenuVecteur.at(i);
		if (i != vect.contenuVecteur.size() - 1)
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}

template<typename T>
class Vecteur {
	friend std::ostream& operator<<<T>(std::ostream& os,
			const Vecteur<T>& vect);

public:
	Vecteur() :
			contenuVecteur(vector < T > (0)) {

	}
	Vecteur(vector<T> vect) :
			contenuVecteur(vector<T>()) {
		contenuVecteur = vect;
	}
	Vecteur(size_t n) :
			contenuVecteur(vector < T > (n)) {
	}

	T& at(size_t n);
	T at(size_t n) const;
	void resize(size_t size);
	T somme() const;
	unsigned size() const noexcept;

	Vecteur<T> operator*(T valeur);
	Vecteur<T> operator*(Vecteur vect);
	Vecteur<T> operator+(Vecteur vect);
	Vecteur<T> operator-(Vecteur vect);

private:
	vector<T> contenuVecteur;
};
#include "VecteurImpl.h"
#endif // VECTEUR_H
