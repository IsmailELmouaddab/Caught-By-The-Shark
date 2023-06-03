#ifndef REQUIN_H
#define REQUIN_H
#include <chrono>

/**
  @brief Module gérant un Requin
  @file Requin.h
*/
class Requin{
private:
    /**
     * @brief Position du requin
    */
    unsigned int posX,posY;
    /**
     * @brief Range du requin
    */
    int range;
public:
    /**
     * @brief Temps avant l'activation du requin
    */
    unsigned int tempsDeploiement;// temps activation
    /**
     * @brief Booléen vrai si le requin est sur le terrain
    */
    bool estSurLaMap;// check si le requin est sur la map
     /**
     * @brief Constructeur par défaut de la classe : initialise la position à 0 et la portée à 0
    */
    Requin(); //construceur
    /**
     * @brief Constructeur de la classe : initialise la position avec positionX, positionY et la portée avec nouvPortee
     * @param positionX : unsigned int
     * @param positionY : unsigned int
     * @param nouvRange : int
    */
    Requin(unsigned int positionX,unsigned int positionY, int newRange); //initialise la position x,y et la nouvelle portee
    /**
     * @brief Accesseur : récupère la position X du requin
    */
    unsigned int getPosX() const;
    /**
     * @brief Accesseur : récupère la position Y du requin
    */
    unsigned int getPosY() const;
    /**
     * @brief Mutateur : modifie la position X du requin
     * @param x : unsigned int
     * @param y : unsigned int
    */
    void setPosX(unsigned int x);
    /**
     * @brief Mutateur : modifie la position Y du requin
     * @param x : unsigned int
     * @param y : unsigned int
    */
    void setPosY(unsigned int y);
    /**
     * @brief Accesseur : récupère la portée du requin
    */
    int getRange() const;
    /**
     * @brief Mutateur : modifie la portée du requin
     * @param r : int
    */
    void setRange(int r);
    /**
     * @brief Accesseur : accède au temps d'activation du requin
    */
    int getTempsDeploiement() const;
    /**
     * @brief Mutateur : modifie le temps d'activation du requin
     * @param t : int
    */
    void setTempsDeploiement(int t);
    /**
     * @brief Fonction qui définit un compteur pour l'activation
    */
    void compteurDeploiement();
    };
#endif // REQUIN_H
