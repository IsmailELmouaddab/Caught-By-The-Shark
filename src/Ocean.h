/**
 * @brief Module gérant le terrain du jeu
 * @file Ocean.h
*/
#ifndef OCEAN_H
#define OCEAN_H

#include "TabCorail.h"

class Ocean{
private:
    /**
		 * @brief dimension du terrain en x et y
		*/
    unsigned int dimensionX,dimensionY;
    /**
		 * @brief dimension du terrain en x et en y
		*/
    char oce[125][125];
public:
/**
		 * @brief tableau de corail
		*/
    TabCorail corail;
/**
		 * @brief constructeur de la classe
		*/
    Ocean();
    /**
		 * @brief Booléen qui renvoie vrai si on peut positionner le personnage en X,Y
		 * @param x : entier
		 * @param y : entier
		*/
    bool posVal(const unsigned int x, const unsigned int y)const;
/**
		 * @brief Explose les coraux autour du requin
		 * @param x : entier
		 * @param y : entier
		*/
    void estTouche(unsigned int x,unsigned int y);
    /**
		 * @brief Tue un personnage si a cote du requin
		 * @param x : entier
		 * @param y : entier
		*/
    void estMort(unsigned int x,unsigned int y);
    /**
		 * @brief supprime le requin si deployé
		 * @param x : entier
		 * @param y : entier
		*/
    void RequinEstDeploye(unsigned int x,unsigned int y);
    /**
		 * @brief Place un requin
		 * @param x : entier
		 * @param y : entier
		*/
    void deposer(unsigned int x,unsigned int y);
    /**
		 * @brief Renvoie la position x
		*/
    int getDimX()const;
    /**
		 * @brief Renvoie la position y
		*/
    int getDimY()const;

    char getDimXY(const unsigned int x,const unsigned int y)const;
     /**
		 * @brief Renvoie le type d'objet se trouvant en X,Y
		 * @param x : entier
		 * @param y : entier
		*/
    char getType(unsigned int x,unsigned int y)const;
};
#endif // OCEAN_H
