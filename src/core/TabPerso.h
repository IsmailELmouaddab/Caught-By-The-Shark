#ifndef TABPERSO_H
#define TABPERSO_H
#include <vector>
#include "Perso.h"
using namespace std;

class TabPerso{
	private:
		vector<Perso> tabPerso;
		unsigned int nbPerso;
	public:
		TabPerso();
		~TabPerso();

		unsigned int getNbPerso() const;
		void setNbPerso(unsigned int nbPerso2);

		void testRegression();
		};
#endif
