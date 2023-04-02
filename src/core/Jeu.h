#ifndef _JEU_H
#define _JEU_H
#include "Perso.h"
#include "Ocean.h"

class Jeu{
private:
    Ocean oce;
    Perso poseidon;
    Perso neptune;
    Requin r1,r2;
    TabCorail cor;
    TabRequin req;
public:
    Jeu();
    Ocean& getOcean();
    Perso& getPerso(int p);
    Requin& getRequin(int q);
    const Ocean& getConstOcean()const;
    const Requin& getConstRequin(int j)const;
    const Perso& getConstPerso(int i)const;
    void posRequin(Perso& p1, Ocean& oce, Requin& r);
    void deployerRequin(Perso& p1, Ocean& oce, Requin& r);
    void poserRequin(Perso& p1,Ocean& oce,Requin& r);
    void deployerEtPoser(Perso& p1,Ocean & oce,Requin& r);
    void mort(Perso& p1,Ocean& oce,Requin& r);
    bool actionClavier(const char t);

};

#endif // _JEU_H
