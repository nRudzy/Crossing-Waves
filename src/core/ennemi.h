#ifndef ENNEMI_H
#define ENNEMI_H

#include "terrain.h"
#include "heros.h"
#include "../var/variables.h"

class Ennemi
{
    /*private :

        int x;
        int y;
        int direction;

    public :

        Ennemi();

        void gauche (const Terrain & t);
        void droite (const Terrain & t);
        void haut (const Terrain & t);
        void bas (const Terrain & t);

        int getX() const;
        int getY() const;

        void goVersHeros(const Terrain & t, const Heros & h);
        //void mouvementAutomatique(const Terrain & t);

    public :

        bool vivant;*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    public :
/**
    @brief Constructeur par défaut de la classe Ennemi
*/
        Ennemi();

    public :
/**
    @brief Paramètres privés de la classe Ennemi qui permettre de le définir ainsi que ses mouvements
*/
    sf::RectangleShape ennemiBody;
    sf::Sprite ennemiSprite;
    sf::Texture ennemiTexture;
    sf::Vector2f taille;
    sf::Font font;
    sf::Text ennemiText;

    sf::SoundBuffer ennemi_hitBuffer;
    sf::Sound ennemiHit;

    int counterEnnemi = 0;
    int counter = 0;
    int direction; // On va prendre 1 pour gauche, 2 pour haut, 3 pour droite et 4 pour bas
    int porteeDeDeplacement = 200;
    bool vivant = true;

    int ennemiHP = 3;

    void updateMovement();
    void update();

    void goUp();
    void goDown();
    void goLeft();
    void goRight();

    bool canMoveUp = true;
    bool canMoveDown = true;
    bool canMoveLeft = true;
    bool canMoveRight = true;



};
#endif
