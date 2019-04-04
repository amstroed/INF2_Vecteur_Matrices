#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include "Vecteur.h"
#include <vector>


using namespace std;

template <typename T>
T& Vecteur<T>::at(unsigned n)
{
	return this->contenuVecteur.at(n);
}

template <typename T>
T Vecteur<T>::at(size_t n) const
{

}

template <typename T>
void Vecteur<T>::resize(size_t nouvelleCapacite)
{
	if (nouvelleCapacite < capaciteVecteur)
	{
		//A definir
		//throw();
	}
	this->capaciteVecteur = size;
}

template <typename T>
unsigned Vecteur<T>::size()
{
	return this->tailleVecteur;
}

template <typename T>
T Vecteur<T>::somme() const
{
	T somme = T();
	for (size_t i = 0; i < this->tailleVecteur; ++i)
	{
		somme += this->contenuVecteur.at(i);
	}
	return somme;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator*(T valeur)
{
	for (size_t i = 0; i < this->tailleVecteur; ++i)
	{
		this->contenuVecteur.at(i) *= valeur;
	}
}

template <typename T>
Vecteur<T> Vecteur<T>::operator * (Vecteur vect)
{
	if (vect.taille != this->taille)
	{
		//a definir
		//throw();
	}
	else
	{
		for (size_t i = 0; i < this->tailleVecteur; ++i)
		{
			this->contenuVecteur.at(i) *= vect.contenuVecteur.at(i);
		}
	}
}
template <typename T>
Vecteur<T> Vecteur<T>::operator + (Vecteur vect)
{
	if (vect.taille != this->taille)
	{
		//a definir
		//throw();
	}
	else
	{
		for (size_t i = 0; i < this->tailleVecteur; ++i)
		{
			this->contenuVecteur.at(i) += vect.contenuVecteur.at(i);
		}
	}
}

template <typename T>
Vecteur<T> Vecteur<T>::operator - (Vecteur vect)
{
	if (vect.taille != this->taille)
	{
		//a definir
		//throw();
	}
	else
	{
		for (size_t i = 0; i < this->tailleVecteur; ++i)
		{
			this->contenuVecteur.at(i) -= vect.contenuVecteur.at(i);
		}
	}
}

#endif // VECTEURIMPL_H
