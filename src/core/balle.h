#ifndef BALLE_H
#define BALLE_H
#include "terrain.h"
#include "ennemi.h"
#include "../var/variables.h"
#include "heros.h"

class Balle
{
    /*private :

            int x;
            int y;

    public :

        Balle();

        int getX() const;
        int getY() const;
        void setX(int a);
        void setY(int b);

        void gauche (const Terrain & t);
        void droite (const Terrain & t);
        void haut (const Terrain & t);
        void bas (const Terrain & t);

        bool toucheEnnemi(Ennemi * ennemi);*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

public:
        int movementSpeed = vitessePlayer * 1.8;
        int attackDamage = playerDamage;
        int direction = 0; // On va prendre 1 pour gauche, 2 pour haut, 3 pour droite et 4 pour bas
        bool destroyOnEnnemi = false;
        bool destroyOnWall = false;
        int counterLifeTime = 0;
        int lifeTime = 30;

        Balle();
        void updateMovement();
        void update();

        sf::RectangleShape bullet;
        sf::Sprite bulletSprite;
        sf::Texture bulletTexture;
        sf::Vector2f taille;

        sf::SoundBuffer shot_soundBuffer;
        sf::Sound shotSound;

        Heros personnage;


};

#endif
