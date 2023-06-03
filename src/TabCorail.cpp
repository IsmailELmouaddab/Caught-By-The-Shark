#include "TabCorail.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cassert>
using namespace std;

TabCorail::TabCorail()
{
	nbCorail = 1;
	vector<Corail> tabCorail;
	tabCorail.resize(nbCorail);
}

TabCorail::~TabCorail()
{
	nbCorail = 0;
	tabCorail.clear();
}

unsigned int TabCorail::getNbCorail()
{
	assert(nbCorail >= 0);
	return nbCorail;
}

void TabCorail::setNbCorail(unsigned int nbCorail2)
{
	assert(nbCorail2 >= 0);
	nbCorail = nbCorail2;
}

void TabCorail::testRegression()
{
	assert(getNbCorail() == 1);
	setNbCorail(5);
	assert(getNbCorail() == 5);

	Corail corail1;
	assert(corail1.posX == 0 && corail1.posY == 0);
	corail1.setPosX(10);
	corail1.setPosY(10);
	assert(corail1.posX == 10 && corail1.posY == 10);

	assert(corail1.detruit == false);
	corail1.setDetruit(true);
	assert(corail1.getDetruit() == true);

	tabCorail.resize(5);
//assert(tabCorail.size == 5);//
}
