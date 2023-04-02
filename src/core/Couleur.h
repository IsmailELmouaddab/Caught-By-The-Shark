#ifndef COULEUR_H
#define COULEUR_H

class Couleur{
private:
    unsigned char r,v,b;
public:
    Couleur();
    Couleur(unsigned char nr,unsigned char nv,unsigned char nb);
    unsigned char getRouge()const;
    unsigned char getVert()const;
    unsigned char getBleu()const;
    void setRouge(unsigned char nr);
    void setVert(unsigned char nv);
    void setBleu(unsigned char nb);

};
#endif // COULEUR_H
