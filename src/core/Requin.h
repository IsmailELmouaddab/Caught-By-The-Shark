#ifndef REQUIN_H
#define REQUIN_H
#include <chrono>

class Requin{
private:
    unsigned int posX,posY;
    int range;
public:
    unsigned int tempsDeploiement;// temps activation
    bool estSurLaMap;// check si le requin est sur la map
    Requin(); //construceur
    Requin(unsigned int positionX,unsigned int positionY, int newRange); //initialise la position x,y et la nouvelle portee
    unsigned int getPosX() const;
    unsigned int getPosY() const;
    void setPosX(unsigned int x);
    void setPosY(unsigned int y);
    int getRange() const;
    void setRange(int r);
    int getTempsDeploiement() const;
    void setTempsDeploiement(int t);
    void compteurDeploiement();
    };
#endif // REQUIN_H
