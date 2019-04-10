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
	Matrice<int> lul(4,4);
   Matrice<int> lol(4,4);
	vector<int> lal = {1,2,3,4};
	Vecteur<int> lel = lal;
	cout << lel << endl;
	lul.at(2) = lel;
	lol.at(2) = lel;
	lul.at(0).at(2) = 213;
	lol.at(0).at(2) = 213;
	cout << lul << endl;

	cout << lul.sommeLigne() << endl;
	cout << lul.sommeColonne() << endl;
	cout << lul.sommeDiagonaleGD() << endl;
	cout << lul.sommeDiagonaleDG() << endl;
	cout << lul << endl;
	lul = lul * 3;
	cout << lul << endl;
	lul = lol * lul;
	cout << lul << endl;
	lul = lol + lul;
	cout << lul << endl;
	lul.resize(3, 3);
	cout << lul << endl;
}
