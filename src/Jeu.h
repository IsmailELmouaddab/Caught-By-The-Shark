/**
 * @brief le jeu
 * @file Jeu.h
*/
#ifndef _JEU_H
#define _JEU_H
#include "Perso.h"
#include "Ocean.h"

class Jeu{
private:
     /**
         * @brief terrain
        */
    Ocean oce;
    /**
         * @brief perso 1
        */
    Perso poseidon;
    /**
         * @brief perso 2
        */
    Perso neptune;
    /**
         * @brief Requin pour personnage 1 et personnage 2
        */
    Requin r1,r2;
    /**
         * @brief tableau de coraux
        */
    TabCorail cor;
    /**
         * @brief tableau de requins
        */
    TabRequin req;
public:
    /**
         * @brief constructeur par défaut de la classe jeu
        */
    Jeu();
    /**
         * @brief accesseur : permet d'accéder au terrain
        */
    Ocean& getOcean();
    /**
         * @brief accesseur : permet d'accéder à un personnage
         * @param p : entier
        */
    Perso& getPerso(int p);
    /**
         * @brief accesseur : permet d'accéder à un requin
         * @param q : entier
        */
    Requin& getRequin(int q);
    /**
         * @brief accesseur : permet d'accéder au terrain
        */
    const Ocean& getConstOcean()const;
    /**
         * @brief accesseur : permet d'accéder à un requin
         * @param j : entier
        */
    const Requin& getConstRequin(int j)const;
    /**
         * @brief accesseur : permet d'accéder à un personnage
         * @param i : entier
        */
    const Perso& getConstPerso(int i)const;
    /**
         * @brief Fonction qui modifie la position du requin sur le terrain en fonction du personnage
         * @param p1 : perso
         * @param oce : Ocean
         * @param r : Requin
        */
    void posRequin(Perso& p1, Ocean& oce, Requin& r);
    /**
         * @brief Fonction qui permet l'activation d'un requin
         * @param p1 : perso
         * @param oce : Ocean
         * @param r : requin
        */
    void deployerRequin(Perso& p1, Ocean& oce, Requin& r);
    /**
         * @brief Fonction qui permet de poser un requin sur le terrain en fonction des positions d'un personnage
         * @param p1 : perso
         * @param oce : Ocean
         * @param r : requin
        */
    void poserRequin(Perso& p1,Ocean& oce,Requin& r);
    /**
         * @brief Permet de placer et de faire exploser les briques autour d'une bombe
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
    void deployerEtPoser(Perso& p1,Ocean & oce,Requin& r);
    /**
         * @brief Permet de tuer un perso si il est touché
         * @param p1 : personnage
         * @param oce : Ocean
         * @param r : requin
        */
    void mort(Perso& p1,Ocean& oce,Requin& r);
     /**
         * @brief Permet de réaliser une action en appuyant sur une touche du clavier
         * @param t : caractère
        */
    bool actionClavier(const char t);

};

#endif // _JEU_H
