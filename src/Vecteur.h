#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>;

template <typename T>
class Vecteur
{
	friend std::ostream& operator <<(std::ostream& os, const Vecteur& vect);
private :
	vector<T> contenuVecteur;
public :
	Vecteur(vector<T>);
	Vecteur(size_t n);

	T at(n);
	void resize(size_t size);
	T somme();

	operator * (T valeur);
	operator * (Vecteur vect);
	operator + (Vecteur vect);
	operator - (Vecteur vect);
};

#endif // VECTEUR_H
