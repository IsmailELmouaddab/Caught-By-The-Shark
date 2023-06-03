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
     * @brief Booléen pour indiquer si la brique est détruite
    */
    bool detruit;
    /**
     * @brief Constructeur par défaut de la classe : : mise à jour de posX et posY à 0 et la couleure à noir
    */
    Corail();
    /**
     * @brief Constructeur de la classe : initialise sa position et sa couleur
     * @param x : entier non signé
     * @param y : entier non signé
     * @param etat : booléen
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
     * @param x : entier non signé
    */
    void setPosX(unsigned int x);
    /**
     * @brief Mutateur de la position d'un corail
     * @param y : entier non signé
    */
    void setPosY(unsigned int y);
    /**
     * @brief
     * Accesseur de l'état d'un corail
    */
    bool getDetruit();
    /**
     * @brief
     * Dértruit un corail
     * @param etat : booléen
    */
    void setDetruit(bool etat);
};
#endif // CORAIL_H
