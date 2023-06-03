#ifndef CORAIL_H
#define CORAIL_H

#include "Couleur.h"
#include <string>
using namespace std;

class Corail{
private:

public:
    /**
     * @brief Position du corail
    */
    unsigned int posX,posY;
    /**
     * @brief Bool�en pour indiquer si la brique est d�truite
    */
    bool detruit;
    /**
     * @brief Constructeur par d�faut de la classe : : mise � jour de posX et posY � 0 et la couleure � noir
    */
    Corail();
    /**
     * @brief Constructeur de la classe : initialise sa position et sa couleur
     * @param x : entier non sign�
     * @param y : entier non sign�
     * @param etat : bool�en
     * @param c : Couleur
    */
    Corail(unsigned int x,unsigned int y,bool etat);
    /**
     * @brief Accesseur de la position en X d'un corail
    */
    unsigned int getPosX() const;
    /**
     * @brief Accesseur de la position en Y d'un corail
    */
    unsigned int getPosY() const;
    /**
     * @brief Mutateur de la position d'un corail
     * @param x : entier non sign�
    */
    void setPosX(unsigned int x);
    /**
     * @brief Mutateur de la position d'un corail
     * @param y : entier non sign�
    */
    void setPosY(unsigned int y);
    /**
     * @brief
     * Accesseur de l'�tat d'un corail
    */
    bool getDetruit();
    /**
     * @brief
     * D�rtruit un corail
     * @param etat : bool�en
    */
    void setDetruit(bool etat);
};
#endif // CORAIL_H
