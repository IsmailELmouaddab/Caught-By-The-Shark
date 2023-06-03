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
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;


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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    in_poseidon.chargerFichier("data/perso.png", renderer);
    in_neptune.chargerFichier("data/perso.png", renderer);
    in_barriere.chargerFichier("data/BlueCoral.png", renderer);
    in_mur.chargerFichier("data/BLOC.png", renderer);
    in_r1.chargerFichier("data/Shark.gif", renderer);
    in_r2.chargerFichier("data/Shark.gif", renderer);
    in_ocean.chargerFichier("data/underwater_tileable.png", renderer);
    in_win1.chargerFichier("data/winner1.png", renderer);
    in_win2.chargerFichier("data/winner2.png",renderer);
    in_menu.chargerFichier("data/ocean.png",renderer);
    in_tuto.chargerFichier("data/tuto.png",renderer);

    if (withSound)
    {
        soundBackground = Mix_LoadWAV("data/fond.wav");
        soundPosRequin=Mix_LoadWAV("data/IMG_0.wav");
        Mix_VolumeChunk(soundBackground, MIX_MAX_VOLUME/40);
        if (soundBackground == NULL) {
            soundBackground = Mix_LoadWAV("data/fond.wav");
        }if(soundPosRequin==NULL){
            soundPosRequin=Mix_LoadWAV("data/IMG_0.wav");
        }
        if (soundBackground == NULL) {
            cout << "Failed to load wav! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
    }
}
sdlJeu::~sdlJeu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAffichage() {
    SDL_SetRenderDrawColor(renderer, 180, 200, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Ocean& oce = jeu.getConstOcean();
	const Perso& poseidon = jeu.getConstPerso(0);
    const Perso& neptune = jeu.getConstPerso(1);
    const Requin& r1 = jeu.getConstRequin(0);
    const Requin& r2 = jeu.getConstRequin(1);
    // Afficher le sprite du sol

    for (x = 0 ; x < oce.getDimX() ; ++x) {
        for (y = 0 ; y < oce.getDimY() ; ++y) {
            in_ocean.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
        }
    }


	for (x=0 ; x < oce.getDimX() ; ++x) {
        for (y=0 ; y < oce.getDimY(); ++y) {
            if (oce.getDimXY(x,y) == '#') {
                in_mur.draw(renderer, x * (TAILLE_SPRITE+1.2), y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            }
			else if (oce.getDimXY(x,y) == '.') {
                in_barriere.draw(renderer, x * (TAILLE_SPRITE+1.2), y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            }
        }
    }

	// Afficher le sprite des perso
    if(poseidon.etatVie == true){
        in_poseidon.draw(renderer, poseidon.getPosX() * (TAILLE_SPRITE+1.2), poseidon.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(neptune.etatVie == true){
        in_neptune.draw(renderer, neptune.getPosX() * (TAILLE_SPRITE+1.2), neptune.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(r1.estSurLaMap == true) {
        in_r1.draw(renderer, r1.getPosX() * (TAILLE_SPRITE+1.2), r1.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(r2.estSurLaMap == true) {
        in_r2.draw(renderer, r2.getPosX() * (TAILLE_SPRITE+1.2), r2.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(!poseidon.etatVie ){
    int window_width, window_height;
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Coordonnées de dessin centrées dans la fenêtre
    int x = (window_width - 300) / 2;
    int y = (window_height - 300) / 2;

    in_win1.draw(renderer, x, y, 300, 300);
}
if(!neptune.etatVie){
    int window_width, window_height;
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Coordonnées de dessin centrées dans la fenêtre
    int x = (window_width - 300) / 2;
    int y = (window_height - 300) / 2;

    in_win2.draw(renderer, x, y, 300, 300);
}

}

void sdlJeu::sdlTuto(){
         bool quit = false;



    font = TTF_OpenFont("./data/stocky.ttf", 28);
    if (font == nullptr) {
        cout << "Failed to load .ttf! TTF_Font Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    while (!quit) {
        // Affichage du menu
        SDL_SetRenderDrawColor(renderer, 180, 200, 255, 255);
        SDL_RenderClear(renderer);
        in_tuto.draw(renderer, 0,0, 1000, 300);

        // Affichage du bouton "Jouer"
        SDL_Rect jouerRect = {435,220, 100, 50};
        SDL_SetRenderDrawColor(renderer, 100, 100, 200, 255);
        SDL_RenderFillRect(renderer, &jouerRect);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &jouerRect);

        // Affichage du texte "Jouer"
        SDL_Color fontColor={255,255,255,255};
        SDL_Surface *jouerSurface = TTF_RenderText_Solid(font, "Retour", fontColor);
        if (jouerSurface == nullptr) {
            cout << "Failed to create surface Error: " <<SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
        }


        SDL_Texture *jouerTexture = SDL_CreateTextureFromSurface(renderer, jouerSurface);
        if (jouerTexture == nullptr) {
            SDL_DestroyTexture(jouerTexture);
        }

        SDL_Rect jouerTextRect = {453, 228, 60, 30};
        SDL_RenderCopy(renderer, jouerTexture, NULL, &jouerTextRect);



        SDL_RenderPresent(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit=true;
                    SDL_FreeSurface(jouerSurface);
                    SDL_DestroyTexture(jouerTexture);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;
                        if (mouseX >= jouerRect.x && mouseX <= jouerRect.x+jouerRect.w && mouseY >= jouerRect.y && mouseY <= jouerRect.y+jouerRect.h) {
                            quit = true;
                            SDL_FreeSurface(jouerSurface);
                            SDL_DestroyTexture(jouerTexture);
                            sdlMenu();
                        }
                    }
                    break;

            }
        }
        }
}
void sdlJeu::sdlMenu() {
    bool quit = false;



    font = TTF_OpenFont("./data/stocky.ttf", 28);
    if (font == nullptr) {
        cout << "Failed to load .ttf! TTF_Font Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    while (!quit) {
        // Affichage du menu
        SDL_SetRenderDrawColor(renderer, 180, 200, 255, 255);
        SDL_RenderClear(renderer);
        in_menu.draw(renderer, 0,0, 1000, 300);

        // Affichage du bouton "Jouer"
        SDL_Rect jouerRect = {435,100, 100, 50};
        SDL_Rect jouerTuto = {435,180,100,50};
        SDL_SetRenderDrawColor(renderer, 100, 100, 200, 255);
        SDL_RenderFillRect(renderer, &jouerRect);
        SDL_RenderFillRect(renderer, &jouerTuto);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &jouerRect);
        SDL_RenderDrawRect(renderer, &jouerTuto);

        // Affichage du texte "Jouer"
        SDL_Color fontColor={255,255,255,255};
        SDL_Surface *jouerSurface = TTF_RenderText_Solid(font, "Jouer", fontColor);
        if (jouerSurface == nullptr) {
            cout << "Failed to create surface Error: " <<SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
        SDL_Surface *tutoSurface = TTF_RenderText_Solid(font, "Tuto", fontColor);
        if (tutoSurface == nullptr) {
            cout << "Failed to create surface Error: " <<SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        SDL_Texture *jouerTexture = SDL_CreateTextureFromSurface(renderer, jouerSurface);
        if (jouerTexture == nullptr) {
            SDL_DestroyTexture(jouerTexture);
        }
        SDL_Texture *tutoTexture = SDL_CreateTextureFromSurface(renderer, tutoSurface);
        if (tutoTexture == nullptr) {
            SDL_DestroyTexture(tutoTexture);
        }
        SDL_Rect jouerTextRect = {453, 108, 60, 30};
        SDL_RenderCopy(renderer, jouerTexture, NULL, &jouerTextRect);

        SDL_Rect tutoTextRect = {453, 188, 60, 30};
        SDL_RenderCopy(renderer, tutoTexture, NULL, &tutoTextRect);


        SDL_RenderPresent(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit=true;
                    SDL_FreeSurface(jouerSurface);
                    SDL_DestroyTexture(jouerTexture);
                    SDL_FreeSurface(tutoSurface);
                    SDL_DestroyTexture(tutoTexture);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;
                        if (mouseX >= jouerRect.x && mouseX <= jouerRect.x+jouerRect.w && mouseY >= jouerRect.y && mouseY <= jouerRect.y+jouerRect.h) {
                            quit = true;
                            SDL_FreeSurface(jouerSurface);
                            SDL_DestroyTexture(jouerTexture);
                            boucleSDL();
                        }else if (mouseX >= jouerTuto.x && mouseX <= jouerTuto.x+jouerTuto.w && mouseY >= jouerTuto.y && mouseY <= jouerTuto.y+jouerTuto.h) {
                            quit = true;
                            SDL_FreeSurface(tutoSurface);
                            SDL_DestroyTexture(tutoTexture);
                            sdlTuto();
                    }
                    break;

            }
        }
        }
}}


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
                    bool corailEstDetruit=false;
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
                            }else
                    Mix_PlayChannel(2,soundPosRequin,-1);

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


                Mix_PlayChannel(-1,soundBackground,-1);

            }
            else if (events.type == SDL_QUIT) quit = true;
                else if (events.type == SDL_KEYDOWN) {
                    bool briqueExplosee = false;
                    switch (events.key.keysym.sym) {
                         case SDLK_ESCAPE:
                            quit = true;
                            break;
                        default: break;
                    }
        }

        sdlAffichage();
        SDL_RenderPresent(renderer);
    }}}
