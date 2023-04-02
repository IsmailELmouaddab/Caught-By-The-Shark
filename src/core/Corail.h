#ifndef CORAIL_H
#define CORAIL_H

#include "Couleur.h"
#include <string>
using namespace std;

class Corail{
private:
    Couleur coulCorail;
public:
    unsigned int posX,posY;
    bool detruit;
    Corail();
    Corail(unsigned int x,unsigned int y,bool etat,Couleur c);
    unsigned int getPosX() const;
    unsigned int getPosY() const;
    void setPosX(unsigned int x);
    void setPosY(unsigned int y);
    bool getDetruit();
    void setDetruit(bool etat);
};
#endif // CORAIL_H
