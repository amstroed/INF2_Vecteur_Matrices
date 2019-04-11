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
   
   cout << "Tests sur les Vecteurs" << endl;
   Vecteur<int> v1(vector<int>(1,2,3,4));
   Vecteur<int> v2(4);
   cout << "elements de v1 : " << v1 << " taille de v1 : " << v1.size() << endl;
   v2 = v1;
   v1.at(2) = v2.at(3);
   v2.resize(3);
   cout << "elements de v2 apres un resize à 3 : " << v2 << endl;
   cout << "somme des elements de v2 : " << v2.somme() << endl;
   cout << "elements de v1 multiplies par 2 : " << v1 * v2 << endl;
   cout << "elements de v1 multiplies par les elements de v2 : " << v1 << endl;
   cout "elements de v1 + elements de v2 : " << v1 + v2 << endl;
   cout << "elements de v1 - elements de v2 : " v1 - v2 << endl;

   cout << "Tests sur les matrices" << endl;
   Matrice<int> m1(4,4);
   Matrice<int> m2(4,4);
   m1.at(2) = v2;
   m2.at(2) = v2;
   m1.at(0).at(2) = 213;
   m2.at(0).at(2) = 213;
   cout << "Elements de m1 : " << m1 << endl;
   cout << "Somme des elements de chaque ligne de m1 : " << m1.sommeLigne() << endl;
   cout << "Somme des elements de chaque colonne de m1 : " 
           << m1.sommeColonne() << endl;
   cout << "Somme de la diagonale GD de m1 : " << m1.sommeDiagonaleGD() << endl;
   cout << "Somme de la diagonale DG de m1 : " << m1.sommeDiagonaleDG() << endl;
   cout << "Elements de m1 : " << m1 << endl;
   cout << "Elements de m1 multiplies par 3 : " << m1 * 3 << endl;
   m1 = m2 * m1;
   cout << "elements de m1 apres multiplication par les elements de m2" 
           << m1 << endl;
   m1 = m2 + m1;
   cout << "Elements de m1 apres addition avec les elements de m2" << m1 << endl;
   m1.resize(3, 3);
   cout << "Elements de m1 apres un resize a 3,3 : " << m1 << endl;
   cout << "Taille de m1 : " << m1.size();
   cout << "Premier element de m1 : " << m1.at(0);
   cout << "Reponse a m1.estVide() : " << m1.estVide() << endl;
   cout << "Reponse a m1.estReguliere() : " << m1.estReguliere() << endl;
   cout << "Reponse a m1.estCarree : " << m1.estCarree() << endl;
}
