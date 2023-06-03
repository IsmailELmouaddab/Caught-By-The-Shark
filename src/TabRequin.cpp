#include "TabRequin.h"
#include "Requin.h"
#include <cassert>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

TabRequin::TabRequin(){
    nbRequin=1;
    vector<Requin> tabRequin;
    tabRequin.resize(nbRequin);
}

TabRequin::~TabRequin(){
    tabRequin.clear();
}

unsigned int TabRequin::getNbRequin()const{
    assert(nbRequin>0);
    return nbRequin;
}

void TabRequin::setNbRequin(unsigned int n){
    assert(n>0);
    nbRequin=n;
}

void TabRequin::testRegression(){
    Requin Requin1(1,2,3);
    assert(Requin1.getPosX()==1);
    assert(Requin1.getPosY()==2);
    assert(Requin1.getRange()==3);

    Requin1.setPosX(10);
    assert(Requin1.getPosX()==10);

    Requin1.setPosY(11);
    assert(Requin1.getPosY()==11);

    Requin1.setRange(4);
    assert(Requin1.getRange()==4);

    assert(getNbRequin()==1);
    setNbRequin(5);
    assert(nbRequin==5);

    tabRequin.resize(6);
    assert(tabRequin.size()==6);

    tabRequin.push_back(Requin1);
    assert(tabRequin[6].getPosX()== 10);
    assert(tabRequin[6].getPosY()==11);
    assert(tabRequin[6].getRange()==4);

}
