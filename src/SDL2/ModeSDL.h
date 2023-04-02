#ifndef _MODESDL_H
#define _MODESDL_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#endif

#ifdef linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#include "Jeu.h"

class Joueur{
private:
    SDL_Surface * surface;
    SDL_Texture * texture;
    bool changement;

public:
    Joueur();
    void afficherMenu(SDL_Renderer * renderer);
    void chargerFichier(const char * filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface(SDL_Renderer * renderer);
    void draw(SDL_Renderer * renderer,int x, int y, int w=-1,int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surfaceT);
};

class sdlJeu{
private:
    Jeu jeu;
    SDL_Window * window;
    SDL_Renderer * renderer;
    TTF_Font * font;
    Joueur font_perso;

    SDL_Color font_color;

    Joueur in_neptune;
    Joueur in_poseidon;
    Joueur in_r1;
    Joueur in_r2;
    Joueur in_barriere;
    Joueur in_mur;
    Joueur in_ocean;
    Joueur in_perdu;

    bool souris;
    bool touche;
public:
    sdlJeu();
    ~sdlJeu();
    void boucleSDL();
    void sdlAffichage();


};
#endif // _MODESDL_H
