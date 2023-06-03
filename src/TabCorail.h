/**
  @brief Module gérant un tableau de Corail
  @file TabCorail.h
*/
#ifndef TABCORAIL_H
#define TABCORAIL_H
#include <iostream>
#include <vector>
#include <string>
#include "Couleur.h"
#include "Corail.h"
using namespace std;

class TabCorail{
private:
    /**
     * @brief
     * Tableau de taille variable de corail
    */
    vector<Corail> tabCorail;
    /**
     * @brief
     * Le nombre de coraux
    */
    unsigned int nbCorail;
public:
    /**
     * @brief
     * Constructeu de base de la classe
    */
    TabCorail();
    /**
     * @brief
     * Destructeur
    */
    ~TabCorail();
    /**
     * @brief
     * Accesseur du nombre de Coraux
    */
    unsigned int getNbCorail();
    /**
     * @brief
     * Mutateur de nombre de coraux
     * @param nbCorail2 : int
    */
    void setNbCorail(unsigned int nbCorail2);
    /**
     * @brief
     * test de regression
    */
    void testRegression();
};

#endif
