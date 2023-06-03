#include "Perso.h"
#include <iostream>
#include <cassert>
using namespace std;

Perso::Perso()
{

	etatVie = true;   //: true si joueur vivant, false si joueur mort
	PaceX = PaceY = 1;
	posX = posY = 1;
	TabRequin requin;
}

Perso::Perso(unsigned int x, unsigned int y)
{
	assert(x >= 1 && y >= 1);
	posX = x;
	posY = y;
	PaceX = PaceY = 1;
	etatVie = true;
	TabRequin requin;
}

Perso::~Perso()
{
	posX = posY = 0;
	PaceX = PaceY = 0.0;
	etatVie = false;
}

int Perso::getPosX() const
{ return posX; }

int Perso::getPosY() const
{ return posY; }

void Perso::setPosXY(const unsigned int &x, const unsigned int &y)
{
	assert(posX >= 0 && posY >= 0);
	posX = x;
	posY = y;
}


bool Perso::getEtatVie() const
{ return etatVie; }

void Perso::setEtatVie(bool vie)
{ etatVie = vie; }

int Perso::getPaceX() const
{ return PaceX; }

int Perso::getPaceY() const
{ return PaceY; }

void Perso::setPaceXY(const float &x, const float &y)
{
	assert(PaceX > 0 && PaceY > 0);
	PaceX = x;
	PaceY = y;
}

void Perso::haut(const Ocean &o)
{
	if(o.posVal(posX,posY+1))
	posY++;
}

void Perso::bas(const Ocean &o)
{
	if(o.posVal(posX,posY-1))
	posY--;
}

void Perso::droite(const Ocean &o)
{
	if(o.posVal(posX+1,posY))
	posX++;
}

void Perso::gauche(const Ocean &o)
{
	if(o.posVal(posX-1,posY))
	posX--;
}

void Perso::testRegression()
{
	setPosXY(10,10);
	assert(getPosX() == 10 && getPosY() == 10);

	assert(PaceX >= 1 && PaceY >= 1);
	setPaceXY(10, 10);
	assert(getPaceX() == 10 && getPaceY() == 10);

	Perso(10, 10);
	assert(getPosX() == 10 && getPosY() == 10);


	assert(getEtatVie() != false);
}


