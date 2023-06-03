/**
  @brief Module gérant un tableau de requin
  @file TabRequin.h
*/
#ifndef TABREQUIN_H
#define TABREQUIN_H

#include "Requin.h"
#include <vector>
using namespace std;

class TabRequin{
private:
    /**
     * @brief
     * Tableau de taille variable de requins
    */
    vector<Requin> tabRequin;
    /**
     * @brief
     * Nombre de requins
    */
    unsigned int nbRequin;
public:
    /**
     * @brief
     * Constructeur de base de la classe
    */
    TabRequin();
    /**
     * @brief
     * Destructeur
    */
    ~TabRequin();
    /**
     * @brief
     * Accesseur du nombre de requins
    */
    unsigned int getNbRequin()const;
    /**
     * @brief
     * Mutateur pour ajouter un nouveau requin
     * @param n : unsigned int
    */
    void setNbRequin(unsigned int n);
    /**
     * @brief
     * Test de regression
    */
    void testRegression();
};
#endif // TABREQUIN_H
