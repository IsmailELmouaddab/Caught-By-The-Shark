/**
  @brief Module gérant un tableau de Personnage
  @file TabPerso.h
*/
#ifndef TABPERSO_H
#define TABPERSO_H
#include <vector>
#include "Perso.h"
using namespace std;

class TabPerso{
	private:
	    /**
      * @brief
      * Tableau de taille variable de perso
    */
		vector<Perso> tabPerso;
		/**
      * @brief
      * nombre de perso
    */
		unsigned int nbPerso;
	public:
	    /**
      * @brief
      * Constructeur de la classe
    */
		TabPerso();
		/**
      * @brief
      * Destructeur
    */
		~TabPerso();
		/**
     * @brief
     * Accesseur du nombre de perso
    */

		unsigned int getNbPerso() const;
		/**
     * @brief
     * Mutateur pour ajouter un nouveau joueur
     * @param nbPerso2: unsigned int
    */
		void setNbPerso(unsigned int nbPerso2);
        /**
     * @brief
     * Test de regression
    */
		void testRegression();
		};
#endif
