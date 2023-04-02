#include "ModeSDL.h"
#include <chrono>
#include<iostream>
using namespace std;
#include <assert.h>


const int TAILLE_SPRITE=32;
float duree(){
    return float(SDL_GetTicks())/CLOCKS_PER_SEC;
}

Joueur::Joueur(){
    surface=NULL;
    texture= NULL;
    changement=false;
}

void Joueur::chargerFichier(const char* filename,SDL_Renderer * renderer){
    surface=IMG_Load(filename);
    if(surface==NULL){
        string etat=string("./")+filename;
        cout<<"Erreur Impossible de charger le fichier"<<filename<<endl;
        surface=IMG_Load(etat.c_str());
        if(surface==NULL){
            etat=string("./")+etat;
            surface=IMG_Load(etat.c_str());
        }
    }
        if (surface == NULL) {
        cout<<"Erreur Impossible de charger la surface "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Erreur Impossible de creer la texture "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}
void Joueur::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Erreur impossible de creer la texture " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Joueur::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int etat;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;
    if (changement) {
        etat = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(etat == 0);
        changement = false;
    }

    etat = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(etat == 0);
}

SDL_Texture * Joueur::getTexture() const {return texture;}

void Joueur::setSurface(SDL_Surface * surf) {surface = surf;}

void Joueur::afficherMenu(SDL_Renderer * renderer){
    SDL_Surface* surface_message = TTF_RenderText_Solid(police, "Bienvenue dans Bomberman !", couleur);
    SDL_Texture* texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect rectangle_message = { 100, 50, surface_message->w, surface_message->h };
    SDL_RenderCopy(renderer, texture_message, NULL, &rectangle_message);
    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);

    // Ajouter des boutons
    SDL_Rect rectangle_bouton_jouer = { 150, 150, 100, 50 };
    SDL_Rect rectangle_bouton_quitter = { 150, 250, 100, 50 };

    SDL_Surface* surface_bouton_jouer = TTF_RenderText_Solid(police, "Jouer", couleur);
    SDL_Surface* surface_bouton_quitter = TTF_RenderText_Solid(police, "Quitter", couleur);

    SDL_Texture* texture_bouton_jouer = SDL_CreateTextureFromSurface(renderer, surface_bouton_jouer);
    SDL_Texture* texture_bouton_quitter = SDL_CreateTextureFromSurface(renderer, surface_bouton_quitter);

    SDL_RenderCopy(renderer, texture_bouton_jouer, NULL, &rectangle_bouton_jouer);
    SDL_RenderCopy(renderer, texture_bouton_quitter, NULL, &rectangle_bouton_quitter);

    SDL_FreeSurface(surface_bouton_jouer);
    SDL_FreeSurface(surface_bouton_quitter);
    SDL_DestroyTexture(texture_bouton_jouer);
    SDL_DestroyTexture(texture_bouton_quitter);

    // Rafraîchir l'écran
    SDL_RenderPresent(renderer);
}

