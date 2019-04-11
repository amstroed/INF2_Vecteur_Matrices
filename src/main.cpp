/*
 ---------------------------------------------------------------------------------- -
 Laboratoire : G�N�RICIT� ET EXCEPTIONS
 Fichier : main.cpp
 Auteur(s) : Lo�c Geinoz, Teo Ferrari
 Date : 09.04.2019

 But : fichier utilis� afin de v�rifier et tester les diff�rentes fonctionnalit�s
 d�velopp�es pour les classes Vecteur et Matrice
 ---------------------------------------------------------------------------------- -
 */

using namespace std;
#include "Matrice.h"
#include "Vecteur.h"

int main() {

	cout << "test de fonctionnement normal:" << endl;
	Matrice<int> matrice1(4, 4);
	Matrice<int> matrice2(4, 3);
	vector<int> vector1 = { 1, 2, 3, 4 };
	Vecteur<int> vecteur1 = vector1;
	cout << "cout de vecteur1: " << vecteur1 << endl;
	matrice1.at(2) = vecteur1;
	matrice2.at(2) = vecteur1;
	matrice1.at(0).at(2) = 213;
	matrice2.at(0).at(2) = 213;

	cout << "cout de matrice 1: " << matrice1 << endl;

	cout << "résultat de sommeLigne sur matrice1: " << matrice1.sommeLigne()
			<< endl;
	cout << "résultat de sommeColonne sur matrice1: " << matrice1.sommeColonne()
			<< endl;
	cout << "résultat de sommeDiagonaleGD sur matrice1: "
			<< matrice1.sommeDiagonaleGD() << endl;
	cout << "résultat de sommeDiagonaleDG sur matrice1: "
			<< matrice1.sommeDiagonaleDG() << endl;
	cout << "test de multiplcation avec une constante (3): " << matrice1 * 3
			<< endl;
	cout << "test de multiplcation avec une autre matrice(la meme): "
			<< matrice2 * matrice1 << endl;
	cout << "test d'addition avec une autre matrice(la meme): "
			<< matrice2 + matrice1 << endl;

	matrice1.resize(3, 3);
	cout << "test de resize(3,3): " << matrice1 << endl;
}
