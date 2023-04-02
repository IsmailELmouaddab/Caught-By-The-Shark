#include "Requin.h"
#include <cassert>
#include <chrono>
using namespace std;

Requin::Requin(){
    posX=posY=1;
    range=1;
    tempsDeploiement=0;
    estSurLaMap=false;
}

Requin::Requin(unsigned int positionX,unsigned int positionY,int newRange){
    assert(positionX>=0);
    assert(positionY>=0);
    posX=positionX;
    posY=positionY;
    range=newRange;
}

unsigned int Requin::getPosX()const{
    assert(posX>=0);
    return posX;
}

unsigned int Requin::getPosY()const{
    assert(posY>=0);
    return posY;
}

void Requin::setPosX(unsigned int x){
    assert(x>=0);
    posX=x;
}

void Requin::setPosY(unsigned int y){
    assert(y>=0);
    posY=y;
}

int Requin::getRange()const{
    assert(range>=0);
    return range;
}

void Requin::setRange(int r){
    assert(r>=0);
    range=r;
}

int Requin::getTempsDeploiement() const{
    assert(tempsDeploiement>=0);
    return tempsDeploiement;
}

void Requin::setTempsDeploiement(int t){
    //assert(t>=0);//
    tempsDeploiement=t;
}

void Requin::compteurDeploiement(){
    auto debut= std::chrono::system_clock::now();
        auto fin= std::chrono::system_clock::now();
        while(std::chrono::duration_cast<std::chrono::seconds>(fin - debut).count()<2.0){
            fin = std::chrono::system_clock::now();
        }
}
