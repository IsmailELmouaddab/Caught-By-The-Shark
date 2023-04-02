#include "TabPerso.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>
using namespace std;

TabPerso::TabPerso()
{
	nbPerso = 2;
	vector<Perso> tabPerso;
	tabPerso.resize(nbPerso);
}

TabPerso::~TabPerso()
{
	tabPerso.clear();
}

unsigned int TabPerso::getNbPerso() const
{
	assert(nbPerso > 0);
	return nbPerso;
}

void TabPerso::setNbPerso(unsigned int nbPerso2)
{
	assert(nbPerso2 > 0);
	nbPerso = nbPerso2;
}

void TabPerso::testRegression()
{
	assert(getNbPerso()== 2);
	setNbPerso(4);
	assert(getNbPerso()== 4);
}
