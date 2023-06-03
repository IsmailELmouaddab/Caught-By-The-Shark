 /**
  * @brief Module gérant le Personnage
  * @file Perso.h
*/
#ifndef PERSO_H
#define PERSO_H
#include "Couleur.h"
#include "Ocean.h"
#include <string>
#include "TabRequin.h"
using namespace std;

class Perso {
	private:

		/**
		 * @brief Vitesse en X et Y du personnage
		*/

		float PaceX, PaceY;
	public:
        /**
		 * @brief Position en X et Y du personnage
		*/
		unsigned int posX, posY;
        /**
		 * @brief Booléen pour savoir si le joueur est en vie
		*/
		bool etatVie;
        /**
		 * @brief Constructeur de base de la classe
		*/
		Perso();
		/**
		 * @brief Création du personnage de l'utilisateur
		 * @param x : entier
		 * @param y : entier
		*/
		Perso(unsigned int x, unsigned int y);
		/**
		 * @brief Destruction du personnage de l'utilisateur
		*/
		~Perso();
        /**
		 * @brief Accesseur pour la position en X
		*/
		int getPosX() const;
		/**
		 * @brief Accesseur pour la position en Y
		*/
		int getPosY() const;
		/**
		 * @brief Mutateur pour la position en X et Y
		 * @param x : entier
		 * @param y :entier
		*/
		void setPosXY(const unsigned int &x, const unsigned int &y);
        /**
		 * @brief Accesseur pour la vie du personnage
		*/
		bool getEtatVie() const;
		/**
		 * @brief Mutateur pour la vie du personnage
		*/
		void setEtatVie(bool vie);
        /**
		 * @brief Accesseur pour la vitesse en X
		*/
		int getPaceX() const;
		/**
		 * @brief Accesseur pour la vitesse en Y
		*/
		int getPaceY() const;
		/**
		 * @brief Mutateur pour la vitesse en X, Y
		 * @param x : entier
		 * @param y : entier
		*/
		void setPaceXY(const float &x, const float &y);
        /**
		 * @brief Déplacement du personnage
		*/
		void mouvement();
		/**
		 * @brief Incremente la position en y
		 * @param o :Ocean
		*/
		void haut(const Ocean &o);
		/**
		 * @brief Decremente la position en y
		 * @param o : Ocean
		*/
		void bas(const Ocean &o);
		/**
		 * @brief Incrémente la position en x
		 * @param o : Ocean
		*/
		void droite(const Ocean &o);
		/**
		 * @brief Decremene la position en x
		 * @param o : Ocean
		*/
		void gauche(const Ocean &o);
		/**
		 * @brief
		 * Test de regression
		*/

		void testRegression();
	};

#endif


