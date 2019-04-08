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

class Erreur_taille : public std::logic_error  {
public:
   Erreur_taille(int no, const string& msg="") noexcept
   : logic_error(msg), no(no) {};

   int noErreur () const noexcept{
      return no;
   };

private:
   int no;

};



#endif /* ERREURS_H_ */
