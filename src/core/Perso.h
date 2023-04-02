#ifndef PERSO_H
#define PERSO_H
#include "Couleur.h"
#include "Ocean.h"
#include <string>
#include "TabRequin.h"
using namespace std;

class Perso {
	private:
		Couleur cPerso;

		float PaceX, PaceY;
	public:
		unsigned int posX, posY;

		bool etatVie;

		Perso();
		Perso(unsigned int x, unsigned int y);
		~Perso();

		int getPosX() const;
		int getPosY() const;
		void setPosXY(const unsigned int &x, const unsigned int &y);

		bool getEtatVie() const;
		void setEtatVie(bool vie);

		int getPaceX() const;
		int getPaceY() const;
		void setPaceXY(const float &x, const float &y);

		void mouvement();
		void haut(const Ocean &o);
		void bas(const Ocean &o);
		void droite(const Ocean &o);
		void gauche(const Ocean &o);

		void testRegression();
	};

#endif