sdlJeu::sdlJeu () : jeu() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la console SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "Erreur Impossible de charger SDL_Image" << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


	int dimx, dimy;
	dimx = jeu.getConstOcean().getDimX();
	dimy = jeu.getConstOcean().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Caught By The Shark", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* fenetre = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    // Initialisation de TTF pour le texte
    TTF_Init();
    TTF_Font* police = TTF_OpenFont("arial.ttf", 28);
    SDL_Color couleur = { 255, 255, 255 };

    // Afficher le menu
    afficher_menu(renderer);

    // Boucle principale pour gérer les événements
    bool en_cours = true;
    while (en_cours) {
        SDL_Event evenement;
        while (SDL_PollEvent(&evenement)) {
            if (evenement.type == SDL_QUIT) {
                en_cours = false;
            }
            if (evenement.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 150 && x <= 250 && y >= 150 && y <= 200) {
                    // Bouton "Jouer" cliqué
                    // Lancer le jeu
                }
                if (x >= 150 && x <= 250 && y >= 250 && y <= 300) {
                    // Bouton "Quitter" cliqué
                    en_cours = false;
                }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    in_poseidon.chargerFichier("data/perso.png", renderer);
    in_neptune.chargerFichier("data/perso.png", renderer);
    in_barriere.chargerFichier("data/BlueCoral.png", renderer);
    in_mur.chargerFichier("data/BLOC.png", renderer);
    in_r1.chargerFichier("data/Shark.gif", renderer);
    in_r2.chargerFichier("data/Shark.gif", renderer);
    in_ocean.chargerFichier("data/underwater_tileable.png", renderer);
    in_perdu.chargerFichier("data/perdu.png", renderer);


}

void sdlJeu::sdlAffichage () {
    SDL_SetRenderDrawColor(renderer, 180, 200, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Ocean& oce = jeu.getConstOcean();
	const Perso& poseidon = jeu.getConstPerso(0);
    const Perso& neptune = jeu.getConstPerso(1);
    const Requin& r1 = jeu.getConstRequin(0);
    const Requin& r2 = jeu.getConstRequin(1);
    // Afficher le sprite du sol
 //   renderer->x=520;renderer->y=32;renderer->h=32;renderer->w=68;

    for (x = 0 ; x < oce.getDimX() ; ++x) {
        for (y = 0 ; y < oce.getDimY() ; ++y) {
            in_ocean.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
        }
    }


	for (x=0 ; x < oce.getDimX() ; ++x) {
        for (y=0 ; y < oce.getDimY() ; ++y) {
            if (oce.getDimXY(x,y) == '#') {
                in_mur.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            }
			else if (oce.getDimXY(x,y) == '.') {
                in_barriere.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            }
        }
    }

	// Afficher le sprite des perso
    if(poseidon.etatVie == true){
        in_poseidon.draw(renderer, poseidon.getPosX() * TAILLE_SPRITE, poseidon.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(neptune.etatVie == true){
        in_neptune.draw(renderer, neptune.getPosX() * TAILLE_SPRITE, neptune.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(r1.estSurLaMap == true) {
        in_r1.draw(renderer, r1.getPosX() * TAILLE_SPRITE, r1.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(r2.estSurLaMap == true) {
        in_r2.draw(renderer, r2.getPosX() * TAILLE_SPRITE, r2.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(!poseidon.etatVie || !neptune.etatVie){
        in_perdu.draw(renderer, 90,50,300,300);
    }

}

sdlJeu::~sdlJeu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::boucleSDL () {
    SDL_Event events;
    bool quit = false;
    auto t0 = chrono::system_clock::now();
    auto t2 = chrono::system_clock::now();
    while (!quit) {
        auto t1 = chrono::system_clock::now();
        jeu.getRequin(0).setTempsDeploiement((t1 - t0).count());
        if(jeu.getRequin(0).estSurLaMap) {
            if(jeu.getRequin(0).getTempsDeploiement() < 1){
                jeu.deployerRequin(jeu.getPerso(0), jeu.getOcean(), jeu.getRequin(0));
                jeu.mort(jeu.getPerso(1), jeu.getOcean(), jeu.getRequin(0));
                jeu.mort(jeu.getPerso(0), jeu.getOcean(), jeu.getRequin(0));
            }
        }
        auto t3 = chrono::system_clock::now();
        jeu.getRequin(1).setTempsDeploiement((t3 - t2).count());
        if(jeu.getRequin(1).estSurLaMap) {
            if(jeu.getRequin(1).getTempsDeploiement() < 1){
                jeu.deployerRequin(jeu.getPerso(1), jeu.getOcean(), jeu.getRequin(1));
                jeu.mort(jeu.getPerso(1), jeu.getOcean(), jeu.getRequin(1));
                jeu.mort(jeu.getPerso(0), jeu.getOcean(), jeu.getRequin(1));
            }
        }


        while (SDL_PollEvent(&events)) {
            if(jeu.getPerso(0).etatVie && jeu.getPerso(1).etatVie) {
                if (events.type == SDL_QUIT) quit = true;
                else if (events.type == SDL_KEYDOWN) {
                    bool corailEstDetruit = false;
                    switch (events.key.keysym.sym) {
                        // Commandes du 1er joueur
                        case SDLK_o:
                            corailEstDetruit = jeu.actionClavier('b');
                            break;
                        case SDLK_l:
                            corailEstDetruit = jeu.actionClavier('h');
                            break;
                        case SDLK_k:
                            corailEstDetruit = jeu.actionClavier('g');
                            break;
                        case SDLK_m:
                            corailEstDetruit = jeu.actionClavier('d');
                            break;
                        case SDLK_p:
                            if(!jeu.getRequin(0).estSurLaMap) {
                                corailEstDetruit = jeu.actionClavier('u');
                                t0 = t1;
                            }
                            break;
                        case SDLK_s:
                            corailEstDetruit = jeu.actionClavier('v');
                            break;
                        case SDLK_z:
                            corailEstDetruit = jeu.actionClavier('j');
                            break;
                        case SDLK_q:
                            corailEstDetruit = jeu.actionClavier('f');
                            break;
                        case SDLK_d:
                            corailEstDetruit = jeu.actionClavier('o');
                            break;
                        case SDLK_a:
                            if(!jeu.getRequin(1).estSurLaMap) {
                                corailEstDetruit = jeu.actionClavier('m');
                                t2 = t3;
                            }
                            break;
                        case SDLK_e:
                            quit = true;
                            break;
                        default: break;
                    }
                }
            }
        }

        sdlAffichage();
        SDL_RenderPresent(renderer);
    }
}
