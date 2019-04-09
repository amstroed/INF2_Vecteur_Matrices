/*
 * Erreurs.h
 *
 *  Created on: 8 Apr 2019
 *      Author: Teo
 */

#ifndef ERREURS_H_
#define ERREURS_H_

#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Depassement_Capacite : public std::logic_error  {
public:
		explicit Depassement_Capacite(const string& what) : logic_error (what){

		}
		explicit Depassement_Capacite(const char* what) : logic_error (what){}

};

class Erreur_taille : public std::logic_error  {
public:
		explicit Erreur_taille(const string& what) : logic_error (what){


		}
		explicit Erreur_taille(const char* what) : logic_error (what){}

};



#endif /* ERREURS_H_ */
