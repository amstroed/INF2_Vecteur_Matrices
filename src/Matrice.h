#ifdef MATRICE_H
#define MATRICE_H

#include <vector>;
#include "Vecteur.h"

template <typename T>
class Vecteur
{
	friend std::ostream& operator <<(std::ostream& os, const Matrice& matrice
private:
	Vecteur<Vecteur<T>> contenuMatrice;
public :
	Matrice();
	Matrice(unsigned lignes);
	Matrice(unsigned lignes, unsigned colonnes);

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
	
	operator * (T valeur);
	operator * (Matrice matrice);
	operator + (Matrice matrice);
};

#endif // MATRICE_H