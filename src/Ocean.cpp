#include "Ocean.h"
#include <iostream>
using namespace std;
#include <cassert>
#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

const char oce_test[9][30]{
"#############################",
"#  .........  #...####....  #",
"# .#.#.#.#.# ##   #   #...  #",
"# ##...##....  .#...#.....  #",
"# .#.##....### ....####     #",
"# #.#.#.#.#.# .    #  ..#   #",
"# #.#.#.#.#.# #.#.#.#.#.#.  #",
"#  .........  #    .......  #",
"#############################",
};

Ocean::Ocean(){
    dimensionX=30;
    dimensionY=9;
        for(unsigned int x=0;x<dimensionX;x++){
        for(unsigned int y=0;y<dimensionY;y++){
            oce[x][y]=oce_test[dimensionY-1-y][x];
        }
    }
}

void Ocean::deposer(unsigned int x,unsigned int y){
    assert(x>=0 && y>=0);
    assert(x<dimensionX && y<dimensionY);
    oce[x][y]='@';
}

void Ocean::estTouche(unsigned int x,unsigned int y){
    assert(x>=0 && y>=0);
    assert(x<dimensionX && y<dimensionY);
    if(oce[x][y]!='#'){
        oce[x][y]=' ';
    }
}

bool Ocean::posVal(const unsigned int x,const unsigned int y)const{
    return((x>=0)&&(y>=0)&&(x<dimensionX)&&(y<dimensionY)&&(oce[x][y]!='#')&&(oce[x][y]!='@')&&(oce[x][y]!='.'));
}

int Ocean::getDimX()const{
    assert(dimensionX>=0);
    return dimensionX;
}

int Ocean::getDimY()const{
    assert(dimensionY>=0);
    return dimensionY;
}
char Ocean::getType(unsigned int x,unsigned int y)const{
    assert(x>=0 && y>=0);
    assert(x<dimensionX && y<dimensionY);
    return oce[x][y];
}

void Ocean::RequinEstDeploye(unsigned int x,unsigned int y){
    assert(x>=0 && y>=0);
    assert(x<dimensionX && y<dimensionY);
    if(oce[x][y]=='@'){
        oce[x][y]=' ';
    }
}
void Ocean::estMort(unsigned int x,unsigned int y){
    assert(x>=0 && y>=0);
    assert(x<dimensionX && y<dimensionY);
    if(oce[x][y]=='V' || oce[x][y]=='P'){
        oce[x][y]=' ';
    }
}


char Ocean::getDimXY(const unsigned int x,const unsigned int y)const{
    assert(x>= 0 && y>=0);
    assert(x<dimensionX && y<dimensionY);
    return oce[x][y];
}
