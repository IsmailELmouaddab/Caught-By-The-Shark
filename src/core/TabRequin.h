#ifndef TABREQUIN_H
#define TABREQUIN_H

#include "Requin.h"
#include <vector>
using namespace std;

class TabRequin{
private:
    vector<Requin> tabRequin;
    unsigned int nbRequin;
public:
    TabRequin();
    ~TabRequin();
    unsigned int getNbRequin()const;
    void setNbRequin(unsigned int n);
    void testRegression();
};
#endif // TABREQUIN_H
