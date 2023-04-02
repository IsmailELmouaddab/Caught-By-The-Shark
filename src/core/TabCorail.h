#ifndef TABCORAIL_H
#define TABCORAIL_H
#include <iostream>
#include <vector>
#include <string>
#include "Couleur.h"
#include "Corail.h"
using namespace std;

class TabCorail{
private:
    vector<Corail> tabCorail;
    unsigned int nbCorail;
public:
    TabCorail();
    ~TabCorail();
    unsigned int getNbCorail();
    void setNbCorail(unsigned int nbCorail2);
    void testRegression();
};

#endif
