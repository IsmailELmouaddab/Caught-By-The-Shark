#ifndef OCEAN_H
#define OCEAN_H

#include "TabCorail.h"

class Ocean{
private:
    unsigned int dimensionX,dimensionY;
    char oce[125][125];
public:
    TabCorail corail;

    Ocean();
    bool posVal(const unsigned int x, const unsigned int y)const;
    void estTouche(unsigned int x,unsigned int y);
    void estMort(unsigned int x,unsigned int y);
    void RequinEstDeploye(unsigned int x,unsigned int y);
    void deposer(unsigned int x,unsigned int y);
    int getDimX()const;
    int getDimY()const;
    char getDimXY(const unsigned int x,const unsigned int y)const;
    char getType(unsigned int x,unsigned int y)const;
};
#endif // OCEAN_H
