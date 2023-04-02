#include "Corail.h"
#include <cassert>
#include <stdlib.h>
#include <iostream>
using namespace std;

Corail::Corail(){
    posX=posY=0;
    coulCorail=Couleur(0,0,0);
    detruit=false;
}

Corail::Corail(unsigned int x,unsigned int y,bool etat,Couleur c){
    assert(x>=0 && y>=0);
    posX=x;
    posY=y;
    detruit=etat;
    coulCorail=c;
}

unsigned int Corail::getPosX()const{
    assert(posX>=0);
    return posX;
}

unsigned int Corail::getPosY()const{
    assert(posY>=0);
    return posY;
}

void Corail::setPosX(unsigned int x){
    assert(x>0);
    posX=x;
}

void Corail::setPosY(unsigned int y){
    assert(y>0);
    posY=y;
}

bool Corail::getDetruit(){
    return detruit;
}

void Corail::setDetruit(bool etat){
    detruit=etat;
}
