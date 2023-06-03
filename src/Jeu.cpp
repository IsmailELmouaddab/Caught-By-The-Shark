#include "Jeu.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;

Jeu::Jeu():
    oce(),poseidon(1,1),neptune(27,7),r1(),r2(),cor(){
}

Ocean& Jeu::getOcean(){
    return oce;
}

Perso& Jeu::getPerso(int p){
    if(p==0){
        return poseidon;
    }
    if(p==1){
        return neptune;
    }
}

Requin& Jeu::getRequin(int q){
    if(q==0){
        return r1;
    }
    if(q==1){
        return r2;
    }
}

const Ocean& Jeu::getConstOcean()const{return oce;}
const Perso& Jeu::getConstPerso(int i)const{
    if(i==0){
        return poseidon;
    }
    if(i==1){
        return neptune;
    }
}
const Requin& Jeu::getConstRequin(int j)const{
    if(j==0){
        return r1;
    }
    if(j==1){
        return r2;
    }
}

void Jeu::poserRequin(Perso & test,Ocean& oce,Requin& r){
    oce.deposer(test.getPosX(),test.getPosY());
    r.estSurLaMap=true;
}

void Jeu::posRequin(Perso & test,Ocean& oce,Requin& r){
    r.setPosX(test.getPosX());
    r.setPosY(test.getPosY());
}

void Jeu::deployerRequin(Perso& test ,Ocean& oce,Requin& r){
    oce.estTouche(r.getPosX()+r.getRange() ,r.getPosY());
    oce.estTouche(r.getPosX()-r.getRange(),r.getPosY());
    oce.estTouche(r.getPosX(),r.getPosY()-r.getRange());
    oce.estTouche(r.getPosX(),r.getPosY()+r.getRange());
    oce.estTouche(r.getPosX(),r.getPosY());
    r.estSurLaMap=false;
}

void Jeu::mort(Perso &test,Ocean& oce,Requin& r){
    if((test.getPosX()==r.getPosX()+r.getRange() && test.getPosY()==r.getPosY()) ||(test.getPosX()==r.getPosX()-r.getRange() && test.getPosY()==r.getPosY())||
        (test.getPosX()==r.getPosX() && test.getPosY()==r.getPosY()+r.getRange())||(test.getPosX()==r.getPosX() && test.getPosY()==r.getPosY()-r.getRange())||
        (test.getPosX()==r.getPosX() && test.getPosY()==r.getPosY()))
        {
            test.etatVie=false;

        }
}

bool Jeu::actionClavier(const char t){
    switch(t){
    case 'g' :
        poseidon.gauche(oce);
        break;
    case 'd' :
        poseidon.droite(oce);
        break;
    case 'h':
        poseidon.haut(oce);
        break;
    case 'b':
        poseidon.bas(oce);
        break;
    case 'u':
        poserRequin(poseidon,oce,r1);
        posRequin(poseidon,oce,r1);
        break;

    case 'f':
        neptune.gauche(oce);
        break;
    case 'o':
        neptune.droite(oce);
        break;
    case 'v':
        neptune.haut(oce);
        break;
    case 'j':
        neptune.bas(oce);
        break;
    case 'm':
        poserRequin(neptune,oce,r2);
        posRequin(neptune,oce,r2);
        break;


    }
    return false;
}
