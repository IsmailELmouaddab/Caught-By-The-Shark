#include "Couleur.h"
#include <cassert>

Couleur::Couleur(){
        r=v=b=0;
}

Couleur::Couleur(unsigned char nr,unsigned char nv,unsigned char nb){
    r=nr;
    v=nv;
    b=nb;
}

unsigned char Couleur::getRouge()const{
    assert(r>=0);
    return r;
}
unsigned char Couleur::getVert()const{
    assert(v>=0);
    return v;
}
unsigned char Couleur::getBleu()const{
    assert(b>=0);
    return b;
}

void Couleur::setRouge(unsigned char red){
    assert(red>=0);
    r=red;
}
void Couleur::setVert(unsigned char green){
    assert(green>=0);
    v=green;
}
void Couleur::setBleu(unsigned char blue){
    assert(blue>=0);
    b=blue;
}
