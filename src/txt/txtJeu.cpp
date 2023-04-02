#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "txtJeu.h"


void txtAff(WinTXT & win, const Jeu & jeu) {
	const Ocean & oce = jeu.getConstOcean();
	const Perso& poseidon = jeu.getConstPerso(0);
	const Perso& neptune = jeu.getConstPerso(1);

	win.clear();

	for(int x = 0 ; x < oce.getDimX() ; x++) {
		for(int y = 0 ; y < oce.getDimY() ; y++) {
			win.print(x, y, oce.getDimXY(x,y));
		}
	}


	win.print(poseidon.getPosX(), poseidon.getPosY(), 'V');
	win.print(neptune.getPosX(), neptune.getPosY(), 'P');
	win.draw();
}

void txtBoucle(Jeu & jeu) {
    WinTXT win (jeu.getConstOcean().getDimX(), jeu.getConstOcean().getDimY());

	bool en_jeu = true;
	int partie;
	auto tinitiale = chrono::system_clock::now();
	auto tbis = chrono::system_clock::now();
	do {
	    txtAff(win,jeu);
		auto tter = chrono::system_clock::now();
        jeu.getRequin(0).setTempsDeploiement((tter - tinitiale).count());
        if(jeu.getRequin(0).getTempsDeploiement() < 1){
            jeu.deployerRequin(jeu.getPerso(0), jeu.getOcean(), jeu.getRequin(0));
            if(jeu.getPerso(0).getEtatVie()==false)
                en_jeu=false;
        }

		auto tquar = chrono::system_clock::now();
        jeu.getRequin(1).setTempsDeploiement((tquar - tbis).count());
        if(jeu.getRequin(1).getTempsDeploiement() < 1){
            jeu.deployerRequin(jeu.getPerso(1), jeu.getOcean(), jeu.getRequin(1));
            if(jeu.getPerso(1).getEtatVie()==false)
                en_jeu=false;
        }

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(2000);
        #endif // WIN32
		partie = win.getCh();
		switch (partie) {
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;
			case 'o':
				jeu.actionClavier('b');
				break;
			case 'p':
				if(!jeu.getRequin(0).estSurLaMap) {
					jeu.actionClavier('u');
					tinitiale = tter;
				}
				break;

            case 's':
                jeu.actionClavier('v');
                break;
            case 'z':
	            jeu.actionClavier('j');
                break;
            case 'q':
                jeu.actionClavier('f');
                break;
            case 'd':
                jeu.actionClavier('o');
                break;
            case 'a':
				if(!jeu.getRequin(1).estSurLaMap) {
					jeu.actionClavier('m');
					tbis = tquar;
				}
                break;
            case 'e':
				en_jeu = false;
				break;
		}
	} while (en_jeu);
}
